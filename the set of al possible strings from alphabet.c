#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TRUE 1
#define FALSE 0

/* This function sets all the characters of
** a string to the first character of the alphabet
*/
void resetString(char *string, char *alphabet, int size){
    int i;
    for(i = 0; i<size; i++){
        string[i] = alphabet[0];
    }
}

/* This function checks if all the characters of a string
** is the last characters of an alphabet. This is used to
** if the last string in a given length is printed out,
** then increase the length of the string by one.
*/
int checkIfAllLastChar(char *string, char *alphabet, int size){
    int i;
    for(i = 0; i<size; i++){
        if(string[i]!=alphabet[strlen(alphabet)-1]){
            return FALSE;
        }
    }
    return TRUE;
}

#if 0 //This was for testing
void makeAllLastChar(char *string, char *alphabet, int size){
    int i;
    for(i = 0; i<size; i++){
        string[i] = alphabet[strlen(alphabet)-1];
    }
}
#endif // 0

/* The function below doesn't work properly
** and I don't exactly know why.
*/
void PrintAllStrings(char *string, char *alphabet, int size){
    int i;
    int j;
    if(checkIfAllLastChar(string, alphabet, size)==TRUE){
        if(size == 0){
            printf("\n");
            usleep(300000);
            return;
        }
        return;
    }

    for(i = 0; i<size; i++){
        for(j = 0; j<strlen(alphabet); j++){
            string[i] = alphabet[j];
            printf("%c", string[0]);
            PrintAllStrings(string+1, alphabet, size-1);
        }
    }
}

int main(void){
    char alphabet[2] = {'a', 'b'};
    char *string;
    int size = 1;

    string = (char *)malloc(sizeof(char));

    for(;;){
        resetString(string, alphabet, size);
        PrintAllStrings(string, alphabet, size);
        size++;
        string = realloc(string, size);
    }
}

