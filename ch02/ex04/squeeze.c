#include <stdio.h>

#define MAXCHAR 1000

void squeeze(char [], char []);

void squeeze(char s1[], char s2[])
{
  int i, j, m;

  m  = 0;
  for (i = 0; s1[i] != '\0'; i++) {
    for(j = 0; s2[j] != '\0' && s1[i] != s2[j]; ++j)
      ;
    if(s2[j] == '\0')
      s1[m++] = s1[i];
  }
  s1[m] = '\0';
}

int main()
{
  char string1[MAXCHAR] = "Clea===ned Str-----ing=== -------";
  char string2[MAXCHAR] = "-=";

  squeeze(string1, string2);
  printf("%s\n", string1);
  
  return 0;
}
