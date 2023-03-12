#include <stdio.h>

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
int main(void)
{
    print_star0();
    printf("------------------------\n");
    print_star1();
    return 0;
}
