#include <stdio.h>
#include <ctype.h>

#define MAXLEN 1000

int getLine(char [], int);
int isValidRange(char, char);
void expand(char [], char []);

int getLine(char s[], int lim)
{
  int c, i;

  for(i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
    s[i] = c;

  if (c == '\n') {
    s[i] = c;
    ++i;
  }
  s[i] = '\0';

  return i;
}

int isValidRange(char start, char end)
{
  return start < end && ((isdigit(start) && isdigit(end))
			 || (isalpha(start) && isalpha(end)
			 && ((islower(start) && islower(end))
			 || (isupper(start) && isupper(end)))));
}

void expand(char s1[], char s2[])
{
  int i, j, k, dist;

  for (i = j = 0; s1[i] != '\0'; ++i)
    if (i != 0 && s1[i] == '-' && isValidRange(s1[i - 1], s1[i + 1])) {
      dist = s1[i + 1] - s1[i - 1];
      for (k = 1; k < dist; ++k, ++j)
	s2[j] = s1[i - 1] + k;
    } else {
      s2[j++] = s1[i];
    }
  s2[j] = '\0';
}

int main()
{
  char line[MAXLEN];
  char modline[MAXLEN];

  while (getLine(line, MAXLEN) > 0) {
    expand(line, modline);
    printf("%s", modline);
  }
  
  return 0;
}
