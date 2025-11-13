#include <stdio.h>

// print array
void print_1d_int_array(int *arr, int len){
  printf("[ ");
  for (int i = 0; i < len; i++){
    printf("%d ", arr[i]);
  }
  printf("]\n");
}

// typedef and struct - struct
typedef struct player_info {
  char *name;
  int heart; // range(0, 100)
} player_info;

int main(void){
  // typedef theory
  typedef int nat_num;

  nat_num num1 = 6;
  nat_num num2 = 4;
  nat_num result = num1 + num2;
  printf("num1: %d + num2: %d = result: %d\n", num1, num2, result);

  // typedef and struct
  struct player_info player1 = {
    .name="aliceinwonderland",
    .heart=88
  };
  printf("player %s info:\n", player1.name);
  printf("heart | %d\n", player1.heart);

  player_info player2 = {
    .name="bobinmansion",
    .heart=66
  };
  printf("player %s info:\n", player2.name);
  printf("heart | %d\n", player2.heart);

  // typedef and pointer
  typedef int *intptr;
  int a = 54;
  intptr b = &a;
  printf("a, *b = %d, %d\n", a, *b);
  *b = *b + 1;
  printf("a, *b = %d, %d\n", a, *b);


  // typedef and array
  typedef int five_ints[5];
  five_ints arr = {9, 8, 7, 6, 5};

  print_1d_int_array(arr, 5);

  return 0;
}
