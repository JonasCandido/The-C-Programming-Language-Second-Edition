#include <stdio.h>
#include <ctype.h>

#define BUFSIZE 100

/* function */
int getch(void);
void ungetch(int);
int getfloat(float *);

/* global */
char buf[BUFSIZE]; /* buffer for ungetch */
int bufp = 0; /* next free position in buf */

int getch(void) /* get a (possibly pushed-back) character */
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) /* push character back on input */
{
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else {
        buf[bufp++] = c;
    }
}

/* getfloat: get next float from input into *pn */
int getfloat(float *pn)
{
    int c, sign;
    float power = 1.0f;

    while (isspace(c = getch())) /* skip white character  */
           ;
    if (!isdigit(c) && c != EOF && c != '+' && c != '-' && c != '.') {
        ungetch(c); /* it is not a number */
        return 0;
    }
    sign = (c == '-') ? -1 : 1;
	if (c == '+' || c == '-')
		if (!isdigit((c = getch()))) /* is the sign is follwed by a digit? */
			return 0; /* it is not a number */
	for (*pn = 0; isdigit(c); c = getch())
		*pn = 10 * *pn + (c - '0');

    if (c == '.')
        while (isdigit(c = getch())) {
            *pn = 10.0 * *pn + (c - '0');
            power *= 10.0;
        }

    *pn = (*pn * sign) / power;

    if (c != EOF)
        ungetch(c);

    return c;
}

int main()
{
    int input;
    float num;

    while ((input = getfloat(&num)) && input != EOF)
		printf("%f\n", num);

    return 0;
}
