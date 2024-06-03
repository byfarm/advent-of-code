#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXLL 100


int main() {
    FILE *file;
    file = fopen("data.txt", "r");
    if (file == NULL)
        return -1;

    char line[MAXLL];
    char* token;
    unsigned int score = 0;
    char* ranges[2];
    while(fgets(line, MAXLL, file)) {
        token = strtok(line, ",");
        ranges[0] = token;
        token = strtok(NULL, ",");
        ranges[1] = token;
        printf("%s,%s", ranges[0], ranges[1]);
        int stnd[4];
        for (int i = 0; i < 2; ++i) {
            int start = atoi(strtok(ranges[i], "-"));
            int end = atoi(strtok(NULL, "-"));
            stnd[2*i] = start;
            stnd[2*i+1] = end;
        }
        int yes = 0;
        if (stnd[0] >= stnd[2] && stnd[0] <= stnd[3])
            yes = 1;
        else if (stnd[1] >= stnd[2] && stnd[1] <= stnd[3])
            yes = 1;
        if (stnd[2] >= stnd[0] && stnd[2] <= stnd[1])
            yes = 1;
        else if (stnd[3] >= stnd[0] && stnd[3] <= stnd[1])
            yes = 1;
        score += yes;
        printf("%i\n", yes);
    }
    printf("\nscore %i\n", score);
    fclose(file);
    return 0;
}
