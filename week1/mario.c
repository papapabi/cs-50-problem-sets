#include <stdio.h>
#include <stdbool.h>

int get_int();

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

int get_int() {
  int i = 0;
  while(true) {
    scanf("%d", &i);
    if(i >= 0 && i <= 23) {
      break;
    }
    printf("Retry: ");
  }
  return i;
}