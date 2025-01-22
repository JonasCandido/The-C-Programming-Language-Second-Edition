#include <stdio.h>

#define MAX_LINE 1000 /* maximum input line length */
#define COLUMN_WIDTH 2 /* maximum output line length */

int get_line(char line[], int maxline);
void fold_line(char line[], char linetofold[]);

/* print folded line */
int main()
{
  int len; /* current input line length */
  char line[MAX_LINE]; /* current input line */
  char foldedLine[MAX_LINE]; /* folded input line */
  
  while((len = get_line(line, MAX_LINE)) > 0) {
    if (len > COLUMN_WIDTH) {
      fold_line(line, foldedLine);
      printf("%s", foldedLine);
    } else {
      printf("%s", line);
    }
  }
  
  return 0;
}

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

/* builds folded line */
void fold_line(char s[], char s2[]) {
  int lastBlank; /* position of the last non-blank character */
  int countChar; /* number of chars from fold point */
  int i; /* position of current char */
  int spaceFound ;

  spaceFound = countChar = lastBlank = 0;
  for (i = 0; s[i] != '\0'; ++i) {
    s2[i] = s[i];
    ++countChar;
    if (s[i] == ' ' || s[i] == '\t') {
      if (!spaceFound) {
           lastBlank = i; /* keep track of last blank position */
      } 
      spaceFound = 1;
    } else {
          spaceFound = 0;
    }

    if(countChar > COLUMN_WIDTH && lastBlank != 0) {
      s2[lastBlank] = '\n';
      i = lastBlank;
      countChar = lastBlank = 0;
    }
  }
  s2[i] = '\0';
}






