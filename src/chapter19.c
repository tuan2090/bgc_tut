// #include
#include <stdio.h>

// simple macros - macros
#define HELLO "Hello,"
#define NAME "Bob"

// conditional compilation - macros
#define HAPPY
#define MODE_A

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

  // #elifdef and #elifndef
  // new feature in C23
#ifdef MODE_A
  printf("This is mode A\n");
#elifdef MODE_B
  printf("This is mode B\n");
#elifdef MODE_C
  printf("This is mode C\n");
#else
  printf("No mode!\n");
#endif

  printf("OK!\n");

  return 0;
}
