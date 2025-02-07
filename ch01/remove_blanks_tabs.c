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
  int i, limit;

  if(s[length - 1] == '\n') {
      limit = length - 2;
  } else {
      limit = length - 1;
  }
  
  for (i = limit; i >= 0; --i) {
      if (s[i] != ' ' && s[i] != '\t') {
      break;
    }
  }
  
  s[++i] = '\0';
}
