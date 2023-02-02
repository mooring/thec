#include <stdio.h>

void printCharArr(char *arr[], int asize){
    int i = 0;
    for(i=0; i<asize; i++){
        printf("%2d %s\n", i+1, arr[i]);
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
