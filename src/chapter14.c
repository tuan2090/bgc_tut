#include <stdio.h>

int main(void){
  // signed and unsigned interger

  /*
  short s;
  int i;
  long l;
  long long ll;
  unsigned short uss;
  unsigned int usi;
  unsigned long usl;
  unsigned long long usll;
  */

  // signed and unsigned character

  char temp = 'A';
  printf("%c:  %d\n", temp, temp);

  /*
  char c; // could be signed or unsigned
  signed char sc;
  unsigned char usc;
  */

  char n1 = 55, n2 = 12;
  printf("%d + %d = %d\n", n1, n2, n1 + n2);

  char n = 5;
  char chr = 'A';
  char result = n + chr;

  printf("%c: %d\n", result, result);

  // float
  /*
  float f;
  double d;
  long double ld;
  */

  float f1 = 1.23456f;
  float f2 = 0.00000789f;

  printf("f1, f2 = %.5f, %.8f\n", f1, f2);

  f1 += f2; // f2 should equal 1.23456789
  
  printf("f1 = %.8f\n", f1);

  // constant numeric type
  int hex = 0xA; // hexadecimal
  int octal = 0111; // octal
  
  printf("%x -> %d\n", hex, hex);
  printf("%o -> %d\n", octal, octal);

  // interger constant
  /*
  int i = 12;
  long int li = 12L;
  long long int lli = 12LL;

  unsigned int usi = 12U;
  unsigned long int usli = 12UL;
  unsigned long long int = uslli = 12ULL;
  */

  // float constant
  /*
  float f = 5.5f;
  double d = 5.5;
  long double ld = 5.5L
  */

  // scientific notation
  double d = 123456.0;
  printf("d = %e\n", d);

  float f = 12e-1f;
  printf("f = %f\n", f);

  return 0;
}
