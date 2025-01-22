#include <stdio.h>

#define TAB 8

int main()
{
  int c, count = 0, blank_count = 0;

  while((c = getchar()) != EOF) {
    ++count;
    
    if(c == ' ') {
      ++blank_count;

      if (count % TAB == 0 && blank_count > 1)
      {
	putchar('\t');
	blank_count = 0;
      }
    } else {
      while (blank_count)
      {
	putchar(' ');
	--blank_count;
      }

      if (c == '\n')
      {
	count = 0;
      }

      putchar(c);
    }
  }

  return 0;
}
