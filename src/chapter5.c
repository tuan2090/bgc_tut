#include <stdio.h>

// Passing pointers as arguments - function
void increment(int *ptr){
  *ptr = *ptr + 1;
}

int main(void){
  // Memory and variable
  int x = 32;
  printf("the address of x is: %p\n", (void *)&x);
  printf("the value of x is: %d\n", x);

  // Dereferencing
  int num;
  int *ptr;
  ptr = &num;

  num = 52;
  printf("num = %d\n", num);

  *ptr = 25;
  printf("*ptr = %d\n", *ptr);
  printf("num = %d\n", num);

  // Passing pointers as arguments
  int i = 16;
  int *j = &i;

  printf("i, *j = %d, %d\n", i, *j);
  increment(j);
  printf("i, *j = %d, %d\n", i, *j);

  return 0;
}
