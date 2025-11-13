#include <stdio.h>

// declaring struct
struct car {
  char *name;
  float price_is_usd;
  float rate;
};

// passing struct to function - function
void set_rate(struct car *c, float new_rate){
  // ugly way
  // (*c).rate = new_rate;
  // arrow operator way
  c->rate = new_rate;
}

void printing_car_struct(struct car *c){
  printf("car %s info:\n", c->name);
  printf("price | $%.2f\n",c->price_is_usd);
  printf("rate | %.1f stars\n", c->rate);
}

int main(void){
  // init struct - struct_name.args method
  struct car bolt;
  bolt.name = "BoLT-1000";
  bolt.price_is_usd = 19999.99;
  bolt.rate = 4.2;

  printing_car_struct(&bolt);
  // init struct - struct struct_name = {} method
  struct car flash = {"flaSH-1200", 20000.99, 3.8};

  printing_car_struct(&flash);
  // passing struct to function
  set_rate(&flash, 4.6);
  printf("the new rate of '%s' is %.1f stars!\n", flash.name, flash.rate);

  // copy struct
  struct car copy_flash;
  copy_flash = flash;
  copy_flash.name = "CoPyFLASH-2000";

  printing_car_struct(&copy_flash);

  return 0;
}
