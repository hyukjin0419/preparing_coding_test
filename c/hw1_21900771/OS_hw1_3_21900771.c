#include <ctype.h>
#include <stdio.h>
#include <string.h>

typedef struct {
  int start;
  int end;
  char str[100];
} Words;

int main() {
  int i, j;
  char str[100];
  char newStr[100];
  int sizeOfWord = 0;
  int count = 0;
  int countWords = 0;

  printf("input a text: ");
  fgets(str, sizeof(str), stdin);

  // str[strlen(str)-1] = '\0';

  for (i = 0; i < strlen(str); i++) {
    if (isspace(str[i])) {
      if (str[i - 1] != ' ') {
        sizeOfWord++;
      }
    }
  }

  // printf("%d", sizeOfWord);
  Words words[sizeOfWord];

  for (i = 0; i < 14; i++) {
    printf(" ");
  }

  for (i = 0; i < strlen(str); i++) {
    if (!isspace(str[i])) {
      if (count == 0) {
        printf("[");
        words[countWords].start = i;
      } else {
        printf(" ");
      }
      newStr[count] = str[i];
      count++;
    } else {
      if (str[i - 1] != ' ') {
        newStr[count] = '\0';
        strcpy(words[countWords].str, newStr);
        words[countWords].end = i;
        count = 0;
        printf("]");
        countWords++;
      } else {
        printf(" ");
      }
      
    }
  }

  printf("\n");
  printf("\n");

  for (i = 0; i < sizeOfWord; i++) {
    printf("words[%d] = (%d, %d, %s)\n", i, words[i].start, words[i].end,
           words[i].str);
  }

  return 0;
}
