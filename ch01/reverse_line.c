#include <stdio.h>

#define MAXLINE 1000 /* maximum input line length */

int get_line(char line[], int maxline);
void reverse_line(char line[], int length);

/* reverses input line at a time */
int main()
{
  int len;
  char line[MAXLINE]; /* current input line */

  while ((len = get_line(line, MAXLINE)) > 0) {
    reverse_line(line, len);
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

void reverse_line(char s[], int length) {
  int i, start = 0, end;
  char temp;
   
  if(s[length - 1] == '\n') {
      end = length - 2;
  } else {
      end = length - 1;
  }
  
  while (start < end) {
    temp = s[start];
    s[start] = s[end];
    s[end] = temp;
    start++;
    end--;
  }
}


