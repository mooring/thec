#include <stdio.h>

int main()
{
    int count = 0, sum = 0, tmp = 0;
    while(1){
        if(tmp < 0){
            break;
        }else{
            printf(
                "Input Positive number%s:\n",
                count < 1 ? "(negative to quit)" : ""
            );
            scanf("%d", &tmp);
            getchar();
            sum   += tmp < 0 ? 0 :tmp;
            count += tmp < 0 ? 0 : 1;
        }
    }
    printf("got %d numbers, sum = %d, average = %.2f\n",
            count, sum , (float)sum/(count == 0 ? 1 : count));
    return 0;
}
