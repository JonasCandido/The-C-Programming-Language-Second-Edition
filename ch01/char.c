#include <stdio.h>

/* copy input to outpu; 2nd version */
int main()
{
  int c;
  printf("%d\n", EOF);
  printf("%d\n", (getchar() != EOF));
  while ((c = getchar()) != EOF) {
    putchar(c);
  }

  return 0;
}
