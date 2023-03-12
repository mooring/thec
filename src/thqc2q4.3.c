#include <stdio.h>

void swap(int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
int main(void)
{
    int a = 0, b = 0, c = 0;
    printf("input 3 number: a b c\n");
#if defined(__STDC_HOSTED__) && ( defined(_WIN32) || defined(_WIN64) )
    scanf_s("%d%d%d", &a, &b, &c);
#else
    scanf("%d%d%d", &a, &b, &c);
#endif
    if(a>b){
        swap(&a, &b);
    }
    if(b>c){
        swap(&b, &c);
    }
    if(a>b){
        swap(&a, &b);
    }
    printf("%d %d %d\n", a, b, c);
    return 0;
}