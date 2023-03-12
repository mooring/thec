#include <stdio.h>

void selectSort(int arr[], int cnt){
    int i, j, t;
    for(i=0;i<cnt-1;i++){
        t = i;
        for(j=i+1;j<cnt;j++){
            if(arr[j] < arr[t]){
                t = j;
            }
        }
        j = arr[i];
        arr[i] = arr[t];
        arr[t] = j;
    }
}

void printArr(int arr[], int cnt){
    int i;
    for(i=0; i<cnt; i++){
        printf("%-4d  ", arr[i]);
        if(i%5==0&&i>0){
            putchar('\n');
        }
    }
    putchar('\n');
}

int main(){
    int arr[] = {3, 6, 1, 9, 4};
    printArr(arr, 5);
    selectSort(arr, 5);
    printArr(arr, 5);
    return 0;
}