#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#define MAXLL 1000

int linelen(char* s);

int main () {
    FILE *file;
    file = fopen("data", "r");

    int sum = 0;
    char string[MAXLL];
    while (fgets(string, MAXLL, file)) {
        char pair[3];
        pair[2] = '\0';
        int len = linelen(string);
        for (int i = 0; i < len; ++i) {
            int val = isdigit(string[i]);
            if (val)
                pair[1] = string[i];
        }
        for (int j = len; j >= 0; --j) {
            int val = isdigit(string[j]);
            if (val)
                pair[0] = string[j];
        }
        int num = atoi(pair);
        printf("num %i, string %s\n", num, string);
        sum += num;
    }
    printf("%i\n", sum);

}


int linelen(char* s) {
    int i;
    for (i = 0; s[i] != '\n'; i++);
    return i;
}
