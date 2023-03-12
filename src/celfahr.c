#include <stdio.h>

int main(void)
{
    double fahr, celsius;
    double lower, upper, step;
    lower = 0;
    upper = 300;
    step  = 20;
    fahr = lower;
    while(fahr <= upper){
        celsius = 5 * (fahr - 32) / 9.0;
        printf("%3.2lf    %3.2lf\n", fahr, celsius);
        fahr = fahr + step;
    }
    return 0;
}
