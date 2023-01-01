#include <stdio.h>

void swap(int* x, int* y){
    int* tmp;
    printf("x=%p, &x=%p, *x=%d\n", x, &x, *x);
    printf("y=%p, &y=%p, *y=%d\n", y, &y, *y);
    *tmp = *x;
    *x = *y;
    *y = *tmp;
}
void vswap(void* x, void* y){
    void* tmp;
    tmp = x;
    x = y;
    y = tmp;
}
int main()
{
    int a = 1, b = 2;
    int c = 3, d = 4;
    printf("a=%d, &a=%p\n", a, &a);
    printf("b=%d, &b=%p\n", b, &b);
    printf("after swap(&a, &b)\n");
    swap(&a, &b);
    printf("a=%d, &a=%p\n", a, &a);
    printf("b=%d, &b=%p\n", b, &b);
    printf("c=%d, &c=%p\n", c, &c);
    printf("d=%d, &d=%p\n", d, &d);
    vswap(&c, &d);
    printf("c=%d, d=%d\n", c, d);
    getchar();
    return 0;
}
