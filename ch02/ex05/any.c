#include <stdio.h>

#define MAXCHAR 1000

int any(char [],char []);

int any(char s1[], char s2[])
{
  int i, j;
  for(i = 0; s1[i] != '\0'; ++i)
    for(j = 0; s2[j] != '\0'; ++j)
      if(s1[i] == s2[j])
	return i;

  return -1;
}

int main()
{
  char string1[MAXCHAR] = "find the w <- here";
  char string2[MAXCHAR] = "w";

  printf("%i\n", any(string1, string2));
  
  return 0;
}
