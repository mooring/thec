#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * Description: get specified env key/value
 * Author : mooring
 * Date   : 2022/12/12 13:18
 * Version: 0.01
 * License: MIT
 * Usage  : ./cref [[os/path/shell] ";/:"]
 * Example:  cref.exe PATH ";"
 *           cref.exe PATH
 *           cref.exe
 *           ./cref
 *           ./cref   PATH ":"
 *           ./cref   SHELL
 * Compling :
 *    vs 6.0  : cl /O2 /W3 /nologo cref.c
 *    vs 2005+: cl /Wall /O2 /nologo cref.c
 *    *nix gcc: gcc -O2 cref.c -o cref
 */

#ifdef _WIN32
#define PATH_DELIMITER ";"
#else
#define PATH_DELIMITER ":"
#endif

void printfVal(const char *val, const char *delim)
{
    int     i = 1;
    char   *p = (char *)val;
    
#if defined(__STDC_HOSTED__) && (defined(_WIN32)||defined(_WIN64))
    char *ntk = NULL;
    p = strtok_s(p, delim, &ntk);
#else
    p = strtok(p, delim);
#endif
    while(p != NULL)
    {
        printf("%02d. %s\n", i++, p);
#if defined(__STDC_HOSTED__) && (defined(_WIN32)||defined(_WIN64))
        p = strtok_s(NULL, delim, &ntk);
#else
        p = strtok(NULL, delim);
#endif
    }
}

int main(int argc, char *argv[])
{
    size_t ret  = 0;
    char *ptr   = NULL;
    char *name  = "PATH";
    char *delim = PATH_DELIMITER;
    if(argc > 1 && strlen(argv[1]) > 1){
        name = argv[1];
    }
    if(argc > 2 && strlen(argv[2]) > 0){
        delim = argv[2];
    }

#if defined(__STDC_HOSTED__) && (defined(_WIN32)||defined(_WIN64))
    getenv_s(&ret, NULL, 0, name);
    if(ret>0){
        ptr = (char *)malloc(ret*sizeof(char));
        if(ptr != NULL){
            getenv_s(&ret, ptr, ret, name); 
        }
    }else{
        ptr = NULL;
        ret = 0;
    }
#else
    ptr = getenv(name);
#endif

    if( ptr != NULL || ret != 0)
    {
        printf("env \"%s\" value:\n", name);
        printfVal(ptr, delim);
    }
    else
    {
        printf("get nothing about %s\n", name);
    }
#if defined(__STDC_HOSTED__) && (defined(_WIN32)||defined(_WIN64))
    if(ret>0 && ptr != NULL){
        free(ptr);
        ptr = NULL;
    }
#endif
    return 0;
}
