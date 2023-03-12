#include <stdio.h>
#pragma warning(push)
#pragma warning(disable: 4127)

int main(void)
{
    int max = 0, num = 0, cnt = 0;
    char c;
    while(1){
    	printf("input a number (1q quit): ");
#if defined(__STDC_HOSTED__) && (defined(_WIN32) || defined(_WIN64))
    	scanf_s("%d%c", &num, &c);
#else
    	scanf("%d%c", &num, &c);
#endif
    	rewind(stdin);
    	if(cnt > 10 || ('q' == c && 1 == num)){
    		break;
    	}
        if(cnt == 0){ max = num; }
    	if(num > max){ max = num; }
    	cnt++;
    }
    printf("input number count equals %d, max number is %d\n", cnt, max);
    return 0;
}