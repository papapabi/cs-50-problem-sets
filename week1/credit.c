#include <stdio.h>
#include "cs50.h"
#include <math.h>

void validate(long long);
int first_digit(long long);

int main(int argc, char *argv[]) {
  printf("Input credit card number: ");
  long long c_num = get_long_long();
  validate(c_num);
}

void validate(long long c_num) {
  long long copy_cnum = c_num;
  int digits = floor(log10 ((c_num))) + 1;

  int odd[digits]; // I wonder why int odd[digits] = {0}; doesn't work in c99?
  int even[digits];

  for(int i = 0; i < digits; i++) {
    odd[i] = 0;
    even[i] = 0;
  }

  for(int i = 0; i < digits; i++) {
    int digit = c_num % 10;
    c_num /= 10;
    if((i+1) % 2 == 0) { // every 2nd digit
      even[i] = digit * 2;
    }
    else {
      odd[i] = digit;
    }
  }

  int odd_length = sizeof(odd) / sizeof(odd[0]);
  int even_length = sizeof(even) / sizeof(even[0]);
  int odd_total = 0;
  int even_total = 0;

  for(int i = 0; i < even_length; i++) {
    if(even[i] >= 10) {
      int ones = even[i] % 10;
      int tens = even[i] / 10;
      even_total += ones;
      even_total += tens;
    }
    else {
      even_total += even[i];
    }
  }

  for(int i = 0; i < odd_length; i++) {
    odd_total += odd[i];
  }

  if((odd_total + even_total) % 10 == 0) { // Valid if the sum of the sums above have a last digit of 0
    switch(digits) {
      case 13:
        printf("VISA\n");
        break;
      case 15:
        printf("AMEX\n");
        break;
      case 16:
        if(first_digit(copy_cnum) == 5) {
          printf("MASTERCARD\n");
        }
        else {
          printf("VISA\n");
        }
        break;
    }
  }
  else {
    printf("INVALID\n");
  }
}

int first_digit(long long value) {
  while(value >= 10) {
    value /= 10;
  }
  return value;
}