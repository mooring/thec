#include <stdio.h>

void bubbleSort(void)
{
    int num[] = {32,12,8, 45, 7,18, 21,47,19, 60};
    int i, j,tmp, cnt = sizeof(num)/sizeof(int);
    for(i=0;i<cnt;i++){
        for (j = 0; j < cnt-1 ; j++){
            if (*(num+j) > *(num+j+1)){
                tmp        = *(num+j);
                *(num+j)   = *(num + j +1);
                *(num+j+1) = tmp;
            }
        }
    }
    for(i=0;i<cnt;i++){ printf("%3d", num[i]); }
}

void selectSort(void)
{
    int num[] = {32,12,8, 45, 7,18, 21,47,19, 60};
    int i, j, tmp, cnt = sizeof(num)/sizeof(int);
    for(i=0;i<cnt;i++){
        tmp = i;
        for(j=i;j<cnt;j++){
            if(*(num+j) < *(num+tmp)){
                tmp = j;
            }
        }
        if(tmp != i){
            j = *(num+i);
            *(num+i) = *(num+tmp);
            *(num+tmp) = j;
        }
    }
    for(i=0;i<cnt;i++){ printf("%3d", num[i]); }
}
int main(void){
    bubbleSort();
    putchar('\n');
    selectSort();
    putchar('\n');
    return 0;
}
