#include <stdio.h>
#include <stdlib.h>
#define MAXLL 100

int linelen(char*);
char findcommon(char*, int, int);

int main() {
    FILE *file;
    file = fopen("data.txt", "r");
    if (file == NULL)
        return -1;

    unsigned int priority = 0;
    char line[MAXLL];
    while(fgets(line, MAXLL, file)) {
        int len = linelen(line);
        int midpoint = len / 2;
        char letter = findcommon(line, midpoint, len);
        printf("%c\n", letter);
        if (letter > '`') 
            priority += letter - '`';
        else if (letter > '@')
            priority += letter - '@' + 26;
        else
            return -1;
    }
    printf("%u\n", priority);
}

int linelen(char* line) {
    int i;
    for (i = 0; line[i] != '\n'; ++i);
    return i;
}

char findcommon(char* line, int midpoint, int len) {
    for (int i = 0; i < midpoint; ++i) {
        for (int j = midpoint; j < len; ++j)
            if (line[i] == line[j])
                return line[i];
    }
    return -1;
}
