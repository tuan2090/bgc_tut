#include <stdio.h>
#include <stdlib.h>

int main(void){
  // string conversion
  // numeric value to string
  char numstr[16];
  float num = 3.1415;

  snprintf(numstr, 16, "%f", num);

  printf("numstr = %s\n", numstr);

  // string to numeric value
  char *num2str = "123456";
  int num2 = atoi(num2str);

  printf("num2 = %d\n", num2);

  // -----
  char *num3str = "88888888";
  unsigned long num3 = strtoul(num3str, NULL, 10);

  printf("num3 = %lu\n", num3);

  // -----
  char *num4str = "1011";
  unsigned long num4 = strtoul(num4str, NULL, 2);

  printf("%lb -> %lu\n", num4, num4);

  // -----
  char *str = "12n34";
  char *badchr;

  unsigned long int nval = strtoul(str, &badchr, 10);

  printf("nval = %lu\n", nval);
  printf("Invalid char: %c\n", *badchr);
  
  // -----
  char *str2 = "6543";
  char *badchr2;

  unsigned long int n2val = strtoul(str2, &badchr2, 10);

  if (*badchr2 == '\0') {
    printf("Success! %lu\n", n2val);
  } else {
    printf("Partial conversion: %lu\n", n2val);
    printf("Invalid char: %c\n", *badchr2);
  }

  // char conversion
  printf("%d %d\n", 5, '5');

  char c1 = '6';
  printf("c1 = %d(%c)\n", c1, c1);

  int x1 = c1;
  int y1 = c1 - '0';
  printf("x1, y1 = %d, %d(%c)\n", x1, y1, y1);

  // -----
  int x2 = 8;
  char c2 = x2 + '0';

  printf("%d %c\n", c2, c2);

  // implicit conversion
  // interger promotion
  char n1 = 11, n2 = 22;
  int result = n1 + n2;

  printf("n1(%d) + n2(%d) = %d\n", n1, n2, result);

  // usual arithmetic conversion
  int n3 = 5.3 + 4;
  float n4 = 5 + 3;

  printf("n3, n4 = %d, %f\n", n3, n4);

  // void* implicit conversion
  int x3 = 99;
  void *p = &x3;
  int *q = p;

  printf("*q = %d\n", *q);

  // explicit conversion
  // casting
  int x4 = 2222;
  long y2 = (long)x4 + 12;
  printf("x4, y2 = %d, %ld\n", x4, y2);

  // -----
  int x5 = 1000;
  int *p2 = &x5;
  printf("x5, *p2 = %d, %p\n", x5, (void *)p2);

  // -----
  long y3 = 1234;
  long *p3 = &y3;

  unsigned char *c3 = (unsigned char *)p3;

  printf("y3, *p3, *c3 = %ld, %ld, %c\n", y3, *p3, *c3);

  return 0;
}
