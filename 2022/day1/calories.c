#include <stdio.h>

#define MAX_LINE_LENGTH 10

int main() {
	FILE *textfile;
	char line[MAX_LINE_LENGTH];

	textfile = fopen("data.txt", "r");
	if (textfile == NULL)
		return 1;

	while (fgets(line, MAX_LINE_LENGTH, textfile)) {
		int line_length = sizeof(line) / sizeof(line[0]);
		printf("%d\n", line_length);
		printf("%c\n\n", line[0]);
	}
	fclose(textfile);
	return 0;
	
}
