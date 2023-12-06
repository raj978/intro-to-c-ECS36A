/**
 * Created by Rajat Mahesh Gupta on 11/6/23.
 * This program is used to compare 2 phrases input by the user and check whether they are
 * anagrams.
 * It uses 2 functions and
*/
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

/**
 * This is a void function which is used to arrange the character phrase in alphabetical order.
 * It does this by using the traditional swap operation using Bubble sort.
 * @param phrase : It is the phrase input by the user called right after its input.
 */
void ArrangePhrase(char *phrase) {
    char temp;
    int length = strlen(phrase);
    // Sort characters of the string
    for (int i = 0; i < length - 1; i++) {
        for (int j = i + 1; j < length; j++) {
            if (phrase[i] > phrase[j]) {
                temp = phrase[i];
                phrase[i] = phrase[j];
                phrase[j] = temp;
            }
        }
    }
}

/**
 * This is a boolean function that is used to compare the string arrays phraseOne and phraseTwo, it returns true
 * if they are and false if they are not.
 * It does this by first comparing their length, followed by using a simple loop that iterates through each of their
 * elements to check if they are same.
 * @param phraseOne : It is the first string input by the user.
 * @param phraseTwo : It is the second string input by the user.
 * @return
 */

bool ComparePhrases(char *phraseOne, char *phraseTwo) {
    int len1 = strlen(phraseOne);
    int len2 = strlen(phraseTwo);

    if (len1 != len2) {
        return false;
    }

    // Sort characters of both strings
    ArrangePhrase(phraseOne);
    ArrangePhrase(phraseTwo);

    // Compare sorted strings
    for (int i = 0; i < len1; i++) {
        if (phraseOne[i] != phraseTwo[i]) {
            return false;
        }
    }
    return true;
}

/**
 * it is a void function which is used to loop through the character array and store each letter as its lower alphabet
 * back into the variable phrase. It doesn't return any value.
 * The function is called right after the string from the user input is duplicated.
 * @param phrase : It is the string input by the user.
 */
void ToLower(char* phrase){
    for (int i = 0; i < strlen(phrase); ++i){
        char letter = tolower(phrase[i]);
        phrase[i] = letter;
    }
}

int main(void){
    char stringOneO[100];
    char stringTwoO[100];
    char stringOne[100];
    char stringTwo[100];
    bool isAnagram = false; // Default is false so that code is only executed under certain conditions.

    // The 2 printf statements are used to take string inputs from the user.
    printf("Please enter the first word: ");
    scanf(" %s", stringOneO);
    strcpy(stringOne, stringOneO); // Used to duplicate the variable so that the original is unchanged.
    ToLower(stringOne);
    int lenOne = strlen(stringOne);

    printf("Please enter the second word: ");
    scanf(" %s", stringTwoO);
    strcpy(stringTwo, stringTwoO); // Used to duplicate the variable so that the original is unchanged.
    ToLower(stringTwo);
    int lenTwo = strlen(stringTwo);

    ArrangePhrase(stringOne);
    ArrangePhrase(stringTwo);

    if (lenOne == lenTwo){
        isAnagram = ComparePhrases(stringOne, stringTwo);
    }

    if (isAnagram){
        printf("%s is an anagram of %s", stringOneO, stringTwoO);
    } else {
        printf("%s is NOT an anagram of %s", stringOneO, stringTwoO);
    }
}
