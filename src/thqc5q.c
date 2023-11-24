#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>

void pi(void)
{
    int    c  = 1;
    double pi = 0.0;
    double tm = 1.0;
    double n  = 1.0;
    puts("1e-8 pi number:");
    while(fabs(tm) > 1e-8){
        pi += tm;
        n  += 2;
        c = -c;
        tm = c / n;
    }
    printf("pi = %.6lf n = %.0lf\n", 4*pi, n);
}

void fibonacci(const int n)
{
    int sum = 0, a = 1, b = 1, i = 0;
    puts("fibonacci numbers:");
    if( n > 0){
        sum = 0;
        for(i=1; i<=n; i++){
            printf("%4d %5d\n", i, a);
            sum += a;
            b = a + b;
            a = b - a;
        }
        printf("%4d  => %-5d\n", n , sum);
    }else{
        printf("invalid input %d\n", n);
    }
}

int prime(const int n)
{
    int i = 0, q = 0;
    if( n > 3){
        q = (int) sqrt(n);
        for(i=2; i<=q; i++){
            if(n%i==0){
                break;
            }
        }
    }
    return q > 0 && i > q;
}

void batchPrime(void)
{
    int i = 100, j = 0;
    puts("prime numbers from 100 to 200:");
    for(; i<=200; i++){
        if(prime(i)){
            printf("%4d", i);
            ++j;
            if(j%5==0){
                putchar('\n');
            }
        }
    }
    putchar('\n');
}

void transcode(void)
{
    char str[100] = {0}, *c = str;
    puts("input your string to encrypt:");
    fgets(str, 100, stdin);
    puts("encrypted text:");
    while(*c != '\0'){
        if((*c >= 'a' && *c<='z') || (*c >= 'A' && *c <= 'Z') ){
            putchar(*c>='a'&& *c<'w'||*c>='A'&&*c<'W' ? *c+4 : *c-22);
        }else{
            putchar(*c);
        }
        c++;
    }
}
void question3(void)
{
    int a = 0, b = 0, t = 0, i = 0;
    puts("input two number to find greatest common divisor and least common multiple:");
#if defined(__STDC_HOSTED__) && (defined(_WIN32)||defined(_WIN64))
    scanf_s("%d%d", &a, &b);
#else
    scanf("%d%d", &a, &b);
#endif
    if(a>0 && b>0){
        t = a > b ? b : a;
        for(i=t; i>1; i--){
            if(a%i==0&&b%i==0){
                break;
            }
        }
        if(i>0){
            printf("%d and %d greatest common divisor is %d\n", a, b, i);
        }
        t = a > b ? a : b;
        for(i=t;;i++){
            if(i%a==0&&i%b==0){
                break;
            }
        }
        if(i>t || a%b==0 || b%a==0){
            printf("%d and %d least common multiple is %d\n", a, b, i);
        }            
    }else{
        puts("number must be positive");
    }
}
void question4(void)
{
    char str[200] = {0};
    char *p       = str;
    int  cnt[4]   = {0};
    puts("input one line to counter:");
    rewind(stdin);
    fgets(str, 100, stdin);
    while(*p != '\0'){
        if(*p >= 'a' && *p <= 'z' || *p >= 'A' && *p <= 'Z'){
            cnt[0] ++;
        }else if(*p >= '0' && *p <= '9'){
            cnt[1]++;
        }else if(*p == ' '){
            cnt[2]++;
        }else{
            cnt[3]++;
        }
        p++;
    }
    printf("letters %d, numbers %d, white spaces %d, others %d\n",
            cnt[0], cnt[1], cnt[2], cnt[3]);
}
void question5(void)
{
    int sum = 0, num = 0, cnt = 0, tmp = 0, i = 0;
    puts("input one digit and max repeated time:");
#if defined(__STDC_HOSTED__) && (defined(_WIN32)||defined(_WIN64))
    scanf_s("%d%d", &num, &cnt);
#else
    scanf("%d%d", &num, &cnt);
#endif
    for(i=0; i<cnt; i++){
        tmp += (num%10) * (int)pow(10, i);
        sum += tmp;
        printf("%d ", tmp);
        if(i < cnt - 1){
            printf("%s", " + ");
        }
    }
    printf("= %d\n", sum);
}
void question6(const unsigned long n)
{
    unsigned long sum = 0, i = 0, tmp = 1;
    for(i=1;i<=n;i++){
        if(i>1){
            tmp *= i;
        }
        printf("%2lu! = %lu\n", i, tmp);
        if(i%10==0){ putchar('\n'); }
        sum += tmp;
    }
    printf("sum = %lu\n", sum);
}
void question7(const unsigned long k)
{
    double sum = 0.0;
    unsigned long i = 1;
    for( i = 1; i <= k; i++){
        sum += i;
    }
    for( i = 1; i <= k/2; i++){
        sum += i * i;
    }
    for( i = 1; i <= k/10; i++){
        sum += 1.0 / i ;
    }
    printf("%.2lf\n" , sum);
}
void question8(void)
{
    int i = 0, t = 0, h = 0, s = 0;
    const int m = 1000;
    
    for(i=1; i<m; i++){
        t = i/100;
        h = i%100/10;
        s = i%  10;
        if(t*t*t + h*h*h + s*s*s == i){
            printf("%d is flower number\n", i);
        }
    }
}
void question9()
{
    #define MAX   10000
    #define COUNT 100
    int i = 0, j = 0, idx = 0, sum = 0, num[COUNT] = {0};
    for(i=1; i<=MAX; i++){
        memset(num, 0, COUNT*sizeof(int));
        idx = 0;
        sum = 0;
        for(j=1; j<i; j++){
            if(i%j==0){
                num[idx] = j;
                sum += j;
                idx++;
            }
        }
        
        if(sum == i){
            printf("%6d %6d its factors are ", i, idx);
            j = 0;
            while(j < idx){
                printf("%d%s", num[j], j<idx-1?",":"");
                j++;
            }
            putchar('\n');
        }
    }
}
void question10(const int n)
{
    double sum = 0.0;
    int a = 1, b = 1, i = 0;
    puts("fibonacci numbers:");
    printf("idx      f1     f2     f2/f1\n");
    if( n > 0){
        sum = 0;
        for(i=1; i<= n+1; i++){
            printf("%4d %6d %6d %8.2lf\n", i, a, b, (double)b/(double)a);
            sum += (double)b/(double)a;
            b = a + b;
            a = b - a;
        }
        printf("index =  %-4d  sum = %6.2lf\n", n , sum-1.0);
    }else{
        printf("invalid input %d\n", n+1);
    }
}

