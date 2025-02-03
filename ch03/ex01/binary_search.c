#include <stdio.h>

#define SIZE 10

int binsearch(int, int [], int);

int binsearch(int x, int v[], int n)
{
  int low, high, mid;

  low = 0;
  high = n - 1;
  while(low < high) {
    mid = (low+high)/2;
    if (x > v[mid])
      low = mid + 1;
    else
      high = mid;
  }
  
  if(v[low] == x)
    return low;
  
  return -1;
}

int main()
{
  int array[SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

  printf("%i\n", binsearch(5, array, SIZE));
  return 0;
}
