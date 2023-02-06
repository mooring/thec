#include <stdio.h>
#include <string.h>

void stripAlpha(char str[], char f){
    int i, j, l;
    l = strlen(str);

    for(i=0;i<l;i++){
        if(str[i] == f){
            for(j=i+1;j<l;j++){
                str[j-1] = str[j];
            }
        }
    }
}

int main()
{
    char s_str[] = "This is a C Program";
    char c_find;
    
    printf("input a charactor to be strip:");
    scanf("%c", &c_find);
    printf("origin: %s\n", s_str);
    stripAlpha(s_str, c_find);
    printf("stripd: %s\n", s_str);
    
    return 0;
}