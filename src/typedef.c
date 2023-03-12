#include <stdio.h>
#include <string.h>

typedef struct T_Person {
    char name[20];
    int  age;
} AS_person, *AP_person;


int main(void)
{
    struct T_Person tp;
    AS_person ap;
    AP_person pp;
    strcpy(ap.name, "mooring");
    ap.age = 10;
    tp = ap;
    pp = &ap;
    strcpy(pp->name, "mooringniu");
    printf("ap=%s age: %d\n", pp->name, tp.age);
    return 0;
}