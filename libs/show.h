// @nodetino, 2015
// Search Functions

#include <stdio.h>
#include <stdlib.h>

void show_int_array(int length, int array[]);
void show_float_array(int length, float array[]);
void show_str_array(int length, int strlength, char strings[][strlength]);


void show_int_array(int length, int array[]) {
  printf("[");
  for(size_t i=0; i < length; i++) {
    if (i != (length-1)){
      printf("%d, ", array[i]);
    } else {
      printf("%d]\n", array[i]);
    }
  }
}


void show_float_array(int length, float array[]) {
  printf("[");
  for(size_t i=0; i < length; i++) {
    if (i != (length-1)){
      printf("%.2f, ", array[i]);
    } else {
      printf("%.2f]\n", array[i]);
    }
  }
}


void show_str_array(int length, int strlength, char strings[][strlength]) {
  printf("[");
  for(size_t i=0; i < length; i++) {
    if (i != (length-1)){
      printf("\"%s\", ", strings[i]);
    } else {
      printf("\"%s\"]\n", strings[i]);
    }
  }
}
