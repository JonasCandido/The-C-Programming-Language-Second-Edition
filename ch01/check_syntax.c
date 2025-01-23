#include <stdio.h>

int main()
{
  /* Keep track of these symbols and comments  */
  int parentheses = 0;
  int brackets = 0;
  int braces = 0;
  int single_quotes = 0;
  int double_quotes = 0;
  int correct_comment = 0;
  int quote = 0;
 
  /* keeps track of current character */
  int c;
  
  while((c = getchar()) != EOF) {

    if(c == '/') {
      if(correct_comment >= 0){
	if((c = getchar()) != EOF) {
	  if(c == '/') {
	    while((c = getchar()) != EOF && c != '\n')
	      ;
	    correct_comment = 1;
	  }  else if (c == '*') {
	    while(!((c = getchar()) == '*' && (c = getchar()) == '/') && c != EOF &&  c != '\n')
	      ;
	    if(c == '/')
	      correct_comment = 1;
	    else if(c == EOF)
	      correct_comment = -1;
	    else if(c  == '\n')
	      correct_comment = 1;
	  } else {
	    correct_comment = -1;
	  }
	}
     }
   }
    
    /* handle quotes */
    if(c == '\'')
        ++single_quotes;
    else if(c == '"')
        ++double_quotes;
    
    /* handle rest of the symbols */
    if(c == '[')
      ++brackets;
    else if(c == ']')
      --brackets;
    else if(c == '{')
      ++braces;
    else if(c == '}')
      --braces;
    else if(c == '(')
      ++parentheses;
    else if(c == ')')
      --parentheses;
  }

  if(parentheses != 0)
    printf("Syntax Error: Missing  parenthesis\n");

  if(brackets != 0)
    printf("Syntax Error: Missing bracket\n");

  if(braces != 0)
    printf("Syntax Error: Missing braces\n");
  
  if(correct_comment == -1)
    printf("Syntax Error: Comment(s) isn't correct typed or closed\n");
  
  if(single_quotes % 2 != 0)
      printf("Syntax Error: Missing single quote\n");
  
  if(double_quotes % 2 != 0)
      printf("Syntax Error: Missing double quote\n");  

  return 0;
}
