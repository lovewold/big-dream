#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main() {

    char i;
    while (scanf("%c", &i) != EOF) {
        switch (i) {

        case 'A':
            printf("Vowel\n");
            break;
        case 'a':
            printf("Vowel\n");
            break;
        case 'E':
            printf("Vowel\n");
            break;
        case 'e':
            printf("Vowel\n");
            break;
        case 'I':
            printf("Vowel\n");
            break;
        case 'i':
            printf("Vowel\n");
            break;
        case 'O':
            printf("Vowel\n");
            break;
        case 'o':
            printf("Vowel\n");
            break;
        case 'U':
            printf("Vowel\n");
            break;
        case 'u':
            printf("Vowel\n");
            break;
        default:
            printf("Consonant\n");
            break;
            


        }
        getchar();



    }


    return 0;
}