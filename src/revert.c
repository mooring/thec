#include <stdio.h>
#include <string.h>

void main2(const int num);
void main1(const int num);

int main(void)
{
    int  num     = 0;
    printf("input a number: ");
#if defined(__STDC_HOSTED__) && (defined(_WIN32)||defined(_WIN64))
    scanf_s("%d", &num);
#else
    scanf("%d", &num);
#endif
    main1(num);
    main2(num);
}   

void main1(const int num)
{
    char str[20] = {0};
#if defined(__STDC_HOSTED__) && (defined(_WIN32)||defined(_WIN64))
    sprintf_s(str, 20, "%d", num);
    snprintf(str, 20, "%d", num);
#else
    sprintf(str, "%d", num);
#endif
    
    printf("sprintf your input number is: %s\n", str);
}  
  
void main2(const int num)
{
    int  left    = num, mod = 0, idx = 0;
    char str[20] = {0};
    char *p      = NULL;
    char c       = '\0';
    
    if(num < 0){
        str[idx++] = '-';
        left *= -1;
    }
    do{
        mod        = left % 10;
        str[idx++] = '0'  + mod;
        if(left < 10){
            break;
        }
        left /= 10;
    }while(left);
    p   = str + idx - 1;
    idx = num < 0 ? 1 : 0;
    while(str + idx < p){
        c        = *p;
        *p--     = str[idx];
        str[idx] = c;
        idx++;
    }
    printf("your input number is: %s\n", str);
}