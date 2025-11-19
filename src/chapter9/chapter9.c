#include <stdio.h>
#include <string.h>

int main(void){
  // open and reading file char-by-char
  FILE *hellofp = fopen("./hello.txt", "r");
  int chr;

  while ((chr = fgetc(hellofp)) != EOF) {
    printf("%c", chr);
  }

  fclose(hellofp);

  // open and reading file line-by-line
  FILE *quotefp = fopen("./quote.txt", "r");
  char buffer[1024];
  int line_count = 0;

  while (fgets(buffer, sizeof(buffer), quotefp) != NULL) {
    printf("%d | %s", ++line_count, buffer);
  }

  fclose(quotefp);

  // formatting input
  FILE *whalesfp = fopen("./whales.txt", "r");
  char name[1024];
  float length;
  int mass;

  printf("Whale name | Length | Mass\n");
  while (fscanf(whalesfp, "%s %f %d", name, &length, &mass) != EOF) {
    printf("%s whale | %.1f meters | %d tonnes\n", name, length, mass);
  }

  fclose(whalesfp);

  // writing text file
  FILE *outputfp = fopen("output.txt", "w");
  char content[] = "Hello, World! I'm BCOT-1234\n";

  fputc('C', outputfp);
  fputc('\n', outputfp);
  fprintf(outputfp, "%s", content);
  fputs("Goodbye, World!", outputfp);

  fclose(outputfp);

  // writing binary file
  FILE *outbinfp = fopen("out.bin", "wb");
  unsigned char bytes[8] = {5, 37, 0, 88, 89, 90, 255, 12};

  fwrite(bytes, sizeof(char), 8, outbinfp);

  fclose(outbinfp);

  // reading binary file
  FILE *outbinrfp = fopen("./out.bin", "rb");
  unsigned char outbinchr;

  while (fread(&outbinchr, sizeof(char), 1, outbinrfp) > 0) {
    printf("%d\n", outbinchr);
  }

  fclose(outbinrfp);

  return 0;
}
