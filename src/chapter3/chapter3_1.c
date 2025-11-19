#include <stdio.h>
#include <stdbool.h>

int main(void){
  int your_score = 263;
  float game_rate = 4.5;
  char last_letter_in_alphabet = 'Z';
  char *your_name = "Bob";
  bool bob_is_here = true;

  printf("Your name is %s\n", your_name);
  printf("Your score is %d\n", your_score);
  printf("The last letter in alphabet is: %c\n", last_letter_in_alphabet);
  printf("Game rate of 'Nv' is %.1f\n", game_rate);

  if (bob_is_here){
    printf("Bob is here!\n");
  } else {
    printf("Bob isn't here!\n");
  }

  return 0;
}
