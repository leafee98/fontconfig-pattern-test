# fontconfig-pattern-test

This is a simple code to call fontconfig and do pattern match, like Firefox did.

In a normal fontconfig call, there should be two steps, pattern match and sort by score. But for test purpose and do simplify the code, we only do the pattern match without sort, also like what Firefox did.

So this code can help you to debug you configuration of fontconfig, and see why Firefox use another font instead of what you want.

## Compile

Make sure you have fontconfig library installed on your system.

```
g++ main.cpp -o main -lfontconfig
```

## Usage

The lines started with '>' mean it's the input, and lines without it is output. The output is too long and I cutted much many.

```
$ ./main
>sans,mono
========================
DejaVu Sans
DejaVu LGC Sans
Noto Sans
Noto Sans CJK SC
DejaVu LGC Sans
Noto Sans
DejaVu Sans
Verdana

...
```
