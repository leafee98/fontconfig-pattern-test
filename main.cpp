#include <iostream>
#include <fontconfig/fontconfig.h>
#include <new>
#include <cstdlib>
#include <cstring>
#include <string>
using namespace std;

FcChar8 * toFcChar8(const char * sc) {
    FcChar8 * result = new FcChar8[strlen(sc)];
    for (size_t i = 0, l = strlen(sc); i < l; ++i) {
        result[i] = (unsigned char)(sc[i]);
    }

    return result;
}

void print_help(const string & program_name) {
    cout << "Usage: " << program_name << "\"Font Pattern\"" << endl;
    cout << "Note: better to quote all your pattern," << endl;
    cout << "  since bash will split them into multi word if not" << endl;
}

int main(int argc, char ** argv) {
    FcPattern * fcp = FcPatternCreate();

    if (argc != 2) {
        cout << "Wrong usage!" << endl;
        print_help(argv[0]);

        exit(-1);
    }

    string patterns = argv[1];

    patterns += ',';
    size_t l = 0, r = patterns.find(",", 0);
    while (r != string::npos) {
        FcChar8 * queryName = toFcChar8(patterns.substr(l, r - l).c_str());
        FcPatternAddString(fcp, FC_FAMILY, queryName);
        delete[] queryName;

        l = r + 1;
        r = patterns.find(",", l + 1);
    }

    FcChar8 * resultName = nullptr;
    FcConfigSubstitute(nullptr, fcp, FcMatchPattern);

    for (int i = 0; FcPatternGetString(fcp, FC_FAMILY, i, &resultName) == FcResultMatch; ++i) {
        cout << resultName << endl;
    }

    FcPatternDestroy(fcp);
    return 0;
}
