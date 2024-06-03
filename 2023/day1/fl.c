#include <stdio.h>
#include <stdlib.h>

int linelen(char*);
int summm(char* s);

int main() {
    FILE *file;
    file = fopen("data", "r");
    if (file == NULL)
        return -1;

    int sum = 0;
    char str[1000];
    while (fgets(str, 1000, file)) {
        char output[3];
        printf("string %s\n", str);
        int len = linelen(str);
        printf("len %i\n", len);
        output[2] = '\0';
        output[0] = str[0];
        output[1] = str[len-1];
        printf("str1 %s\n", output);
        for (int i = 0; i < 2; ++i)
            if (output[i] > '9') {
                printf("%c\n", output[i]);
                printf("%i\n", output[i]);
                output[i] -= ('a');
                printf("%i\n", output[i]);
                output[i] %= 10;
                printf("%i\n", output[i]);
                output[i] += '0';
                printf("%i\n", output[i]);
            }
        printf("str %s\n", output);
        int val = atoi(output);
        printf("val %i\n\n", val);
        sum += val;
    }
    printf("%i\n", sum);
    return 0;
}

int linelen(char* s) {
    int i;
    for (i = 0; s[i] != '\n'; i++);
    return i;
}

int summm(char* s) {
    int sum = 0;
    for (int i = 0; s[i] != 0; ++i)
        sum += s[i];
    return sum;
}



