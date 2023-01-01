#include <stdio.h>
#include <math.h>

int main(void)
{
    int start = 1, end = 20;
    int i = 0, j = 0, ext = 0, cnt = 0, fnd = 0;
    for(i=start; i<=end; i++){
        ext = (int)sqrt(i)+1;
        fnd = 0;
        for(j=2;j<=ext; j++){
            if(i%j == 0){
                fnd = 1;
                break;
            }
        }
        if(!fnd){
            cnt++;
            if(cnt == 1){
                printf("prime number:\n");
            }
            printf("%4d%s", i, cnt%5==0?"\n":" "); 
        }
    }
}