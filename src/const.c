#include <stdio.h>
#include <string.h>

int main()
{
    char *hstr  = "hello world *hstr";
    char *ostr  = "HELLO WORLD *ostr";
    char sstr[] = "hello world sstr[]";
    char estr[] = "HELLO WORLD estr[]";
    hstr = ostr;
    /* strrev(sstr); */
    /* strupr(sstr); */
    /* strcpy(sstr, strlwr(estr)); */
    /* strcpy(sstr, estr); */
    printf("hstr=%s\nostr=%s\nsstr=%s\nestr=%s\n", hstr, ostr, sstr, estr);
    getchar();
}
