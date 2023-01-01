#include <stdio.h>

static int j;

void func1(void)
{
    static int i = 0;
    i++;
}

void func2(void)
{
    j = 0;
    j++;
}

int main()
{
    int k = 0;
    for(k=0; k<10; k++){
    	func1();
    	func2();
    }
    return 0;
}
