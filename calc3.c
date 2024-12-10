#include <stdio.h>
#include <conio.h>

int main() {
    char pointer[] = " <---";
    long a = 0, b = 0;
    int fa = 0, fb = 0;  // переменные для проверки, введены ли числа A и B (они 1 или 0)
    char op = '?';       // штука, которая будет отображаться в строке статуса
    long result = 0;     // Промежуточного результата
    short int mind = -32768, maxd = 32767;
    int selected = 1;    // Переменная для выбранного пункта

    // Функция для меню
    void display_menu(int selected, char *status) {
        printf("\033c");
        printf("1) Ввод A%s\n", selected == 1 ? pointer : "");
        printf("2) Ввод B%s\n", selected == 2 ? pointer : "");
        printf("3) Сложение%s\n", selected == 3 ? pointer : "");
        printf("4) Вычитание%s\n", selected == 4 ? pointer : "");
        printf("5) Умножение%s\n", selected == 5 ? pointer : "");
        printf("6) Деление%s\n", selected == 6 ? pointer : "");
        printf("7) Выход%s\n", selected == 7 ? pointer : "");
        printf("\nПромежуточный результат: %s\n", status);
    }

    // Строка для результата
    char status[50] = "A ? B = result";

    int key;
    do {
        display_menu(selected, status);
        key = getch();

        if (key == 72) {  // вверх
            selected = (selected == 1) ? 7 : selected - 1;
        } else if (key == 80) {  // вниз
            selected = (selected == 7) ? 1 : selected + 1;
        } else if (key == 13) {  // энтер
            switch (selected) {
                case 1: {
                    display_menu(1, status);
                    printf("Введите A: ");
                    scanf("%ld", &a);
                    if (a < mind || a > maxd) {
                        printf("Нет! Введите число в диапазоне {-32768, 32767}\n");
                    } else {
                        fa = 1;
                        snprintf(status, sizeof(status), "%ld %c %ld = result", a, op, fb ? b : 0);
                    }
                    getch();
                    break;
                }
                case 2: {
                    display_menu(2, status);
                    printf("Введите B: ");
                    scanf("%ld", &b);
                    if (b < mind || b > maxd) {
                        printf("Нет! Введите число в диапазоне {-32768, 32767}\n");
                    } else {
                        fb = 1;
                        snprintf(status, sizeof(status), "%ld %c %ld = result", fa ? a : 0, op, b);
                    }
                    getch();
                    break;
                }
                case 3: {
                    display_menu(3, status);
                    if (fa && fb) {
                        result = a + b;
                        op = '+';
                        snprintf(status, sizeof(status), "%ld %c %ld = %ld", a, op, b, result);
                    } else {
                        printf("Определите оба числа A и B!\n");
                    }
                    getch();
                    break;
                }
                case 4: {
                    display_menu(4, status);
                    if (fa && fb) {
                        result = a - b;
                        op = '-';
                        snprintf(status, sizeof(status), "%ld %c %ld = %ld", a, op, b, result);
                    } else {
                        printf("Определите оба числа A и B!\n");
                    }
                    getch();
                    break;
                }
                case 5: {
                    display_menu(5, status);
                    if (fa && fb) {
                        result = a * b;
                        op = '*';
                        snprintf(status, sizeof(status), "%ld %c %ld = %ld", a, op, b, result);
                    } else {
                        printf("Определите оба числа A и B!\n");
                    }
                    getch();
                    break;
                }
                case 6: {
                    display_menu(6, status);
                    if (fb && b == 0) {
                        printf("Нет! Делитель не может быть равен 0\n");
                    } else if (fa && fb) {
                        result = a / b;
                        op = '/';
                        snprintf(status, sizeof(status), "%ld %c %ld = %ld", a, op, b, result);
                    } else {
                        printf("Определите оба числа A и B!\n");
                    }
                    getch();
                    break;
                }
                case 7:
                    display_menu(7, status);
                    printf("Выход из программы.\n");
                    break;
            }
        }
    } while (selected != 7 || key != 13);

    return 0;
}
