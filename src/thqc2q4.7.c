#include <stdio.h>


void thqc2q44(void)
{
    int i = 0;
    printf("input a number:\n");
#if defined(__STDC_HOSTED__) && (defined(_WIN32) || defined(_WIN64))
    scanf_s("%d", &i);
#else
    scanf("%d", &i);
#endif
    if( i%3==0 && i%5==0 ){
        printf("%d can be dived by 3 and 5\n", i);
    }else{
        printf("%d can't be dived by 3 or 5\n", i);
    }
}
int main(void)
{
    int m = 0, n = 0, i = 0, min = m;
    printf("input 2 numbers: a b\n");
#if defined(__STDC_HOSTED__) && (defined(_WIN32) || defined(_WIN64))
    scanf_s("%d%d", &m, &n);
#else
    scanf("%d%d", &m, &n);
#endif
    min = m > n ? n: m;
    for(i=min; i>0; i--){
        if(m%i==0 && n%i==0){
            break;
        }
    }
    printf("max divider is %d\n", i);
    thqc2q44();
    return 0;
}