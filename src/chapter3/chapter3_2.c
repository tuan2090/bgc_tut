#include <stdio.h>
#include <stdbool.h>

int main(void){
  // Arithmetic Operaror
  int i = 0;
  printf("i = %d\n", i);

  i += 5;
  printf("i = %d\n", i);
  i -= 3;
  printf("i = %d\n", i);
  i *= 12;
  printf("i = %d\n", i);
  i /= 4;
  printf("i = %d\n", i);
  i %= 5;
  printf("i = %d\n", i);

  // Ternary Operaror
  int x = 53;
  printf("the number %d is %s\n", x, x%2 == 0?"Even":"Odd");

  // Pre-and-Post Increment-and-Decrement
  int m1 = 10;
  int n1 = 5 + m1++;
  printf("m1, n1 = %d, %d\n", m1, n1);

  int m2 = 10;
  int n2 = 5 + ++m2;
  printf("m2, n2 = %d, %d\n", m2, n2);

  // Comma Operaror
  int x1 = 5, x2 = 3;
  printf("x1, x2 = %d, %d\n", x1, x2);

  // Conditional Operaror
  int a = 5;
  int b = 8;

  printf("a, b = %d, %d\n", a, b);
  printf("a == b: %d\n", a == b);
  printf("a != b: %d\n", a != b);
  printf("a > b: %d\n", a > b);
  printf("a < b: %d\n", a < b);
  printf("a <= b: %d\n", a <= b);
  printf("a >= b: %d\n", a >= b);

  // Boolean Operaror
  bool b1 = true;
  bool b2 = false;

  printf("b1, b2 = %d, %d\n", b1, b2);
  printf("a && b: %d\n", b1 && b2);
  printf("a || b: %d\n", b1 || b2);
  printf("!a, !b = %d, %d\n", !b1, !b2);

  // sizeof Operaror
  int temp_num = 536;

  printf("temp_num = %d\n", temp_num);
  printf("sizeof temp_num: %zu\n", sizeof(temp_num));

  return 0;
}
