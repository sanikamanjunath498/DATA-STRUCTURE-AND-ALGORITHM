#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* intToRoman(int num) {
    // Arrays representing the values and their corresponding Roman symbols
    int values[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    char* symbols[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    
    // Allocate memory for the resulting Roman numeral string 
    char* result = (char*)malloc(20 * sizeof(char));
    result[0] = '\0'; // Initialize as an empty string
    
    for (int i = 0; i < 13; i++) {
        while (num >= values[i]) {
            strcat(result, symbols[i]);
            num -= values[i];
        }
    }
    
    return result;
} // <-- Make sure this closing brace is here!
