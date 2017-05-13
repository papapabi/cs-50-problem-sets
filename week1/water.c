#include <stdio.h>
#include "cs50.h"

int main(int argc, char *argv[]) {
  printf("How many minutes do you shower? ");
  int minutes = get_int();
  printf("Minutes: %d\n", minutes);
  printf("Bottles: %d\n", minutes * 12);
  return 0;
}