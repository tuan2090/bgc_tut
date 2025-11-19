#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv){
  if (argc != 3) {
    printf("arguments format: <int: x> <int: y>\n");
    return EXIT_FAILURE;
  }
  
  int arg1 = atoi(argv[1]);
  int arg2 = atoi(argv[2]);
  int calculate = arg1 * arg2;

  printf("%d x %d = %d\n", arg1, arg2, calculate);

  return 0;
}
