#include <stdio.h>

int main()
{
    short _a = 1 - .1e-1;
    int   _b = 10110L;
    char* _d = "\129";
    char   x = 65;
    float  y = 7.3;
    int    a = 100;
    double b = 4.5;
    printf("%d %d %s\n", _a, _b, _d);
    printf("%d %d %d %d\n",
            sizeof(x), sizeof(y), sizeof(a), sizeof(b));
    return 0;
}
