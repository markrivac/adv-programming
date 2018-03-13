#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

#define printDebug(...) do{\
  char *isDebug; \
  isDebug = getenv("DEBUG"); \
  char message[255]; \
  if (isDebug != NULL && !strcasecmp(isDebug,"y")){ \
    fprintf(stderr, __VA_ARGS__); \
  } \
}while(0)

int main(){
  char *fileName = "output2.txt";
  FILE *output;
  int character;
  output = fopen(fileName, "a");
  printDebug("output = %p \n", output);
  while(1){
    character = fgetc(stdin);
    if(feof(stdin)){
      break;
    }
    fputc(character, output);
  };
  fclose(output);
  return 0;
}