#include <stdio.h>
#include <stdarg.h>

// ellipses in function signatures - function
void foo(int a, ...){
  printf("a is equal to %d\n", a);
}

// getting extra arguments - function
int sumof(int count, ...){
  int sum = 0;
  va_list va;

  va_start(va, count);
  for (int i = 0; i < count; i++) {
    int num = va_arg(va, int);

    sum += num;
  }
  va_end(va);

  return sum;
}

// example: println - function
void println(const char *format, ...){
  va_list va;

  va_start(va, format); // may contain {
  vprintf(format, va);
  printf("\n"); // may contain }
  va_end(va);
}

int main(void){
  // ellipses in function signatures
  foo(55, 44, 33, 22, 11);

  // getting extra arguments
  printf("sum of 5, 6 and 7 is %d\n", sumof(3, 5, 6, 7));
  printf("sum of 1, 2, 3 and 4 is %d\n", sumof(4, 1, 2, 3, 4));

  // example: println
  println("Hello, %s!", "World");

  return 0;
}
