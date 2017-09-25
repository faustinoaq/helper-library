#include <stdio.h>

int main() {
	int i;
	char nom[10][20];

	for (i=0; i<10; i++) {
		printf("name_%i: ", i+1);
		scanf("%s", nom[i]);
	}

	for (i=0; i<10; i++) {
		printf("%s\n", nom[i]);
	}

	return 0;
}
