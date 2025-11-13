#include <stdio.h>

// void function
void hello(void){
  printf("Hello, World!\n");
}

// passing by value
void say(char content[]){
  printf("%s\n", content);
}

// function prototype
int addnum(void);

int main(void){
  hello();
  say("Hello, Alice!");
}
