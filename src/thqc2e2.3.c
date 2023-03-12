#include <stdio.h>
#

int main(void)
{
    const int start = 2000, end = 2100;
    int i = start;
    for(; i <= end; i++){
    	if((i%4==0&&i%100!=0) || i%400==0){
    		printf("%d is leap year\n", i);
    		printf("%d is not a leap year\n", ++i);
    		printf("%d is not a leap year\n", ++i);
    		printf("%d is not a leap year\n", ++i);
    	}else{
    		printf("%d is not a leap year\n", i);
    	}
    }
}
