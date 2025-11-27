#include <stdio.h>
#include <stddef.h>

// padding bytes and offsetof - struct
struct foo {
  int a;
  char b;
  int c;
  char d;
};

// fake OOP - struct
struct parent {
  int a, b;
};

struct child {
  struct parent super;
  int c, d;
};

// fake OOP - function
void print_parrent(void *p){
  struct parent *self = p;
  printf("parrent: a=%d, b=%d\n", self->a, self->b);
}

void print_child(struct child *self) {
  printf("child: c=%d, d=%d\n", self->c, self->d);
}

// bit-fields - struct
struct bar {
  unsigned int a:5;
  unsigned int b:3;
  unsigned int c:5;
  unsigned int d:3;
};

// non-adjacent bit-fields - struct
// C will only combine adjacent bit-fields
struct bar2 {
  unsigned int a:1;
  unsigned int c:1;
  unsigned int b;
  unsigned int d;
};

// unnamed bit-fields - struct
struct foo2 {
  unsigned char a:2;
  unsigned char :5;
  unsigned char b:1;
};

// zero-width unnamed bit-fields - struct
struct foo3 {
  unsigned int a:1;
  unsigned int b:2;
  unsigned int :0;
  unsigned int c:3;
  unsigned int d:4;
};

int main(){
  // padding bytes
  printf("%zu\n", sizeof(int) + sizeof(char) + sizeof(int) + sizeof(char));
  printf("%zu\n", sizeof(struct foo));

  // offsetof
  printf("%zu\n", offsetof(struct foo, a));
  printf("%zu\n", offsetof(struct foo, b));
  printf("%zu\n", offsetof(struct foo, c));
  printf("%zu\n", offsetof(struct foo, d));

  // fake OOP
  struct child c = {
    .super.a=11, .super.b=22,
    .c=33, .d=44
  };

  print_child(&c);
  print_parrent(&c);

  // bit-fields
  printf("%zu\n", sizeof(struct bar));
  
  printf("%zu\n", sizeof(struct bar2));

  // unnamed bit-fields
  printf("%zu\n", sizeof(struct foo2));

  // zero-width unnamed bit-fields
  printf("%zu\n", sizeof(struct foo3));

  return 0;
}
