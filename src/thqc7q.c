#include <stdio.h>
#include <math.h>

void q1_func1(int x, int y){
    int i = 0, f = 0,
        mn = x < y ? x : y;
    for(i=2; i<=mn; i++){
        if(x%i==0 && y%i==0){
            f = 1;
            break;
        }
    }
    if(x == y){ f = 1; i = x;}
    if(f){
        printf("%d,%d 最大公约数是:%d\n", x, y, i);
    }else{
        printf("%d,%d 没有最大公约数\n", x, y);
    }
}
void q1_func2(int x, int y){
    int i,
        mn = x < y ? x : y;
    for(i=mn; ; i++){
        if(i%x==0 && i%y==0){
            break;
        }
    }
    printf("%d,%d 最小公倍数是:%d\n", x, y, i);
}

void q1(){
    int x, y;
    printf("thq charpter 7 question 1\n");
    printf("input two integer number: ");
    scanf("%d%d", &x, &y);
    q1_func1(x, y);
    q1_func2(x, y);
}

void q2(){
    int a, b, c, bs, ac;
    double x[2] = {0.0};
    printf("thq charpter 7 question 2\n");
    
    printf("ax^2 + bx + c = 0, input integer a, b, c: \n");
    scanf("%d%d%d", &a, &b, &c);
    
    bs = b * b;
    ac = 4 * a * c;
    printf("b*b-4ac=%d\n", bs - ac);
    
    if(bs - ac < 0){
        printf("ax^2+bx+c=0 has no root\nwhen a=%d b=%d c=%d\n", a, b, c);
    }else if(bs - ac == 0){
        x[0] = -b/2/(double)a;
        printf("ax^2+bx+c=0 roots x1=x2=%.2lf\nwhen a=%d b=%d c=%d\n", x[0], a, b, c);
    }else{
        x[0] = (0+sqrt((double)(bs - ac))-b)/2/a;
        x[1] = (0-sqrt((double)(bs - ac))-b)/2/a;
        printf("ax^2+bx+c=0 roots x1=%.2lf, x2=%.2lf\nwhen a=%d b=%d c=%d\n", x[0], x[1], a, b, c);
    }
}

void q3(){
    int i, n, s = 0 , f = 0;
    printf("thq charpter 7 question 3\n");
    // 质数（Prime number），又称素数，
    // 指在大于1的自然数中，除了1和该数自身外，无法被其他自然数整除的数
    // 也可定义为只有1与该数本身两个正因数的数。
    // 大于1的自然数若不是素数，则称之为合数（也称为合成数）。例如，5是个素数，因为其正约数只有1与5
    printf("input a number to test: ");
    scanf("%d", &n);
    if( n <= 1 ){
        printf("%d is not a prime number\n");
    }else{
        f = (int) sqrt(n);
        for(i=2;i<=f;i++){
            if(n%i==0){
                s = 1;
                break;
            }
        }
        printf("%d is%s a prime number\n", n, s==1 ? " not" : "");
    }
}

int main()
{
    // q1();
    // q2();
    // q3();
    return 0;
}
