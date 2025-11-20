// #include
#include <stdio.h>

// simple macros - macros
#define HELLO "Hello,"
#define NAME "Bob"

// conditional compilation - macros
#define HAPPY
#define MODE_C

#define ERR_CODE 200

// macros with one argument - macros
#define SQR(x) ((x) * (x))

// macros with multify argument - macros
#define TRIANGLE_AREA(w, h) (0.5 * (w) * (h))

// macros with variable arguments - macros
#define X(a, b, ...) (10*(a) + 100*(b)), __VA_ARGS__

int main(void){
  // simple macros
  printf("%s %s!\n", HELLO, NAME);

  // conditional compilation
  // #ifdef and #endif
#ifdef HAPPY
  printf("I'm so happy!\n");
  // #else
#else
  printf("I'm neutral!\n");
#endif
  // #ifndef 
// #ifndef HAPPY
//   printf("I'm neutral!\n");
// #endif

  // defined 
#if defined MODE_A
  printf("This is mode A\n");
#elif defined MODE_B
  printf("This is mode B\n");
#elif defined MODE_C
  printf("This is mode C\n");
#else
  printf("No mode!\n");
#endif

  // #if and #elif
#if ERR_CODE == 200
  printf("200 OK!\n");
#elif ERR_CODE == 404
  printf("404 Not found!\n");
#else
  printf("%d is not valid error code!\n", ERR_CODE);
#endif

  // #undef
#define GOAT
#ifdef GOAT
  printf("GOAT is define!\n");
#endif

#undef GOAT
#ifdef GOAT
  printf("GOAT is define!\n"); // doesn't print because GOAT is undefine
#endif

  // build-in macros
  printf("This function: %s\n", __func__);
  printf("This file: %s\n", __FILE__);
  printf("This line: %d\n", __LINE__);
  printf("Compiled on (date): %s\n", __DATE__);
  printf("Compiled on (time): %s\n", __TIME__);
  printf("C version: %ld\n", __STDC_VERSION__);

  // macros with one argument
  int a = 3;
  int b = 4;
  printf("SQR(%d + %d) = %d\n", a, b, SQR(a + b));

  // macros with multify argument
  int vw = 6, vh = 4;
  printf("Area of triangle with w=%d, h=%d is %f\n", vw, vh, TRIANGLE_AREA(vw, vh));

  // macros with variable arguments
  printf("%d, %f, %s, %d\n", X(5, 3, 5.5, "hi", 55));

  return 0;
}
