#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "readFile.h"

int main() {
    // this returns a pointer to the first element in the string array
    char* file = read_file();
    char* files = file;

    int len = 10000;
    int sum_t = 0;
    for (int i = 0; i < len; i++) {
        int pair;

        // * file returns the value at the end of the pointer
        if (*file == ' ') {
        } else if (*file == '\n') {
             pair = 0;
        } else if (*file < 'D') {
            pair = *file - '@';
        } else {
            
            sum_t += *file - 'W';
            int difference = (*file - 'W') - pair;
            if (difference == 0) {
                sum_t += 3;
            } else if (difference == 1 | difference == -2) {
                sum_t += 6;
            } 

        } 

        // pointer counting: this moves the pointer to the next element 
        // in the str array
        file++;

    }
    
    printf("%i\n", sum_t);

    int sum_2 = 0;
    for (int i = 0; i < len; i++) {
        int pair;

        if (*files == ' ') {
        } else if (*files == '\n') {
            pair = 0;
        } else if (*files < 'D') {
            pair = *files - '@';
            //printf("p%i ", pair);

        } else {
            int result_score = (*files - 'X') * 3;
            printf("%i", result_score);
            sum_2 += result_score;
            if ( result_score == 6 ) {
                printf("a ");

                switch (pair) {
                    case 1:
                        sum_2 += 2;
                    case 2:
                        sum_2 += 3;
                    case 3:
                        sum_2 += 1;
                }

            }
            else if (result_score == 3) {
                printf("b ");

                switch (pair) {
                    case 1:
                        sum_2 += 1;
                    case 2:
                        sum_2 += 2;
                    case 3:
                        sum_2 += 3;
                }

            }
            else {
                printf("c ");

                switch (pair) {
                    case 1:
                        sum_2 += 3;
                    case 2:
                        sum_2 += 1;
                    case 3:
                        sum_2 += 2;
                }

            }
        }
    files++;
    }

    printf("%i\n", sum_2); 

}
