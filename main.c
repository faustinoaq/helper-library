// Sort array with my own library
#define MAX_INT 10
#define MAX_FLOAT 10
#define DICT "names.txt"

#include "helper.h"

int main() {

  const int n=5, m=10;
  int i, intVector[n];
  float floatVector[n];
  char strings[n][m];

  // GET data
  for(i=0; i<n; i++) {
    scanf("%d", &intVector[i]);
    scanf("%f", &floatVector[i]);
    scanf("%s", strings[i]);
  }

  show_int_array(n, intVector);
  sort_int_array(n, intVector);
  show_int_array(n, intVector);

  show_float_array(n, floatVector);
  sort_float_array(n, floatVector);
  show_float_array(n, floatVector);

  show_str_array(n, m, strings);
  sort_str_array(n, m, strings);
  show_str_array(n, m, strings);

  i=1;
  float j=1.00;
  char name[4];
  strcpy(name,"Ana");
  printf("%d is %d times in intVector\n", i, search_int(i, n, intVector));
  printf("%.2f is %d times in floatVector\n", j, search_float(j, n, floatVector));
  printf("%s is %d times in strings\n", name, search_str(name, n, m, strings));

  return 0;
}
