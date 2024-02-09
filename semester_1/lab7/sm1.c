#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define MAX_LINES 30
#define MAX_NUMBERS 20
#define MAX_INPUT_LENGTH 1024


void generateRandomFile(const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }
    srand(21);

    int numLines = rand() % (MAX_LINES + 1);
    for (int i = 0; i < numLines; ++i) {
        int numNumbers = rand() % (MAX_NUMBERS + 1);
        for (int j = 0; j < numNumbers; ++j) {
            fprintf(file, "%d ", rand() % 100);
        }
        fprintf(file, "\n");
    }

    fclose(file);
}

char* getUserInput() {
    char* input = NULL;
    char buffer[MAX_INPUT_LENGTH];

    while (1) {
        if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
            perror("Ошибка ввода");
            exit(EXIT_FAILURE);
        }

        size_t len = strlen(buffer);
        if (len > 0 && buffer[len - 1] == '\n') {
            buffer[len - 1] = '\0';
        }

        if (strlen(buffer) == 0) {
            break;
        }

        size_t newLen = (input ? strlen(input) : 0) + strlen(buffer) + 1;
        input = realloc(input, newLen);
        if (input == NULL) {
            perror("Ошибка выделения памяти");
            exit(EXIT_FAILURE);
        }
        strcat(input, buffer);
        strcat(input, "\n");
    }

    return input;
}

void findMinSumLine(const char *content) {
    int minSum = INT_MAX;
    size_t lineNumber = 0;

    int *minSumLines = NULL;
    size_t minSumLinesCount = 0;

    char* inputCopy = strdup(content);

    char* savePtr;
    char* line = strtok_r(inputCopy, "\n", &savePtr);

    while (line != NULL) {
        char* lineCopy = strdup(line);

        int sum = 0;
        char* token = strtok(lineCopy, " ");

        while (token != NULL) {
            sum += atoi(token);
            token = strtok(NULL, " ");
        }

        free(lineCopy);

        if (sum < minSum) {
            minSum = sum;
            free(minSumLines);
            minSumLines = NULL;
            minSumLinesCount = 0;
        }

        if (sum == minSum) {
            minSumLinesCount++;
            minSumLines = realloc(minSumLines, minSumLinesCount * sizeof(int));
            minSumLines[minSumLinesCount - 1] = lineNumber;
        }

        lineNumber++;
        line = strtok_r(NULL, "\n", &savePtr);
    }

    free(inputCopy);

    for (size_t i = 0; i < minSumLinesCount; ++i) {
        if (i == 0) {
            printf("%d", minSumLines[i] + 1);
        } else {
            printf("% d", minSumLines[i] + 1);
        }
    }
    printf("\n");

    free(minSumLines);
}

void generateHistogram(const char *content) {
    int digitCounts[10] = {0};
    int totalDigits[10] = {0};

    char* token;
    char* inputCopy = strdup(content);

    char* savePtrOuter;
    char* line = strtok_r(inputCopy, "\n", &savePtrOuter);

    while (line != NULL) {
        char* savePtrInner;
        token = strtok_r(line, " ", &savePtrInner);

        while (token != NULL) {
            int num = atoi(token);


            if (num == 0) {
                digitCounts[num]++;
                totalDigits[num]++;
            } else {
                while (num > 0) {
                    digitCounts[num % 10]++;
                    totalDigits[num % 10]++;
                    num /= 10;
                }
            }


            token = strtok_r(NULL, " ", &savePtrInner);
        }

        line = strtok_r(NULL, "\n", &savePtrOuter);
    }

    free(inputCopy);

    for (int i = 0; i < 10; ++i) {
        printf("%d ", i);

        int stars = digitCounts[i] / 3;
        int remainder = digitCounts[i] % 3;

        for (int j = 0; j < stars; ++j) {
            printf("*");
        }

        if (remainder == 2) {
            printf("*");
        }

        printf(" %d", totalDigits[i]);

        printf("\n");
    }
}

int main() {
    const char *filename = "random_file.txt";

    generateRandomFile(filename);
    char* userInput = getUserInput();

    findMinSumLine(userInput);
    printf("\n");
    generateHistogram(userInput);

    free(userInput);

    return 0;
}