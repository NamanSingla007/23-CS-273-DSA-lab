#include <stdio.h>
#include <string.h>

int isPalindrome(char str[]) {
    int left = 0;
    int right = strlen(str) - 1;
    while (left < right) {
        if (str[left] != str[right]) {
            return 0; // Not a palindrome
        }
        ++left;
        --right;
    }
    return 1; // Palindrome
}

int main() {
    char input[100];
    printf("Enter a string: ");
    scanf("%s", input);
    if (isPalindrome(input)) {
        printf("Palindrome\n");
    } else {
        printf("Not a palindrome\n");
    }
    return 0;
}
