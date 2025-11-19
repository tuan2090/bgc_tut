#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv){
  int sum = 0;
  
  (void)argc;
  
  for (char **p = argv + 1; *p != NULL; p++){
    int value = atoi(*p);

    sum += value;
  }

  printf("sum: %d\n", sum);

  return 0;
}
