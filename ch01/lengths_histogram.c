#include <stdio.h>

#define SIZE 5
#define OUT 1
#define IN 0

int main()
{
  int c, i, j, count, state, longestBar;
  int lengths[SIZE];

  for (i = 0; i <= SIZE; i++)
          lengths[i] = 0;

  state = OUT;
  count = 0;
  while ((c = getchar()) != EOF) {
    if (c == ' ' || c == '\t' || c == '\n')
      state = OUT;
    else
      state = IN;

    if (state == IN)
            ++count;

    if (state == OUT) {
            if (count < 3)
	            ++lengths[0];
	    else if (count >= 3 && count < 7)
	            ++lengths[1];
	    else if (count >= 7 && count < 13)
	            ++lengths[3];
	    else if (count >= 13)
	            ++lengths[4];
	    count = 0;
     }
   }

  printf("\nHorizontal Histogram\n");
  for (i = 0; i < SIZE; ++i) {
    printf(" %i", lengths[i]);
    for (j = 0; j < lengths[i]; ++j)
      printf(" *");
    printf("\n");
  }

  printf("\nVertical Histogram\n");
  longestBar = lengths[0];
  for (i = 0; i < SIZE; ++i) {
    if (lengths[i] > longestBar) {
      longestBar = lengths[i];
    }
  }

  while (longestBar > 0) {
    for (i = 0; i < SIZE; ++i) {
      if (lengths[i] != 0) {
	if (lengths[i] < longestBar) {
	  printf("%2c", ' ');
	} else {
	  printf("%2c", '*');
	}
      }
    }
    printf("\n");
    --longestBar;
  }

  for (i = 0; i < SIZE; ++i) {
    if (lengths[i] != 0) {
      printf("%2i", lengths[i]);
    }
  }
  printf("\n");
  
  return 0;
}
