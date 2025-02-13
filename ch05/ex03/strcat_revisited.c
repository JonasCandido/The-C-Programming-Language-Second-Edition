#include <stdio.h>

void strCat(char *, char *);

int main()
{
    char str1[32] = "abc";
	char str2[] = "def";

	strCat(str1, str2);
	printf("%s\n", str1);

    return 0;
}

void strCat(char *s, char *t)
{
    for ( ; *s != '\0'; s++)
        ;
    while((*s++  = *t++) != '\0')
        ;
}
