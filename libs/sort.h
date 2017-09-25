// @nodetino, 2015
// Search Functions
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// DECLARATIONS

// INT
void sort_int_array(int length, int array[]);
int cmp_int(const void * a, const void * b);

// FLOAT
void sort_float_array(int length, float array[]);
int cmp_float(const void * a, const void * b);

// STR
void sort_str_array(int length, int strlength, char str[][strlength]);

/*
FUNCTIONS BODY

Sort numbers array using qsort function provided by stdlib.h
This method use Quick Sort method
Numbers array need a compare functions for qsort
*/

int data_cmp(void const *lhs, void const *rhs) {
  return ( *(int*)lhs - *(int*)rhs );
}

void sort_int_array(int length, int array[]) {
  qsort (array, length, sizeof(int), data_cmp);
}

void sort_float_array(int length, float array[]) {
  qsort (array, length, sizeof(float), data_cmp);
}

// Sort string array using qsort function provided by stdlib.h
// This method use Quick Sort method
// String array need strcmp function by string.h
void sort_str_array(int length, int strlength, char str[][strlength]) {
  qsort (str, length, strlength, (int(*)(const void*, const void*)) strcmp);
}
