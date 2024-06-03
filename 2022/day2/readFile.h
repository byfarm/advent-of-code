#include <stdio.h>
#include <stdlib.h>


char* read_file() {
    FILE *textfile;
    char *text;
    long numbytes;

    textfile = fopen("data.txt", "r");
    if (textfile == NULL) {
        return 0;
    }

    fseek(textfile, 0L, SEEK_END);
    numbytes = ftell(textfile);
    fseek(textfile, 0L, SEEK_SET);

    text = (char*)calloc(numbytes, sizeof(char));
    if (text == NULL) {
        return 0;
    }

    fread(text, sizeof(char), numbytes, textfile);
    fclose(textfile);

    return text;

}
