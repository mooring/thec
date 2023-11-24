#include <stdio.h>

int main0(void)
{
    printf("**********************\n");
    printf("     Hello World!\n");
    printf("**********************\n");
    return 0;
}

void print_star0(void)
{
    printf("\n ******\n");
    printf("   ******\n");
    printf("     ******\n");
    printf("       ******\n");
}
void print_star1(void)
{
    int i = 0;
    char *str = "      ******";
    for(;i<5;i++){
        printf(" %s\n", str + (6 - 2*i));
    }
}
int main1(void)
{
    print_star0();
    printf("------------------------\n");
    print_star1();
    return 0;
}

int main2(void)
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
    printf(
        "your input is: %d %d %d\n"
        "max number is: %d\n",
        a, b, c, max
    );
    return 0;
}

void main(void)
{
    main0();
    main1();
    main2();
}
