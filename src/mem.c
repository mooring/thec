#include <stdio.h>

int main()
{
    int i      = 10;
    const char *str  = "hello world";
    char arr[] = "hello world";
    char trr[] = {'h','e','l','l','0',' ','w','o','r','l','d'};
    char c;
    c = getchar();
    putchar(c);
    getchar();
    putchar('\n');
    c = getchar();
    putchar(c);
    putchar('\n');
#ifdef __OLDCONIO__
    clrscr();
#endif
    printf("code addr=%p\n&i=%p\nstr=%p, &str=%p\narr=%p, &arr=%p\ntrr=%p, &trr=%p\n",
            main, &i, str, &str, arr,&arr,trr,&trr);
    getchar();
    return 0;
}
