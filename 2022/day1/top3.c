#include <stdio.h>
#include <stdlib.h>

#define MAX_LINE_LENGTH 10

int max(int *array, int len) {
	// finds the maximum value in an array
	// sets the index of that value to 0 and 
	// returns the array

	int max = 0;
	int temp;
	for (int i = 0; i < len; i++) {
		if (array[i] > max) {
			temp = max;
			max = array[i];
			array[i] = temp;
		}
	}

	return max;
}


int main() {
	FILE *textfile;
	char line[MAX_LINE_LENGTH];

	textfile = fopen("data.txt", "r");
	if (textfile == NULL)
		return 1;

	int sum = 0;
	int sums[10000] = {0};
	int idx = 0;
	while (fgets(line, MAX_LINE_LENGTH, textfile)) {
		if (line[0] == '\n') {
			sums[idx] = sum;
			idx++;
			sum = 0;
		} else {
			int value = atoi(line);
			sum += value;
		}
	}

	int maxs[3];
	int total = 0;
	for (int i = 0; i < 3; i++) {
		int maximum = max(sums, idx);
		maxs[i] = maximum;
		printf("%i, ", maximum);
		total += maximum;
	}

	printf("\n%i\n", total);
	fclose(textfile);
	return 0;
	
}
