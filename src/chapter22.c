#include <stdio.h>

// numbering - enum
enum {
  SHEEP, // 0
  CAT, // 1
  DOG, // 2
  SNAKE // 3
};

enum { X=5, Y=3, Z=5 };

enum {
  A, B, C=4, D, // 0, 1, 4, 5
  E, F=3, G, H // 6, 3, 4, 5
};

// your enum is a type - enum
enum items {
  DIAMOND,
  IRON,
  GOLD
};

int main(void){
  // behavior of enum
  // numbering
  printf("CAT, SNAKE = %d, %d\n", CAT, SNAKE);

  // -----
  printf("X, Y, Z = %d, %d, %d\n", X, Y, Z);

  // -----
  printf("A, B, C, D = %d, %d, %d, %d\n", A, B, C, D);
  printf("E, F, G, H = %d, %d, %d, %d\n", E, F, G, H);

  // your enum is a type
  enum items ore = IRON;
  if (ore == IRON) {
    printf("You have iron!\n");
  }
  
  return 0;
}
