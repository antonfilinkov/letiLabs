#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define BUFFER_SIZE 1024

int main() {
    FILE *input = fopen("lab4-test-file.txt", "r");
    FILE *output = fopen("output.txt", "w");

    char buffer[BUFFER_SIZE];
    int countO = 0, counto = 0;
    int totalO = 0, totalo = 0;

    while (1) {
        size_t bytesRead = fread(buffer, 1, BUFFER_SIZE, input);
        if (bytesRead == 0) {
            break; //
        }

        for (size_t i = 0; i < bytesRead; i++) {
            if (buffer[i] == 'O') {
                countO++;
            } else if (buffer[i] == 'o') {
                counto++;
            } else if (buffer[i] == '\n') {
                fprintf(output, "O - %d o - %d\n", countO, counto);
                countO = 0;
                counto = 0;
            }
        }
    }

    if (countO > 0 || counto > 0) {
        fprintf(output, "O - %d o - %d\n", countO, counto);
    }

    // Закрываем файлы
    fclose(input);
    fclose(output);

    printf("ура круто готово!\n");
    return 0;
}
