#include <stdio.h>
#include <stdlib.h>

#define MAX_LINE_LENGTH 10

int main() {
	FILE *textfile;
	char line[MAX_LINE_LENGTH];

	textfile = fopen("data.txt", "r");
	if (textfile == NULL)
		return 1;

	int sum = 0;
	int sums[10000];
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
	printf("%i\n", sums[5]);

	int max = 0;
	for (int i = 0; i < idx; i++) {
		if (sums[i] > max) {
			max = sums[i];
		}
	}
	printf("%i\n", max);
	fclose(textfile);
	return 0;
	
}
