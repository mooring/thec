#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define Q4_COL 4
#define Q4_ROW 4

void pline(){
    puts("---------------------\r");
}

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
    printf("thq chapter 7 question 1\n");
    printf("输入两个整数数求最大公约数、最小公倍数: ");
    scanf("%d%d", &x, &y);
    q1_func1(x, y);
    q1_func2(x, y);
}

void q2(){
    int a, b, c, bs, ac;
    double x[2] = {0.0};
    printf("thq chapter 7 question 2\n");

    printf("输入方程ax^2 + bx + c = 0 整型参数 a, b, c: \n");
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

/*
 * @description: check input number is a prime number
 * @param/n    : int
 * @return     : int (1 true/0 false)
 */ 
int q3_func1(int n){
    int i, j, k = 0;
    if(n<=3){
        return n>1;
    }
    if(n%6 != 1 && n%6 != 5){
        return 0;
    }
    // number 25 35 will be here
    j = (int)sqrt(n);
    for(i=5;i<=j;i+=6){
        printf(
            "%-3d sqrt(%d) = %d, %d%%6 = %d, %d%%%d = %d, %d%%%d = %d\n", 
            k++, n, j, n, n%6, n, i, n%i, n, i+2, n % (i+2)
        );
        if(n%i == 0 || n % (i+2) == 0){
            return 0;
        }
    }
    return 1;
}

void q3(){
    int n, s = 0;
    printf("thq chapter 7 question 3\n");
    // 质数（Prime number），又称素数，
    // 指在大于1的自然数中，除了1和该数自身外，无法被其他自然数整除的数
    // 也可定义为只有1与该数本身两个正因数的数。
    // 大于1的自然数若不是素数，则称之为合数（也称为合成数）。例如，5是个素数，因为其正约数只有1与5
    printf("input a integer to check if it's a prime number: ");
    scanf("%d", &n);
    s = q3_func1(n);
    printf("%d is%sa prime number\n", n, s==0 ? " not " : " ");
}



/*
 * @description: transform matrics
 * @requirement: output memory must be allocated before pass
 * @param/row  : src matric row
 * @param/col  : src matric col
 */
void q4_func2(char **input, char **output, int row, int col){
    int i, j;
    if(output != NULL){
        for(i=0; i<row; i++){
            for(j=0; j<col; j++){
                output[j][i] = input[i][j];
            }
        }
    }else{
        printf("output memory can't be null\n");
    }
}

/*
 * @description: print matrics with row, column
 */
void q4_func1(char **arr, int row, int col ){
    int i, j;
    printf("print matric @%p\n", arr);
    if(arr !=  NULL){
        for(i=0; i<row; i++){
            for(j=0; j<col; j++){
                printf("%-4c", arr[i][j]);
            }
            putchar('\n');
        }
    }
}

void q4(){
    char arr[Q4_ROW][Q4_COL] = {
        {'a', 'b', 'c', 'd'},
        {'x', 'y', 'z', 'p'},
        {'1', '2', '3', '4'},
        {'A', 'B', 'C', 'D'}
    };
    int i;
    char **input  = (char**)malloc(sizeof(char*) * Q4_ROW);
    char **output = (char**)malloc(sizeof(char*) * Q4_COL);
    printf("thq chapter 7 question 4\n");
    for(i=0;i<Q4_COL;i++){
        output[i] = (char*)malloc(sizeof(char) * Q4_ROW);
    }
    for(i=0;i<Q4_ROW; i++){input[i]  = arr[i];}
    q4_func1(input, Q4_ROW, Q4_COL);
    pline();
    q4_func2(input, output, Q4_ROW, Q4_COL);    
    q4_func1(output, Q4_COL, Q4_ROW);
    free(input);
    for(i=Q4_COL-1;i>0;i--){free(output[i]);}free(output);
}

int main()
{
    // q1();
    // q2();
    q3();
    q4();
    return 0;
}
