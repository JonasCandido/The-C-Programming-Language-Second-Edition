#include <stdio.h>

/* print Celsius-Fahrenheit table
   for celsius = 0, 20, ..., 300; floating-point version */

int main()
{
  float fahr, celsius;
  float lower, upper, step;

  lower = 0; /* lower limit of temperatuire scale */
  upper = 300;
  step = 20;

  celsius = lower;
  printf("Celsius to Fahrenheit Table\n");
  while (celsius <= upper) {
    fahr = ((9.0/5.0) * celsius) + 32;
    printf("%3.0f %6.1f\n", celsius, fahr);
    celsius = celsius + step;
  }
}
