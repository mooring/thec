#include <stdio.h>
#include <string.h>


void printCharArr(char *arr[], int asize){
    int i = 0;
    for(i=0; i<asize; i++){
        printf("%2d. strlen=%lu, value: %s\n", i+1, strlen(arr[i]), arr[i]);
    }
}

int main(){
    char* abc[] = {
        "ABCD",
        "abcdef",
        "XY"
    };
    printCharArr(abc, sizeof(abc)/sizeof(char*));
    return 0;
}
