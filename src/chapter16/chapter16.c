#include <stdio.h>

void print_1d_int_array(int *arr, int len){
  printf("[ ");
  for (int i = 0; i < len; i++){
    printf("%d ", arr[i]);
  }
  printf("]\n");
}

// const - function
void foo(const int x){
  printf("%d\n", x + 10);
}

// restrict - function
void swap(int *restrict a, int *restrict b){
  int temp;

  temp = *a;
  *a = *b;
  *b = temp;
}

// static in block scope
void counter(void){
  static int count = 1;
  printf("the counter() function is called %d times!\n", count);
  count++;
}

int main(){
  // type qualifier
  // const
  const float PI = 3.14;
  printf("PI ≈ %.2f\n", PI);
  // PI = 1; // error
  
  foo(100);

  // const and pointer
  int arr[] = {10, 30};
  print_1d_int_array(arr, 2);

  const int *p = arr;
  printf("%d\n", *p);

  p++;
  printf("%d\n", *p);
  
  // *p = 30; // error

  // const int *p;
  // equal
  // int const *p;
  
  // int *const p;
  // p++; // error: can't modify "p" with pointer arithmetic

  // const int *const p; // can't modify p or *p

  int x = 100;
  int *const p2 = &x;
  printf("*p2 value is %d\n", *p2);

  *p2 = 200; // set p2 to 200, no error

  printf("*p new value is %d\n", *p2);

  // char **p;
  // p++; // ok
  // (*p)++; // ok

  // char **const p;
  // p++; // error
  // (*p)++; // ok
  
  // char *const *p;
  // p++; // ok
  // (*p)++; // error

  // char *const *const p;
  // p++; // error
  // (*p)++; // error

  // const correctness
  // const int n = 25;
  // int *p3 = &n; // warning
  // printf("%d\n", *p3);
  // *p3 = 40; // maybe modify n, or not
  // printf("%d\n", *p3);
  
  // restrict
  int n1 = 50, n2 = 60;
  printf("before swap: n1=%d, n2=%d\n", n1, n2);

  swap(&n1, &n2);
  printf("after swap: n1=%d, n2=%d\n", n1, n2);

  // swap(&n2, &n2); // warning
  
  // volatile
  // volatile int *p;

  // storage-class specifiers
  // auto
  // {
  //  int a; // auto is the default
  //  auto int b; // so this is redundant
  // }
  
  // static
  // static in block scope
  counter();
  counter();
  counter();
  counter();
  counter();

  // static int foo; // default value is 0
  // static int foo = 0; // so this is redundant

  // extern
  extern int a;
  printf("a in foo.c = %d\n", a);

  // register
  register int num;
  for (num = 0; num < 10; num++) {
    printf("%d\n", num);
  }

  // register int a;
  // int *ptr = &a; // error

  // register int a[] = {1, 3, 5, 7, 9};
  // int *ptr = a; // error

  // register int a[] = {1, 3, 5, 7, 9};
  // int b = *(a + 2); // error

  // register int a[] = {1, 3, 5, 7, 9};
  // int b = a[2]; // warning

  return 0;
}
