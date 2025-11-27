#include <stdio.h>
#include <threads.h>

int main(void){
  // escape sequences
  // frequently-used escapes
  printf("Use \\n for new line\n");
  printf("Say \"Hello, World!\"\n");
  printf("%c\n", '\'');

  // single line status update
  for (int i = 3; i >= 0; i--) {
    printf("\ryou have %d second%s... \b", i, i > 1 ? "s" : "");
    fflush(stdout);
    thrd_sleep(&(struct timespec){.tv_sec=1}, NULL);
  }
  
  printf("Done!\n");

  // the question mark escape
  printf("What your name\?\n");
  // printf("WHAT YOUR NAME??!\n"); // warning
  printf("WHAT YOUR NAME?\?!\n");

  // numeric escapes
  printf("A\102C\n");

  printf("\\x:\n");
  printf("\xE2\x80\xA2 Bullet 1\n");
  printf("\xE2\x80\xA2 Bullet 2\n");
  printf("\xE2\x80\xA2 Bullet 3\n");
  
  printf("\\u or \\U:\n");
  printf("\u2022 Bullet 1\n");
  printf("\U00002022 Bullet 2\n");
  printf("\u2022 Bullet 3\n");

  return 0;
}
