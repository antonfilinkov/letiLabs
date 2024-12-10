#include <stdio.h>
#include <string.h>
#include <stdbool.h>


bool cSymbols(const char *input, const char *cChars) {
    while (*input) {
        if (strchr(cChars, *input)) {
            return true;
        }
        input++;
    }
    return false;
}
char *processInput(const char *input, const char *cChars) {
    if (cSymbols(input, cChars)) {
        return ""; 
    }
    return (char *)input; 
}
int main() {
    const char cChars[] = "!@#$%^&*";  //массив запреток
    char input[100];
    printf("Введите строку: ");
    fgets(input, sizeof(input), stdin);
//-----------------------------------------------------------------------------------------------------------------
    while (cSymbols(input, cChars))
    {
        printf("Введите строку: ");
        fgets(input, sizeof(input), stdin);

        // удаление символа у новой строки
        input[strcspn(input, "\n")] = 0;

        printf("Результат: %s\n", processInput(input, cChars));
    }

    return 0;
}
