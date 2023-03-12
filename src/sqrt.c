#include <stdio.h>
#include <math.h>

int main(void)
{
    int num = 0;
    while(1){
        printf("input a number less than 1000 (-1 to quit):\n");
#if defined(__STDC_HOSTED__) && (defined(_WIN32)||defined(_WIN64))
        scanf_s("%d", &num);
#else
        scanf("%d", &num);
#endif
        if(num == -1){
            break;
        }
        if( num > 0 && num <= 1000){
            printf("sqrt(%d) = %d\n", num, (int)sqrt(num));
        }
    }
    return 0;
}