#include <stdio.h>

int main(void)
{
    int a = 0, b = 0, c = 0;
    int max = 0;
    printf("input 3 number:\n");
#if defined(__STDC_HOSTED__) && (defined(_WIN32) || defined(_WIN64))
    scanf_s("%d%d%d", &a, &b, &c);
#else
    scanf("%d%d%d", &a, &b, &c);
#endif
    max = a;
    if(b > max){
        max = b;
    }
    if(c > max){
        max = c;
    }
    printf("your input is: %d %d %d\nmax number is: %d\n",
            a, b, c, max);
    return 0;
}

