#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

void strrev(char *str){
    size_t l = strlen(str);
    int i = 0;
    char c;
    while( str+i < str+l-i){
        c = *(str+l-i);
        *(str+l-i) = *str;
        *str = c;
        i++;
    }
}
void question5(void)
{
    int num = 0;
    while(num != -1){
        printf("input a number: 0<=number<=1000 (-1 to quit): ");
#if defined(__STDC_HOSTED__) && (defined(_WIN32)||defined(_WIN64))
        scanf_s("%d", &num);
#else
        scanf("%d", &num);
#endif
        if( num >= 0 && num <= 1000){
            printf("sqrt(%d) = %.2f\n", num, sqrt(num));
        }
    }
}
void question6(void)
{
    float num  = 0;
    char  code = 0;
    while(1){
        printf("please input f(x) x: (1q quit)\n");
#if defined(__STDC_HOSTED__) && (defined(_WIN32)||defined(_WIN64))
        scanf_s("%f%c", &num, &code, 1);
#else
        scanf("%f%c", &num, &code);
#endif
        if((int) num == 1 && code == 'q'){
            break;
        }
        if(num < 1){
            printf("f(x) = x      {x < 1}   = %.2f\n", num);
        }else if(num < 10){
            printf("f(x) = 2x - 1 {1<=x<10} = %.2f\n", 2*num - 1);
        }else{
            printf("f(x) = 3x - 11{x>=10}   = %.2f\n", 3*num -11);
        }
    }
}
void question8(void)
{
    float score = 0;
    char  code  = 0;
    while(1){
        printf("input score (0-100): (1q quit) ");
#if defined(__STDC_HOSTED__) && (defined(_WIN32)||defined(_WIN64))
        scanf_s("%f%c", &score, &code, 1);
#else
        scanf("%f%c", &score, &code);
#endif
        if((int)score == 1 && code == 'q'){
            break;
        }
        if(score>=90){
            printf("%d's grade is: A\n", (int)score);
        }else if(score>=80){
            printf("%d's grade is: B\n", (int)score);
        }else if(score>=70){
            printf("%d's grade is: C\n", (int)score);
        }else if(score>=60){
            printf("%d's grade is: D\n", (int)score);
        }else{
            printf("%d's grade is: E\n", (int)score);
        }
    }
}
void question9(void)
{
    int  num    = 0;
    char str[5] = {0};
    char *p     = str;
    printf("input a number less than 100000\n");
#if defined(__STDC_HOSTED__) && (defined(_WIN32)||defined(_WIN64))
    scanf_s("%d", &num);
#else
    scanf("%d", &num);
#endif
    if( num > 0 && num < 100000){
#if defined(__STDC_HOSTED__) && (defined(_WIN32)||defined(_WIN64))
        snprintf(str, 5, "%d", num);
#else
        sprintf(str, "%d", num);
#endif
    }
    printf("number count: %d\n", (int)strlen(str));
    while(*p != '\0'){
        printf("%c ", *p++);
    }
    putchar('\n');
    strrev(str);
    printf("%s\n", str);
}

void question10(void)
{
    int    num = 0;
    double sum = 0.0;
    printf("input incoming: ");
#if defined(__STDC_HOSTED__) && (defined(_WIN32)||defined(_WIN64))
    scanf_s("%d", &num);
#else
    scanf("%d", &num);
#endif
    if(num > 1000000){
        sum += (num - 1000000)*0.01;
        num = 1000000;
    }
    if(num > 600000){
        sum += (num - 600000)*0.015;
        num = 600000;
    }
    if(num > 400000){
        sum += (num - 400000)*0.03;
        num = 400000;
    }
    if(num > 200000){
        sum += (num - 200000)*0.05;
        num = 200000;
    }
    
    if(num > 100000){
        sum += (num - 100000)*0.075;
        num = 100000;
    }
    if( num <= 100000){
        sum += num * 0.1;
    }
    printf("reward is %.0lf\n", sum);
}
int main(void)
{   
    question10();
    return 0;
    question5();
    question6();
    question8();
    question9();
    return 0;
}
