// Implement a working parser in this file that splits text into individual tokens.
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
  char * pch;
  pch = strtok (argv[1]," ");
  while (pch != NULL)
  {
    printf ("%s\n",pch);
    pch = strtok (NULL, " ");
  }
  return 0;
}	
