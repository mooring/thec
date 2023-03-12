#include <stdio.h>
#include <math.h>

void question2(void)
{
    double initial = 1000.0, temp = 0.0;
    int    i = 0;
    double increment[] = {0.0035, 0.015, 0.021, 0.0275, 0, 0.03};
    printf("5 years 1 time    : %5.2lf\n", initial * (1 + 5 * increment[5]));
    
    temp = initial * ( 1 + 2 * increment[2]);
    printf("5 years 2 + 3 time: %5.2lf\n", temp * (1 + 3 * increment[3]));
    temp = initial * ( 1 + 3 * increment[3]);
    printf("5 years 3 + 2 time: %5.2lf\n", temp * (1 + 2 * increment[2]));
    printf("5 years 1+1+1+1+1 : %5.2lf\n", initial * pow(1+increment[1], 5));
    printf("5 years 4*5 time  : %5.2lf\n", initial * pow(1+increment[0]/4, 4*5));
}

void question3(void)
{
    double d = 300000.0;
    double p = 6000.0;
    double r = 0.01;
    double month = log10(p/(p - d*r))/log10(1 + r);
    printf("pay end months: %.2lf\n", month);
}
int main(void)
{
    question2();
    question3();
    return 0;
}