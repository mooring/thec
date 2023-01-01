#include <stdio.h>

int main()
{
    char  char_arr[10];
    char  char_ptr[] = "abcdefghi";
    short short_arr[10];
    int   int_arr[10] = {1,2,3,4,5};
    long  long_arr[10];
    long  long longlong_arr[10];
    float float_arr[10];
    double double_arr[10];
    printf("sizeof(char_ptr)=%d, elem=%d\n", 
            sizeof(char_ptr), 
            sizeof(char_ptr)/sizeof(char_ptr[0])
    );
    printf("sizeof(void *)=%d\nchar=%d\nshort=%d\nint=%d\nlong=%d\nlong long=%d\nfloat=%d\ndouble=%d\n",
            sizeof(void *),
            sizeof(char_arr),
            sizeof(short_arr),
            sizeof(int_arr),
            sizeof(long_arr),
            sizeof(longlong_arr),
            sizeof(float_arr),
            sizeof(double_arr)
    );
    getchar();
    return 0;
}
