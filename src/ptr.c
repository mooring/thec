#include <stdio.h>

int main()
{
    int i = 0, iarr[] = {1,2,3};
    char c = 'a', carr[] = {'a','b','c'};
    int *iptr = &i, *iaptr = iarr;
    char *cptr = &c, *captr = carr;
    printf("iptr=%p, iptr+1=%p\n", iptr, iptr+1);
    return 0;
}

