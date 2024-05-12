/* Задание 12 */

#include <stdio.h>

void replace(char* start, char* end) {
    int count = end - start + 1;
    char* ptr = start + 2;
    while (*(end + 1)) {
        *ptr = *(end + 1);
        ptr++;
        end++;
    }
    *start = '0' + count;
    *ptr = '\0';
}

void replaceWords(char* s) {
    char* word_begin = s;
    char* temp = s;
    while (*temp) {
        if (*temp == *(temp + 1)) {
            temp++;
        }
        else if (temp - word_begin >= 1) {
            replace(word_begin, temp);
            temp = word_begin + 2;
            word_begin = temp;
        }
        else {
            temp++;
            word_begin = temp;
        }
    }

}

int main() {
    char s[] = "baaaaabbbcdvv";
    printf("Исходная строка: %s\n", s);
    replaceWords(s);
    printf("Измененная строка: %s\n", s);
    return 0;
}