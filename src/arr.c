#include <stdio.h>

int main()
{
    char       arr[] = "hello arr[]";
    const char crr[] = {'h','e','l','l',' ','c','r','r','[',']'};
    int        irr[] = {1,2,3,4};
    const int  icr[] = {1,2,3,4};
    const char  *str = "hello *ptr";

    printf("char       arr[] = \"hello arr[]\";\n");
    printf("const char crr[] = {'h','e','l','l',' ','c','r','r','[',']'};\n");
    printf("int        irr[] = {1,2,3,4};\n");
    printf("const int  icr[] = {1,2,3,4};\n");
    printf("const char  *str = \"hello *ptr\";\n\n");
    printf("arr=%p, &arr[0]=%p, &arr=%p\n", arr, &arr[0], &arr);
    printf("crr=%p, &crr[0]=%p, &crr=%p\n", crr, &crr[0], &crr);
    printf("irr=%p, &irr[0]=%p, &irr=%p\n", irr, &irr[0], &irr);
    printf("icr=%p, &icr[0]=%p, &icr=%p\n", icr, &icr[0], &icr);
    printf("str=%p, &str[0]=%p, &str=%p\n", str, &str[0], &str);

    printf("\n");

}
