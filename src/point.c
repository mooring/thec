#include <stdio.h>

int main(int argc, char* argv[])
{
    int i, j, k;
    int arr[] = {1, 2, 3, 5, 7};
    int brr[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
    int crr[3][2][3] = {
        {{1,2,3},{4,5,6}},
        {{7,8,9},{9,8,7}},
        {{1,3,5},{5,3,1}}
    };
    int* ptr = arr;
    int (*btr)[3][3] = &brr;
    int (*ctr)[3][2][3] = &crr;
    for(ptr=&arr[0]; ptr<=&arr[4]; ptr++){
        printf("%d ", *ptr);
    }
    putchar('\n');
    for(i=0; i<3; i++){
        for(j=0; j<3; j++){
            printf("%d,", *(*(*btr+i)+j));
        }
        putchar('\n');
    }
    putchar('\n');
    for(i=0; i<3; i++){
        for(j=0; j<3; j++){
            printf("%d,", (*btr)[i][j]);
        }
        putchar('\n');
    }
    putchar('\n');
    for(i=0; i<3; i++){
        printf("%d. {", i);
        for(j=0; j<2; j++){
            printf("{");
            for(k=0; k<3; k++){
                printf("%d,", *(*(*(*ctr+i)+j)+k));
            }
            printf("\b},");
        }
        printf("\b}\n");
    }
    putchar('\n');
    for(i=0; i<3; i++){
        printf("%d. {", i);
        for(j=0; j<2; j++){
            printf("{");
            for(k=0; k<3; k++){
                printf("%d,", (*ctr)[i][j][k]);
            }
            printf("\b},");
        }
        printf("\b}\n");
    }
    return 0;
}
