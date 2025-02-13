#include <stdio.h>
#define MAXLINE 1000 /* maximum input line length */

int get_line(char *, int);

int main()
{
    int len; /* current line length */
    char line[MAXLINE];

    while ((len = get_line(line, MAXLINE)) > 0)
        printf("%i\n", len);
    return 0;
}

/* get_line: read a line into s, return length */
int get_line(char *s, int lim)
{
    int c, i;

     i = 0;

    while (--lim > 0 && (c = getchar()) != EOF && c != '\n') {
        *s++ = c;
        ++i;
    }
    if (c == '\n') {
        *s++ = c;
        ++i;
    }
    *s = '\0';

    return i;
}
