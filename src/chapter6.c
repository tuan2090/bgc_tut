#include <stdio.h>

// print array
void print_1d_array_int(int *arr, int len){
  printf("[ ");
  for (int i = 0; i < len; i++){
    printf("%d ", arr[i]);
  }
  printf("]\n");
}

void print_1d_array_float(float *arr, int len){
  printf("[ ");
  for (int i = 0; i < len; i++){
    printf("%.1f ", arr[i]);
  }
  printf("]\n");
}

// passing single dimension array to function - function
void add2(int *arr, int len){
  for (int i = 0; i < len; i++) {
    printf("arr[%d] + 2 = %d\n", i, arr[i] + 2);
  }
}

void times5(int arr[], int len){
  for (int i = 0; i < len; i++) {
    printf("arr[%d] * 5 = %d\n", i, arr[i] * 5);
  }
}

void mod2(int arr[5]){
  for (int i = 0; i < 5; i++) {
    printf("arr[%d] + 2 = %d\n", i, arr[i] % 2);
  }
}

// changing array in function - function
void triple_array(int *arr, int len){
  for (int i = 0; i < len; i++){
    arr[i] *= 3;
  }
}

// pointer multidimension array to function - function
void print_3x3_array_int(int arr[3][3]){
  printf("[\n");
  for (int row = 0; row < 3; row++){
    printf("[ ");
    for (int col = 0; col < 3; col++){
      printf("%d ", arr[row][col]);
    }
    printf("]\n");
  }
  printf("]\n");
}

int main(void){
  // creating array - arr[nth] method
  float arr[5];
  arr[0] = 5.3;
  arr[1] = 8.2;
  arr[2] = 2.7;
  arr[3] = 6.1;
  arr[4] = 9.5;

  print_1d_array_float(arr, 5);

  // getting the length of array
  printf("len(arr) = %zu\n", sizeof(arr) / sizeof(float));

  // creating array - {} method
  int arr2[10] = {5, 10, 15, 20, 25, [6]=35, [8]=45};

  print_1d_array_int(arr2, 10);

  // multidimension array
  int arr2d[3][3] = {
    {19, 28, 37},
    {46, 55, 64},
    {73, 82, 91}
  };

  print_3x3_array_int(arr2d);

  // getting pointer to array
  int arr3[5] = {10, 29, 38, 47, 56};
  int *p;

  for (int i = 0; i < 5; i++){
    p = &arr3[i];
    printf("the value of &arr3[%d] is %d\n", i, *p);
  }

  // passing single dimension array to function
  int arr4[5] = {11, 12, 13, 14, 15};
  print_1d_array_int(arr4, 5);

  add2(arr4, 5);
  times5(arr4, 5);
  mod2(arr4);

  // changing array in function
  int arr5[5] = {5, 4, 3, 2, 1};
  triple_array(arr5, 5);
  print_1d_array_int(arr5, 5);

  // passing multidimension array to function
  int arr3x3[3][3] = {
    {11,22,33},
    {44,55,66},
    {77,88,99}
  };

  print_3x3_array_int(arr3x3);

  return 0;
}
