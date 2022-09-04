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

int main() {
    FcPattern * fcp = FcPatternCreate();

    string line;
    getline(cin, line);

    line += ',';
    size_t l = 0, r = line.find(",", 0);
    while (r != string::npos) {
        FcChar8 * queryName = toFcChar8(line.substr(l, r - l).c_str());
        FcPatternAddString(fcp, FC_FAMILY, queryName);
        delete[] queryName;

        l = r + 1;
        r = line.find(",", l + 1);
    }

    FcChar8 * resultName = nullptr;
    FcConfigSubstitute(nullptr, fcp, FcMatchPattern);

    cout << "========================" << endl;
    for (int i = 0; FcPatternGetString(fcp, FC_FAMILY, i, &resultName) == FcResultMatch; ++i) {
        cout << resultName << endl;
    }

    FcPatternDestroy(fcp);
    return 0;
}
