#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// initializers of nested struct and array - struct
struct cabin_info {
  int window_count;
  int oxygen_level;
};

struct passenger {
  char *name;
  bool cv19_vaccinated;
};

#define MAX_PASSENGERS 10

struct spaceship {
  char *manufacturer;
  struct cabin_info ci;
};

struct car {
  char *manufacturer;
  struct passenger passenger[MAX_PASSENGERS];
};

// anonymous struct - struct
typedef struct {
  char *name;
  int leg_count, speed_in_kmh;
} animal;

// self-referential struct - struct
struct node {
  int data;
  struct node *next;
};

// flexible array member - struct
struct len_string {
  int length;
  char data[];
};

struct len_string *len_string_from_c_string(char *str){
  int len = strlen(str);

  struct len_string *lenstr = malloc(sizeof(*lenstr) + len);

  lenstr->length = len;

  memcpy(lenstr->data, str, len);

  return lenstr;
}

int main(void){
  // initializers of nested struct and array
  struct spaceship s = {
    .manufacturer="SpaceXYZ",
    .ci.window_count = 8,
    .ci.oxygen_level = 32
  };
  printf("%s: %d seats, %d%% oxygen\n", s.manufacturer, s.ci.window_count, s.ci.oxygen_level);

  // -----
  struct spaceship s2 = {
    .manufacturer="SpaceOZ",
    .ci = {
      .window_count = 6,
      .oxygen_level = 45
    }
  };
  printf("%s: %d seats, %d%% oxygen\n", s2.manufacturer, s2.ci.window_count, s2.ci.oxygen_level);

  // -----
  struct car c = {
    .manufacturer="Cardy",
    .passenger={
      [0].name="John",
      [0].cv19_vaccinated=true,
      [1] = {
        .name="Alice",
	.cv19_vaccinated=true
      },
      [7] = {
        .name="Bob",
	.cv19_vaccinated=false
      }
    }
  };

  printf("Passengers for %s car:\n", c.manufacturer);
  printf("Name | CV19 vaccinated\n");
  for (int i = 0; i < MAX_PASSENGERS; i++) {
    if (c.passenger[i].name != NULL) {
      printf("%s | ", c.passenger[i].name);
      if (c.passenger[i].cv19_vaccinated) {
        printf("Vaccinated\n");
      } else {
        printf("Not vaccinated\n");
      }
    }
  }

  // anonymous struct
  animal a = { .name="Dog", .leg_count=4, .speed_in_kmh=12 };
  printf("Name | Legs | Speed\n");
  printf("%s | %d | %d\n", a.name, a.leg_count, a.speed_in_kmh);

  // self-referential struct
  struct node *head;

  // setup linked list
  // (10) -> (20) -> (30)
  head = malloc(sizeof(struct node));
  head->data = 10;
  head->next = malloc(sizeof(struct node));
  head->next->data = 20;
  head->next->next = malloc(sizeof(struct node));
  head->next->next->data = 30;
  head->next->next->next = NULL;

  // traverse it
  for (struct node *cur = head; cur != NULL; cur = cur->next) {
    printf("%d\n", cur->data);
  }

  // flexible array member
  struct len_string *str = len_string_from_c_string("Hello, World!");
  printf("*str data: %s\n", str->data);
  printf("*str length: %d\n", str->length);

  return 0;
}
