# fontconfig-pattern-test

This is a simple code to call fontconfig and do pattern match, like Firefox did.

In a normal fontconfig call, there should be two steps, pattern match and sort by score. But for test purpose and do simplify the code, we only do the pattern match without sort, also like what Firefox did.

So this code can help you to debug your configuration of fontconfig, and see why Firefox use another font instead of what you want.

## Compile

Make sure you have fontconfig library installed on your system.

```
g++ main.cpp -o main -lfontconfig
```

## Usage

The program now use argument as font pattern.

**Note** that no extra space should be present before or after the comma, and not quotation mark needed for patterns those contain spaces.

```
$ ./main "Noto Sans,sans-serif" | head -n 5
Noto Sans
DejaVu LGC Sans
Noto Sans
DejaVu Sans
Verdana
```
