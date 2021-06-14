#include <stdio.h>
#include <stdlib.h>

#define ALPH_SIZE 2
/*
** A lot of improvements could be made such as
** getting the alphabet at the runtime and not
** using the word counter as a global variable.
*/

char alphabet[ALPH_SIZE] = {'0', '1'};

void initiateWord(char *word, int length){
    int i;
    for(i = 0; i < length; i++){
        word[i] = '\0';
    }
    return;
}

/*
** char *word -> Array itself
** int length -> Length of the array
** int start  -> Current index the function is working on
*/
unsigned __int64 word_count = 0;
void printAll(char *word, int length, int start){
    if(start == length){
        printf("%s\n", word);
        word_count++;
        return;
    }
    int i;
    for(i = 0; i < ALPH_SIZE; i++){
        word[start] = alphabet[i];
        printAll(word, length, start+1);
    }
}

int main(void){
    int max_lenght;
    printf("What is the max length of a word? ");
    scanf("%d", &max_lenght);
    max_lenght++;

    char *word;
    word = (char *)malloc(sizeof(char)*(max_lenght));
    initiateWord(word, max_lenght);

    int i;
    for(i = 1; i < max_lenght; i++){
        printAll(word, i, 0);
    }

    printf("Total word count: %d", word_count);

    return 0;
}
