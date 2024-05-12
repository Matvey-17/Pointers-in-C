/* Задание 13 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void reverse(char* start, char* end) {
    char temp;
    while (start < end) {
        temp = *start;
        *start++ = *end;
        *end-- = temp;
    }
}

void reverseWords(char* s) {
    char* word_begin = s;
    char* temp = s;

    while (*temp) {
        temp++;
        if (*temp == '\0') {
            reverse(word_begin, temp - 1);
        } else if (*temp == ' ') {
            reverse(word_begin, temp - 1);
            word_begin = temp + 1;
        }
    }
}

int main() {
    char s_old[] = "Hello World";
    char *s = malloc(strlen(s_old) + 1); 
    if (s != NULL) {
        strcpy(s, s_old);
    }
    reverseWords(s);
    printf("Исходная строка - %s\nПеревернутая строка - %s\n", s_old, s);
    free(s);
    return 0;
}



