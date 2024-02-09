#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char input[1000];
    char max_word[1000];
    int max_len = 0;

    scanf("%[^\n]", &input);

    char* new_str = strtok(input, " \t");

    while (new_str != NULL) {
        printf("%s\n", new_str);
        if (max_len <= strlen(new_str)) {
            max_len = strlen(new_str);
            strcpy(max_word, new_str);
        }
        new_str = strtok(NULL, " \t");
    }

    printf("\n");
    printf("%s\n", max_word);



    return 0;
}