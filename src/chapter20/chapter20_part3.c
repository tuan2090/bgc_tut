#include <stdio.h>

// union and type punning - union
union foo {
  float b;
  short a;
};

// pointer to union - union
union bar {
  int a, b, c, d, e, f;
  float g, h;
  char i, j, k, l;
};

// common initial sequences in union - struct, union, define and function
struct common {
  int type;
};

struct antelope {
  int type;
  int loudness;
};

struct octopus {
  int type;
  int sea_creature;
  float intelligence;
};

union animal {
  struct common common;
  struct antelope antelope;
  struct octopus octopus;
};

#define ANTELOPE 1
#define OCTOPUS 2

void print_animal(union animal *a){
  switch (a->common.type) {
    case ANTELOPE:
      printf("antelope: loudness=%d\n", a->antelope.loudness);
      break;
    case OCTOPUS:
      printf("octopus: sea_creature=%d\n", a->octopus.sea_creature);
      printf("         intelligence=%.1f\n", a->octopus.intelligence);
      break;
    default:
      printf("Unknown animal type!\n");
  }
}

// union and unnamed struct - union and struct
union foo1 {
  struct {
    int x, y;
  } a;

  struct {
    int z, w;
  } b;
};

// passing and returning struct and union - struct
struct bar2 {
  int x, y;
};

struct bar2 b(void) {
  return (struct bar2){ .x=55,  .y=66 };
};


int main(void){
  // union and type punning
  union foo x;
  x.b = 3.1415;

  printf("x.a=%d, x.b=%.4f\n", x.a, x.b);

  // pointer to union
  union bar y;

  int *foo_int_ptr = (int *)&y;
  float *foo_float_ptr = (float *)&y;

  y.a = 12;
  printf("y.a=%d, *foo_int_ptr=%d\n", y.a, *foo_int_ptr);

  y.g = 3.14;
  printf("y.g=%.2f, *foo_float_ptr=%.2f\n", y.g, *foo_float_ptr);

  // -----
  union bar y2;
  int *foo_int_p = (int *)&y2;
  union bar *p = (union bar *)foo_int_p;

  p->a = 12;
  // equal
  // y2.a = 12;
  printf("p->a=%d\n", p->a);

  // common initial sequences in union
  union animal a1 = {
    .antelope.type=ANTELOPE,
    .antelope.loudness = 12
  };
  union animal a2 = {
    .octopus.type=OCTOPUS,
    .octopus.sea_creature=1,
    .octopus.intelligence=12.5
  };

  print_animal(&a1);
  print_animal(&a2);

  // union and unnamed struct
  union foo1 f1;
  f1.a.x = 1;
  f1.a.y = 2;
  f1.b.z = 3;
  f1.b.w = 4;

  printf("f1.a.x = %d\n", f1.a.x);
  printf("f1.a.y = %d\n", f1.a.y);
  printf("f1.b.z = %d\n", f1.b.z);
  printf("f1.b.w = %d\n", f1.b.w);

  // passing and returning struct and union
  struct bar2 b2 = b();
  printf("b2.x, b2.y = %d, %d\n", b2.x, b2.y);
  printf("b().x, b().y = %d, %d\n", b().x, b().y);

  return 0;
}
