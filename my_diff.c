#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024

bool is_empty_line(const char *line);

int my_diff(const char *a, const char *b, bool flag_i, bool flag_B) {
    FILE *fileA, *fileB;
    char lineA[MAX_LINE_LENGTH], lineB[MAX_LINE_LENGTH];
    int lineNum = 0;

    fileA = fopen(a, "r");
    fileB = fopen(b, "r");

    while (1) {
        char *resultA = fgets(lineA, sizeof(lineA), fileA);
        char *resultB = fgets(lineB, sizeof(lineB), fileB);

        if (resultA == NULL && resultB == NULL) {
            break; // Both files are at the end
        }

        lineNum++;

        if (resultA == NULL) {
            resultA = "";
        }
        if (resultB == NULL) {
            resultB = "";
        }
        if (flag_i) {
            // Case-insensitive comparison
            if (strcasecmp(resultA, resultB) != 0) {
                printf("%dc%d\n< %s\n---\n> %s\n", lineNum, lineNum, resultA, resultB);
            }
        } 

        if (flag_B) {
            // Case-sensitive comparison
            if (strcmp(resultA, resultB) != 0) {
                if (!(is_empty_line(resultA) && is_empty_line(resultB))) {
                    printf("%dc%d\n< %s\n---\n> %s\n", lineNum, lineNum, resultA, resultB);
                }
            }
        }
    }

    fclose(fileA);
    fclose(fileB);

    return 0; 
}

bool is_empty_line(const char *line) {
    while (*line != '\0') {
    if (!isspace((unsigned char)*line))
      return false;
    line++;
  }
  return true;
}
