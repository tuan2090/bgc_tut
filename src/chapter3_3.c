#include <stdio.h>
#include <stdlib.h>

int main(void){
  // if-else statement
  int x = 55;
  printf("x = %d\n", x);

  if (x > 50){
    printf("x > 50\n");
  } else if (x < 50) {
    printf("x < 50\n");
  } else {
    printf("none!\n");
  }

  // while statement
  printf("With while:\n");
  int i = 0;
  while (i < 15) {
    printf("i = %d\n", i);
    i++;
  }
  printf("Done!\n");

  // do-while statement
  printf("With do-while:\n");
  int j = 0;
  do {
    printf("j = %d\n", j);
    j++;
  } while (j < 15);
  printf("Done!\n");

  // do-while statement example
  int rand_num;
  do {
    rand_num = rand() % 100;
    printf("%d\n", rand_num);
  } while (rand_num != 50);

  // for statement
  printf("With for:\n");
  for (int n = 0; n < 15; n++){
    printf("n = %d\n", n);
  }

  // for with comma operator
  for (int m = 0, n = 10; m < 10; m++, n--){
    printf("m, n = %d, %d\n", m, n);
  }

  // switch-case statement
  int code = 404;
  switch (code) {
    case 200:
      printf("200 OK!\n");
      break;

    case 404:
      printf("404 Not Found!\n");
      break;

    default:
      printf("Code not found!\n");
      break;
  }

  return 0;
}
