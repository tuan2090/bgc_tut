#include <stdio.h>
#include <stdlib.h>

int main(void){
  char *val = getenv("MMYYEENNVV");

  if (val == NULL) {
    printf("Cannot find MMYYEENNVV enviroment variable\n");
    return EXIT_FAILURE;
  }

  printf("MMYYEENNVV value: %s\n", val);

  return 0;
}
