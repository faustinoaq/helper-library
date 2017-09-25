// @zetatino, 2015
// Search Functions

#include "sort.h"
#include <stdlib.h>
#include <string.h>

// DECLARATIONS

// WORKING for split this file in declarations and implementations

int search_int(int key, int length, int array[]);
int search_float(float key, int length, float array[]);
int search_str(char key[], int length, int strlength, char array[][length]);

int search_int(int key, int length, int array[]) {
  int i, c=0, * aux, * val;
  aux = array;
  sort_int_array(length, aux);
  val = (int *) bsearch (&key, aux, length, sizeof(int), data_cmp);
  if (val == NULL) {
    return 0;
  } else {
    for(i=0; i<length; i++) {
      if (array[i] == key) {
        c++;
      }
    }
    return c;
  }
}

int search_float(float key, int length, float array[]) {
  float * aux;
  int i, c=0, * val;
  aux = array;
  sort_float_array(length, aux);
  val = (int *) bsearch (&key, aux, length, sizeof(float), data_cmp);
  if (val == NULL) {
    return 0;
  } else {
    for(i=0; i<length; i++) {
      if (array[i] == key) {
        c++;
      }
    }
    return c;
  }
}

int search_str(char key[], int length, int strlength, char array[][strlength]) {
  int * val;
  int i, c=0;
  sort_str_array(length, strlength, array);
  val = (int*) bsearch (key,
                         array,
                         length,
                         strlength,
                         (int(*)(const void*,const void*)) strcmp);
  if (val == NULL) {
    return 0;
  } else {
    for(i=0; i<length; i++) {
      if (strcmp(array[i], key) == 0) {
        c++;
      }
    }
    return c;
  }
}
