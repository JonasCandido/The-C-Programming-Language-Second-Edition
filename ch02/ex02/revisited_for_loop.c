#include <stdio.h>

int main()
{
  int lim = 100;
  int c;
  int i = 0;
  int loop = 1;
  char s[lim];

  while(loop) {
    if ((c = getchar()) == '\n' || c == EOF || i < lim - 1) {
      loop = 0;
      continue;
    }

    s[i] = c;
    ++i;
  }

  if(c == '\n') {
    s[i] = c;
    ++i;
  }
  s[i] = '\0';
    
  return 0;
}
