#include <stdio.h>
#include <stdbool.h>

int get_int();

int main(int argc, char *argv[]) {
  printf("How many minutes do you shower? ");
  int minutes = get_int();
  printf("Minutes: %d\n", minutes);
  printf("Bottles: %d\n", minutes * 12);
  return 0;
}

int get_int() {
  int i = 0;
  scanf("%d", &i);
  return i;
}
