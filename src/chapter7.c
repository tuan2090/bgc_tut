#include <stdio.h>
#include <string.h>

// string termination - function
int my_strlen(char *str){
  int count = 0;
  while (str[count] != '\0') {
    count++;
  }
  return count;
}

int main(void){
  // string init
  char *content1 = "Hello, World!";
  char content2[] = "I'm BOTT-1000!";
  char content3[17] = "Good bye, World!";

  // string variable as array
  for (int i = 0; i < 14; i++){
    printf("%c\n", content2[i]);
  }

  // get string length
  printf("The string content1 length is %zu.\n", strlen(content1));

  // string termination
  printf("The content2 length is %d.\n", my_strlen(content2));

  // copying string
  char copy_content3[32];
  strcpy(copy_content3, content3);

  copy_content3[1] = '0';

  printf("%s\n", content3);
  printf("%s\n", copy_content3);

  return 0;
}
