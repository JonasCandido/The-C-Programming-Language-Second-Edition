#include <stdio.h>

#define MAXLINE 1000 /* maximum input line length */

int get_line(char line[], int maxline);
void remove_blanks_tabs(char line[], int length);

/* remove training blanks and tabs from each line of input */
int main()
{
  int len;
  char line[MAXLINE]; /* current input line */
  
  while ((len = get_line(line, MAXLINE)) > 0) {
    remove_blanks_tabs(line, len);
    printf("%s", line);
  }

  return 0;
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

void remove_blanks_tabs(char s[], int length) {
  int c, i;
  
  for (i = length - 2; i >= 0 && (s[i] == ' ' || s[i] != '\t'); --i)
    break;
  s[++i] = '\n';
  s[++i] = '\0';
}
