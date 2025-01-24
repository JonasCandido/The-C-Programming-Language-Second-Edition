#include <stdio.h>
#include <limits.h>

/* print ranges of types in C */
int main()
{
  printf("Signed Char\n");
  printf("Max: %d\n", SCHAR_MAX);
  printf("Min: %d\n\n", SCHAR_MIN);

  printf("Unsigned Char\n");
  printf("Max: %u\n", UCHAR_MAX);
  printf("Min: %u\n\n", 0);

  printf("Signed Int\n");
  printf("Max: %d\n", INT_MAX);
  printf("Min: %d\n\n", INT_MIN);

  printf("Unsigned Int\n");
  printf("Max: %u\n", UINT_MAX);
  printf("Min: %u\n\n", 0);

  printf("Signed Short\n");
  printf("Max: %d\n", SHRT_MAX);
  printf("Min: %d\n\n", SHRT_MIN);

  printf("Unsigned Short\n");
  printf("Max: %d\n", USHRT_MAX);
  printf("Min: %d\n\n", 0);

  printf("Signed Long\n");
  printf("Max: %ld\n", LONG_MAX);
  printf("Min: %ld\n\n", LONG_MIN);

  printf("Unsigned Long\n");
  printf("Max: %lu\n", ULONG_MAX);
  printf("Min: %lu\n\n", 0);
  
  return 0;
}
