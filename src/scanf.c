#include <stdio.h>

void test_scanf(void)
{
    struct {
        char name[20];
        int  age;
    } p1, *p2;
    p2 = &p1;
    printf("input person's name and age:\n");
    rewind(stdin);
#if defined(__STDC_HOSTED__) && ( defined(_WIN32) || defined(_WIN64))
    scanf_s("%s%d", p1.name, 20, &p1.age);
#else
    scanf("%s%d", p1.name, &p1.age);
#endif
    printf("p->name = %s, p->age = %d\n", p2->name, p2->age);
    rewind(stdin);
}
int test_scanf_asteris(void)
{
    int a = 0, b = 0;
    printf("input 2 number: aaxxbb:\n");
    rewind(stdin);
#if defined(__STDC_HOSTED__) && (defined(_WIN32)||defined(_WIN64))
    scanf_s("%d%*2c%d", &a, &b);
#else
    scanf("%2d%*2c%2d", &a, &b);
#endif
    printf("your input number is: %1d %1d\n", a, b);
    return 0;
}
int main(int argc, char *argv[])
{
    int a = 0, b = 0;
    test_scanf();
    test_scanf_asteris();
    printf("input two number a b:\n");
    rewind(stdin);
#if defined(__STDC_HOSTED__) && ( defined(_WIN32) || defined(_WIN64))
    scanf_s("%d%d", &a, &b);
#else
    scanf("%d%d", &a, &b);
#endif
    printf("sum of(%d, %d) = %d\n", a, b, a + b);
    return 0;
}
