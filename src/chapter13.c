#include <stdio.h>

// file scope
int shared = 101010;

// file scope - function
void func1(void){
  shared += 101;
  printf("shared = %d\n", shared);
}

void func2(void){
  printf("shared = %d\n", shared);
}

int main(void){
  // block scope
  int a = 12; // main() block
  
  if (a == 12) {
    int b = 55;
    printf("a, b = %d, %d\n", a, b);
  } // if() block

  printf("a = %d\n", a);
  // printf("b = %d\n", b); // error

  // where to define variable
  int i = 5;

  printf("i = %d\n", i);
  // printf("j = %d\n", j); // error

  // variable hiding
  int num = 999;

  {
    int num = 888;
    printf("num = %d\n", num);
  }

  printf("num = %d\n", num);

  // file scope
  func1();
  func2();

  // for loop scope
  for (int j = 0; j < 10; j++){
    printf("%d\n", j);
  }
  // printf("j = %d\n", j); // error

  for (int j = 0; j < 10; j++){
    int j = 555;
    printf("%d\n", j);
  }

  return 0;
}
