#include <stdio.h>
#include <stdlib.h>

void print_1d_int_array(int *arr, int len){
  printf("[ ");
  for (int i = 0; i < len; i++) {
    printf("%d ", arr[i]);
  }
  printf("]\n");
}

// subtracting pointer - function
int my_strlen(char *str){
  char *p = str;

  while (*p != '\0') {
    p++;
  }

  return p - str;
}

// void pointer - function and struct
void *my_memcpy(void *dest, void *src, int byte_count){
  char *s = src, *d = dest;

  while (byte_count--) {
    *d++ = *s++;
  }

  return dest;
}

typedef struct animal {
  char *name;
  int leg_count;
} animal;

int compar(const void *e1, const void *e2){
  const struct animal *animal1 = e1;
  const struct animal *animal2 = e2;

  if (animal1->leg_count > animal2->leg_count) {
    return 1;
  }

  if (animal1->leg_count < animal2->leg_count) {
    return -1;
  }

  return 0;
}

int main(void){
  int a[5] = {5, 4, 6, 3, 9999};
  print_1d_int_array(a, 5);

  // adding pointer
  int *p = a;
  
  for (int i = 0; i < 5; i++) {
    printf("&a[%d] = %d\n", i, *(p + i));
  }

  // changing pointer
  int *p2 = a;

  while (*p2 != 9999) {
    printf("%d\n", *p2);
    p2++;
  }

  // subtracting pointer
  char *str = "Hello";
  printf("the string length of '%s' is %d\n", str, my_strlen(str));

  // array/pointer equivalence
  // E1[E2] = *(E1 + E2)
  int *p3 = a;

  for (int i = 0; i < 5; i++) {
    printf("%d\n", a[i]);
  }

  for (int i = 0; i < 5; i++) {
    printf("%d\n", p3[i]);
  }

  for (int i = 0; i < 5; i++) {
    printf("%d\n", *(a + i));
  }

  for (int i = 0; i < 5; i++) {
    printf("%d\n", *(p3 + i));
  }

  for (int i = 0; i < 5; i++) {
    printf("%d\n", *(p3++));
  }
  
  // array/pointer equivalence in function call
  char s[] = "Hello";
  char *t = "Goodbye";

  printf("the length of string '%s' is %d\n", s, my_strlen(s));
  printf("the length of string '%s' is %d\n", t, my_strlen(t));

  // void pointer
  char buff[1024];
  my_memcpy(buff, s, 5);

  printf("%s, World!\n", buff);

  // -----
  struct animal animals[4] = {
    {.name="Cat", .leg_count=4},
    {.name="Snake", .leg_count=0},
    {.name="Monkey", .leg_count=2},
    {.name="Dog", .leg_count=4}
  };

  qsort(animals, 4, sizeof(struct animal), compar);

  for (int i = 0; i < 4; i++){
    printf("%d: %s\n", animals[i].leg_count, animals[i].name);
  }

  return 0;
}
