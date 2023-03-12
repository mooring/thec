#include<stdio.h>
#include<string.h>

struct student {
    char name[11];
    float scorel;
    float score2;
};
void output(struct student *p)
{
    printf("Name:%s Total: %.2f\n", (*p).name, p->scorel+p->score2);
}
void test(void)
{
    struct student s[2] = {"aaa",80,90,"bbb",85,95};
    struct student *p   = s;
    printf("Name:%s Total: %.2f\n",s[0].name, s[0].scorel+s[0].score2);
    output(++p);
}
void bubble(void)
{
    char *str[5] = { "chinese","math","english","physics","chemistey"};
    int i, j, x;
    char *m;

    for (i = 0; i < 5; i++)
    {
        for (j = i; j < 5; j++)
        {
            if(strcmp(str[i], str[j]) > 0){
                m      = str[i];
                str[i] = str[j];
                str[j] = m;
            }
        }
    }
    for(x = 0; x < 5; x++) {
        puts(str[x]);
    }
}
int main()
{
    test();
    bubble();
}
