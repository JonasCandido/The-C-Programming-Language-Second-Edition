#include <stdio.h>

#define SIZE 128

int main()
{
  int c, i, j, count, longestBar;
  int characters[SIZE];

  for (i = 0; i < SIZE; i++)
          characters[i] = 0;

  while ((c = getchar()) != EOF) {
    if (c >= 0 && c < SIZE) {
      ++characters[c];
    }
  }

  printf("\nHorizontal Histogram\n");
  for (i = 0; i < SIZE; i++) {
    printf(" %i", i);
    for (j = 0; j < characters[i]; ++j) {
      printf(" *");
    }
    printf("\n");
  }
  
  return 0;
}