void question11(void){
    double sum = 0.0, init = 100.0, tmp = 0.0;
    int  i;
    clock_t   n = clock();
    for(i=0;i<11;i++){
        tmp = init * pow(0.5, i);
        sum += 2 * tmp;
    }
    sum = sum - init;
    n = clock() - n;
    printf("cost %.2fs to calculate question11\n", CLOCKS_PER_SEC);
    printf("10 times height: %.6lf, round length: %.6lf\n", tmp, sum);
}
void question12(void)
{
    int tmp = 1, i = 0;
    while(i<9){
        tmp = (tmp+1)*2;
        i++;
    }
    printf("total peach %d\n", tmp);
}
void question13(void)
{
    float a, x0, x1;
    clock_t n;
    printf("input a positive number:\n");
    rewind(stdin);
#if defined(__STDC_HOSTED__) && (defined(_WIN32)||defined(_WIN64))
    scanf_s("%f", &a);
#else
    scanf("%f", &a);
#endif
    x0 = a / 2;
    x1 = (x0 + a/x0)/2;
    n = clock();
    do{
        x0 = x1;
        x1 = (x0 + a/x0)/2;
    }while(fabs(x0-x1)>=1e-5);
     n = clock() - n;
    printf("cost %.2fs to calculate question13\n", n/CLOCKS_PER_SEC);
    printf("sqrt(%.6f) = %.6f\n", a, x1);
}
void question14(void)
{
    
}
int main(void)
{
    int check = 36;
    
    pi();
    fibonacci(check);
    printf("%d %s prime number\n", check, prime(check)?"is":"is not");
    batchPrime();
    transcode();
    question3();
    question4();
    question5();
    question6(10);
    question7(100);
    getchar();
    question9();
    question10(20);
    question8();
    question11();
    question13();
    return 0;
}

