#include <stdio.h>

#define MAXLINE 1000 /* maximum input line length */
#define MINLINE 80 /* minimum input line length */

int get_line(char line[], int maxline);

/* print lines longest than 80 characters */
int main()
{
  int len;
  char line[MAXLINE]; /* current input line */

  while ((len = get_line(line, MAXLINE)) > 0) {
    if (len > MINLINE) {
      printf("\n%s\n", line);
    } else {
      printf("\nLine with less than %d\n", MINLINE);
    }
  }
}

/* getline: read a line into s, return length */
int get_line(char s[], int lim)
{
  int c, i;

  for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
    s[i] = c;
  if (c == '\n') {
    s[i] = c;
    ++i;
  }
  s[i] = '\0';
  return i;
}
