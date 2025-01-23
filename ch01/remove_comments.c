#include <stdio.h>

int main()
{
  int c; /* keeps track of current char */
  int nextC; /* keeps track of current char */

  while((c = getchar()) != EOF) {
    if(c == '/') {
      nextC = getchar();
      if(nextC == '*') {
	while((c = getchar()) != EOF) {
	  if (c == '*') {
	    c = getchar();
	    if(c == '/')
	      break;
	  }
	}
      } else if (nextC == '/') {
	while((c = getchar()) != EOF && c != '\n') {
	  ;
	}
	if(c == '\n') {
	  putchar(c);
	}
      } else {
	putchar(c);
	putchar(nextC);
      }
    } else if(c == '"') {
       putchar(c);
        while((c = getchar()) != '"') {
            putchar(c);
        }
        if(c == '"') {
            putchar(c);
        }
    } else if(c == '\''){
       putchar(c);
       while((c = getchar()) != '\'') {
           putchar(c);
       }
       if(c == '\'') {
           putchar(c);
       }
    } else {
      putchar(c);
    }
  }
  
  return 0;
}
