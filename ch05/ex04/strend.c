#include <stdio.h>
#include <string.h>

int strend(char *, char *);

int main()
{
    char string1[] = "C Programming Language";
    char string2[] = "Language";

    printf("%i\n", strend(string1, string2));

    return 0;
}

int strend(char *s, char *t)
{
    s += strlen(s) - strlen(t);

    while (*s && *t)
		if (*s++ != *t++)
			return 0;
	return 1;
}
