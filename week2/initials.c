#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_STRING_LEN 80

int main(int argc, char *argv[]) {
  char name[MAX_STRING_LEN];
  char initials[MAX_STRING_LEN];
  bool first = true;
  int c = 0; // The counter for our initials


  printf("Name: ");
  fgets(name, MAX_STRING_LEN, stdin);

  for(int i = 0, l = strlen(name); i < l; i++) {
    if(isspace(name[i])) {
      first = true;
      continue;
    }
    else {
      if(first) {
        first = false;
        initials[c] = toupper(name[i]);
        c++;
      }
      else {
        continue;
      }
    }
  }

  printf("%s\n", initials);
  return 0;
}