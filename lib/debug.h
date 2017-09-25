// @nodetino, 2015
// Debug Library

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef MAX_INT
  #define MAX_INT 100  // integers range 100 → 0-99
#endif
#ifndef MAX_FLOAT
  #define MAX_FLOAT 1000 // float range 1000 → 0.00 - 1000.00
#endif
#ifndef DICT
  #define DICT "lib/strings.txt" // Default String dictionary
#endif

void debug_int(int*);
void debug_float(float*);
void debug_str(char[]);

void debug_int(int* N) {
  *N = (rand() % MAX_INT) + 1;
  printf("%d\n", *N);
}

void debug_float(float* N) {
  *N = ((rand() % (MAX_FLOAT*100))/100.0) + 1;
  printf("%.2f\n", *N);
}

void debug_str(char S[]) {
  FILE * file;
  file = fopen(DICT, "r");
  int words=0;
  char str[80];
  if (file != NULL) {
    // Cpunt words in Dictionary
    while (!feof(file)) {
      if(fscanf(file, "%s", str)) {
        words++;
      }
    }
    words--;
    if (words <=0 ) {
      printf("\n\tError: too few  words in dictionary\n");
      exit(1);
    }
    fclose(file);
  } else {
    printf("Dictionary Error\n");
    exit(1);
  }
  file = fopen(DICT, "r");
  char strings[words][10];
  int i=0;
  if (file != NULL) {
    while (!feof(file)) {
      fscanf(file, "%s", strings[i]);
      i++;
    }
    fclose(file);
    strcpy(S, strings[rand() % words]);
    strcat(S, "\0");
    printf("%s\n", S);
  } else {
    printf("Dictionary Error\n");
    exit(1);
  }
}
