#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

void printArr(const int arr[], const int cnt)
{
    int i;
    for (i = 0; i < cnt; i++) {
        printf("%4d", arr[i]);
    }
}

int fexists(const char* fname) {
    int   ret = 0;
    FILE* fp = NULL;
#if defined(__STDC_HOSTED__) && (defined(_WIN32) || defined(_WIN64))
    ret = 0 == fopen_s(&fp, fname, "r");
#else
    ret = NULL != (fp = fopen(fname, "r"));
#endif
    if (fp) { fclose(fp); }
    return ret;
}

void fdel(const char* fname)
{
    if(fexists(fname)){
        remove(fname);
    }
}
int getIntFromInput(int** arr, int* cnt) {
    int i = 0;
    printf("input sort number count:\n");
#if defined(__STDC_HOSTED__) && (defined(_WIN32)||defined(_WIN64))
    scanf_s("%d", cnt);
#else
    scanf("%d", cnt);
#endif
    if (*cnt > 0) {
        *arr = (int*)calloc(*cnt, sizeof(int));
        if (arr == NULL) {
            printf("memory error\n");
            return -1;
        }
        for (i = 0; i < *cnt; i++) {
            printf("input %d number: ", i + 1);
#if defined(__STDC_HOSTED__) && (defined(_WIN32)||defined(_WIN64))
            scanf_s("%d", *arr + i);
#else
            scanf("%d", *arr + i);
#endif
        }
        return 0;
    }
    return 1;
}
int getIntArray(int** arr, int* cnt) {
    int  ext = 0;
    FILE* fp = NULL;
    const char* fname = "zdata.dat";
    ext = fexists(fname);
    if (ext)
    {
#if defined(__STDC_HOSTED__) && (defined(_WIN32)||defined(_WIN64))
        fopen_s(&fp, fname, "rb+");
#else
        fp = fopen(fname, "rb+");
#endif
    }
    else
    {
#if defined(__STDC_HOSTED__) && (defined(_WIN32)||defined(_WIN64))
        fopen_s(&fp, fname, "wb");
#else
        fp = fopen(fname, "wb");
#endif
    }
    if (fp != NULL)
    {
        if (ext)
        {
            fread(cnt, sizeof(int), 1, fp);
            if (*arr == NULL) {
                *arr = (int*)malloc(*cnt * sizeof(int));
            }
            fread(*arr, sizeof(int), *cnt, fp);
        }
        else
        {
            if (0 == getIntFromInput(arr, cnt))
            {
                fwrite(cnt, sizeof(int), 1, fp);
                fwrite(*arr, sizeof(int), *cnt, fp);
            }
            else
            {
                perror("get int data from input error");
            }
        }
        fclose(fp);
    }
    else
    {
        perror("open int data file error");
        return 1;
    }
    return 0;
}

int getStrFromInput(char (*str)[30], int *cnt, size_t len)
{
    int i = 0;
    printf("input sort string group:\n");
#if defined(__STDC_HOSTED__) && (defined(_WIN32)||defined(_WIN64))
    scanf_s("%d", cnt);
#else
    scanf("%d", cnt);
#endif
    if(*cnt>0)
    {
        if(NULL == str){
            perror("alloc string memory error");
            return -1;
        }
        for(i=0; i<*cnt; i++){
            printf("input %d string: ", i+1);
            fgets(*str + i, len*sizeof(char), stdin);
        }
        return 0;
    }
    return 1;
}

void stringSrt()
{
    int ret = 0;
    int cnt = 3;
    char (*str)[30] = NULL;
}

void selectSrt(int* arr, const int cnt)
{
    int i, j, max, idx = -1;
    for (i = 0; i < cnt; i++) {
        max = arr[i];
        idx = i;
        for (j = i; j < cnt; j++) {
            if (arr[j] < max) {
                max = arr[j];
                idx = j;
            }
        }
        if (idx != i) {
            max = arr[i];
            arr[i] = arr[idx];
            arr[idx] = max;
        }
    }
}

void bubble(int* arr, const int cnt)
{
    int i, j, t;
    for (i = 0; i < cnt; i++) {
        for (j = 0; j < cnt - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                t = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = t;
            }
        }
    }
}

void shellSrt(int arr[], int len) {
    int gap, i, j;
    int temp;
    for (gap = len >> 1; gap > 0; gap >>= 1) {
        for (i = gap; i < len; i++) {
            temp = arr[i];
            for (j = i - gap; j >= 0 && arr[j] > temp; j -= gap) {
                arr[j + gap] = arr[j];
            }
            arr[j + gap] = temp;
        }
    }
}


void sortPractice(void)
{
    int* arr = NULL, * narr = NULL, * sarr = NULL, cnt = 0, snt = 0;
    char (*str)[30] = NULL;
    
    if (0 == getIntArray(&arr, &cnt)) {
        narr = (int*)calloc(cnt, sizeof(int));
        sarr = (int*)calloc(cnt, sizeof(int));
        if (NULL != narr) {
            memcpy(narr, arr, sizeof(int) * cnt);
        }
        if (NULL != sarr) {
            memcpy(sarr, arr, sizeof(int) * cnt);
        }
        printf("input arr :"); printArr(arr, cnt); putchar('\n');
        selectSrt(arr, cnt);
        printf("select sorted arr(ASC):"); printArr(arr, cnt); putchar('\n');
        free(arr); arr = NULL;
        if (NULL != narr) {
            bubble(narr, cnt);
            printf("bubble sorted arr(ASC):"); printArr(narr, cnt); putchar('\n');
            free(narr); narr = NULL;
        }
        if (NULL != sarr) {
            shellSrt(sarr, cnt);
            printf("shell  sorted arr(ASC):"); printArr(sarr, cnt); putchar('\n');
            free(sarr); sarr = NULL;
        }
        printf("every sort is done\n");
    }
    else {
        printf("get int array error\n");
    }
    stringSrt();
}
void question01(void)
{
}
void practiceQuestions(void)
{
    
}
int main(int argc, char *argv[])
{
    const char *fname = "zdata.dat";
    if(argc > 1){
        if(strstr(argv[1], "del")){
            fdel(fname);
        }else if(strspn(argv[1], "/?-")){
            printf("Usage: %s [del]  delete sorted data\n", argv[0]);
        }
    }
    sortPractice();
    practiceQuestions();
    return 0;
}
