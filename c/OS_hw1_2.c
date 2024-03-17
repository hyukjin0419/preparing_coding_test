#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main() {
  int i, j;
  char str[100];
  int count = 1;

  printf("input a text: ");
  fgets(str, sizeof(str), stdin);

  count = 0;

  for (i = 0; i < 14; i++) {
    printf(" ");
  }

  for (i = 0; i < strlen(str); i++) {
    if (!isspace(str[i])) {
      if (count == 0) {
        printf("[");
      } else {
        printf(" ");
      }
      count++;
    } else {
      if (str[i - 1] != ' ') {
        count = 0;
        printf("]");
      } else {
        printf(" ");
      }
    }
  }
  printf("\n");

  return 0;
}
