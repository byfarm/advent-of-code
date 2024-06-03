#include <stdio.h>
#include <stdlib.h>
#define MAXLL 100

int linelen(char*);
char findcommon(char**, int*);

int main() {
    FILE *file;
    file = fopen("data.txt", "r");
    if (file == NULL)
        return -1;

    unsigned int priority = 0;
    char line[MAXLL];
    char *lines[3];
    int lens[3];
    char* linestr;
    for (int i = 0; fgets(line, MAXLL, file); ++i) {
        int len = linelen(line);
        int idx = i % 3;
        linestr = malloc(sizeof(char) * (1+len));
        for (int k = 0; k < len; ++k)
            linestr[k] = line[k];
        lines[idx] = linestr;
        // printf("%i%s",idx, lines[idx]);
        lens[idx] = len;
        // printf("%i, %i\n", i, idx);
        if (idx == 2) {
            char letter = findcommon(lines, lens);
            int val;
            // printf("%c\n", letter);
            if (letter > '`' && letter <= 'z') 
                val = letter - '`';
            else if (letter > '@' && letter <= 'Z')
                val = letter - '@' + 26;
            else
                return -1;
            priority += val;
            // printf("val %i\n", val);
            for (int l = 0; l < 3; ++l)
                free(lines[l]);
        }

    }
    printf("%i\n", priority);
}

int linelen(char* line) {
    int i;
    for (i = 0; line[i] != '\n'; ++i);
    return i;
}

char findcommon(char** liners, int *leners) {
    for (int j = 0; j < 3; ++j)
        printf("%i%s\n", j, liners[j]);

    for (int i = 0; i < leners[0]; ++i) {
        for (int j = 0; j < leners[1]; ++j)
            for (int k = 0; k < leners[2]; ++k)
                if (
                    liners[0][i] == liners[1][j] &&
                    liners[1][j] == liners[2][k] &&
                    liners[0][i] == liners[2][k]
                )
                    return liners[2][k];
    }
    return -1;
}
