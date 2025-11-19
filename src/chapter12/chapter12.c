#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// reading in line of arbitrary length - function
char *readline(FILE *fp){
  int offset = 0;
  int buffsize = 4;
  char *buf = malloc(buffsize);
  int c;

  if (buf == NULL) {
    return NULL;
  }

  while (c = fgetc(fp), c != '\n' && c != EOF) {
    if (offset == buffsize - 1) {
      buffsize *= 2;

      char *new_buf = realloc(buf, buffsize);
      if (new_buf == NULL) {
        free(buf);
	return NULL;
      }

      buf = new_buf;
    }

    buf[offset++] = c;
  }

  if (c == EOF && offset == 0) {
    free(buf);
    return NULL;
  }

  if (offset < buffsize - 1) {
    char *new_buf = realloc(buf, offset + 1);
    if (new_buf != NULL) {
      buf = new_buf;
    }
  }

  buf[offset] = '\0';
  return buf;
}

int main(void){
  // allocating(malloc()) and deallocating(free())
  //int *p = malloc(sizeof(int));
  // or
  int *p = malloc(sizeof(*p));
  *p = 24;

  printf("*p = %d\n", *p);

  free(p);

  // *p = 5; // error: use after free()
  
  // error checking
  int *x = malloc(sizeof(*x) * 10);

  if (x == NULL) {
    printf("Error: failed to allocating x\n");
  }

  free(x);

  // allocating space for array
  int *y = malloc(sizeof(*y) * 10);

  for (int i = 0; i < 10; i++) {
    y[i] = i * 3;
    printf("%d * 3 = %d\n", i, y[i]);
  }

  free(y);

  // allocating with calloc()
  int *y2 = calloc(10, sizeof(*y2));

  for (int i = 0; i < 10; i++){
    y2[i] = i * 5;
    printf("%d * 5 = %d\n", i, y2[i]);
  }

  // changing allocated size with realloc()
  float *p2 = malloc(sizeof(*p2) * 20);

  for (int i = 0; i < 20; i++) {
    p2[i] = i / 20.0;
    printf("p2[%d] = %.2f\n", i, p2[i]);
  }

  float *new_p2 = realloc(p2, sizeof(*p) * 40);

  if (new_p2 == NULL) {
    printf("Error: failed to allocate new_p2\n");
    return 1;
  }

  p2 = new_p2;

  for (int i = 0; i < 40; i++) {
    p2[i] = 1.0 + (i - 20) / 20.0;
    printf("p2[%d] = %.2f\n", i, new_p2[i]);
  }

  free(p2);

  // reading in line of arbitrary length
  FILE *fp = fopen("./test.txt", "r");
  char *line;

  while ((line = readline(fp)) != NULL) {
    printf("%s\n", line);
    free(line);
  }

  fclose(fp);

  // aligned allocation
  char *p3 = aligned_alloc(64, 256);

  strcpy(p3, "Hello, world!");
  printf("*p3 = %s\n", p3);

  free(p3);

  return 0;
}
