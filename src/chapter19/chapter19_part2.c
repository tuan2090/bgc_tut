#include <stdio.h>
#include <stdlib.h>

// multiline macros - macros
#define PRINT_SUM(from, to) do { \
  int sum = 0; \
  for (int i = (from); i < (to) + 1; i++) { \
    sum += i; \
  } \
  printf("The sum from %d to %d is %d\n", from, to, sum); \
} while(0)

// example: assert macro - macros
#define ASSERT_ENABLED 1

#if ASSERT_ENABLED
#define ASSERT(c, m) \
do { \
  if (!(c)){\
    fprintf(stderr, __FILE__ ":%d: assertion %s failed: %s\n", __LINE__, #c, #m); \
    exit(1); \
  } \
} while(0)
#else
#define ASSERT(c, m)
#endif

int main(void){
  // multiline macros
  PRINT_SUM(3, 6);

  // example: assert macro
  int x = 5;
  ASSERT(x < 5, "x must be small than 5");

  // #error directive
#define BOX
#ifndef BOX
  #warning You need box to do this!
  #error You need box to do this!
#endif

  return 0;
}
