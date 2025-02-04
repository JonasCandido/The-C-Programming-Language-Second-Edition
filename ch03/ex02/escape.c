#include <stdio.h>

#define MAXCHAR 1000

int getLine(char [], int);
void escape(char[], char[]);

int getLine(char s[], int lim) {
  int c, i;

  for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
    s[i] = c;
  if (c == '\n')
    s[i++] = c;
  s[i] = '\0';
  return i;
}

void escape(char s[], char t[]) {
  int i, j;
  for (i = j = 0; t[i] != '\0'; ++i, ++j) {
    switch (t[i]) {
        case '\n':
	  s[j] = '\\';
	  s[++j] = 'n';
	  break;
        case '\t':
	  s[j] = '\\';
	  s[++j] = 't';
	  break;
        default:
	  s[j] = t[i];
	  break;
    }
  }
  s[j] = '\0';
}

void escapeToChar(char s[], char t[]) {
  int i, j;
  for (i = j = 0; t[i] != '\0'; ++i, ++j) {
    switch (t[i]) {
        case '\\':
	  switch (t[++i]) {
	      case 't':
	          s[j] = '\t';
	          break;
	      case 'n':
		  s[j] = '\n';
		  break;
	      default:
		  s[j] = t[i];
		  break;
	  }
	  break;
       default:
	 s[j] = t[i];
	 break;
    }
  }
  s[j] = '\0';
}

int main()
{
  char line[MAXCHAR];
  char modline[MAXCHAR];

  while (getLine(line, MAXCHAR) > 0) {
      escape(modline, line);
      printf("%s\n", modline);
      escapeToChar(modline, line);
      printf("%s", modline);
  }
  
  return 0;
}
