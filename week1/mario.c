#include <stdio.h>
#include "cs50.h"

int main(int argc, char *argv[]) {
  printf("Rows: ");
  int rows = get_int();
  printf("Gaps: ");
  int gaps = get_int();
  for(int i = 0; i < rows; i++) {
    for(int s = i; s < rows; s++) {
      printf(" ");
    }

    for(int c = 0; c <= i; c++) {
      printf("#");
    }

    for(int j = 0; j < gaps; j++) {
      printf(" ");
    }

    for(int c = 0; c <= i; c++) {
      printf("#");
    }

    printf("\n");
  }

  return 0;
}