#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "readFile.h"
#define MAXLL 100


int main() {
    FILE *file;
    char line[MAXLL];

    file = fopen("data.txt", "r");
    if (file == NULL)
        return -1;

    int play = 0;
    int score = 0;
    int result;
    char *token;
    while(fgets(line, MAXLL, file)) {
        token = strtok(line, " ");
        result = 3 * (token[2] - 'X');
        switch (result) {
            case 0:
                switch (token[0]) {
                    case 'A':
                        play = 3;
                        break;
                    case 'B':
                        play = 1;
                        break;
                    case 'C':
                        play = 2;
                        break;
                }
                break;
            case 3:
                switch (token[0]) {
                    case 'A':
                        play = 1;
                        break;
                    case 'B':
                        play = 2;
                        break;
                    case 'C':
                        play = 3;
                        break;
                }
                break;
            case 6:
                switch (token[0]) {
                    case 'A':
                        play = 2;
                        break;
                    case 'B':
                        play = 3;
                        break;
                    case 'C':
                        play = 1;
                        break;
                }
                break;
            default:
                return -2;
                break;
        }
        score += play + result;
        printf("token %c, result %c, play %i ", token[0], token[2], play);
        printf("tot %i\n", play+result);
    }
    printf("%i\n", score);
    fclose(file);
}
