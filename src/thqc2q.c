#include <stdio.h>
#include <math.h>
#pragma warning(push)
#pragma warning(disable: 4127)


int question_2_3(void)
{
    const int start = 2000, end = 2100;
    int i = start, count = 0;
    for(; i <= end; i++){
        if((i%4==0&&i%100!=0) || i%400==0){
            printf("%d ", i);
            count++;
        }
    }
    if(count>0){
        puts("are leap years");
    }
    return 0;
}

int question_4_2(void)
{
    int max = 0, num = 0, cnt = 0;
    char c;
    while(1){
        printf("input a number (1q quit): ");
#if defined(__STDC_HOSTED__) && (defined(_WIN32) || defined(_WIN64))
        scanf_s("%d%c", &num, &c);
#else
        scanf("%d%c", &num, &c);
#endif
        rewind(stdin);
        if(cnt > 10 || ('q' == c && 1 == num)){
            break;
        }
        if(cnt == 0){ max = num; }
        if(num > max){ max = num; }
        cnt++;
    }
    printf("input number count equals %d, max number is %d\n", cnt, max);
    return 0;
}

void swap(int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void question_4_3(void)
{
    int a = 0, b = 0, c = 0;
    printf("input 3 number: a b c: ");
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
    printf("sorted number: %d %d %d\n", a, b, c);
}


void question_4_4(void)
{
    int start = 1, end = 20;
    int i = 0, j = 0, ext = 0, cnt = 0, fnd = 0;
    for(i=start; i<=end; i++){
        ext = (int)sqrt(i)+1;
        fnd = 0;
        for(j=2;j<=ext; j++){
            if(i%j == 0){
                fnd = 1;
                break;
            }
        }
        if(!fnd){
            cnt++;
            if(cnt == 1){
                printf("prime number:");
            }else{
                printf("%d ", i);
            }
        }
    }
    putchar('\n');
}

void question_4_6(void)
{
    int i = 0;
    printf("input a number: ");
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

void question_4_5(void)
{
    int m = 0, n = 0, i = 0, min = m;
    printf("input 2 numbers: a b ");
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
}

int main(int argc, char* argv[])
{
    question_2_3();
    question_4_2();
    question_4_3();
    question_4_4();
    question_4_5();
    question_4_6();
    return 0;
}
