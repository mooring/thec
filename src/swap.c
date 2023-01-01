#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
void strupr(char *str) {
    while(*str!='\0'){
        *str=toupper(*str);
        str++;
    }
}
void swap( void *x, void *y, int size)
{
    char *px = (char *)x;
    char *py = (char *)y;
    char tmp;
    int  i;
    for(i=0; i<size; i++){
        tmp = px[i];
        px[i] = py[i];
        py[i] = tmp;
    }
}
void swap1(void *x, void *y, int size){
    char *tmp = (char *)malloc(size);
    memcpy(tmp, x, size);
    memcpy(x, y, size);
    memcpy(y, tmp, size);
}
int main(){
    int a = 10, b = 20;
    char aa[] = "abcd";
    char bb[] = "efgh";
    swap(&a, &b, sizeof(int));
    swap1(&a, &b, sizeof(int));
    swap1(&aa, &bb, sizeof(aa));
    swap(&aa, &bb, sizeof(aa));
    strupr(aa);strupr(bb);
    printf("a=%d, b=%d\n", a, b);
    printf("aa=%s, bb=%s\n", aa, bb);
    getchar();
    return 0;
}
