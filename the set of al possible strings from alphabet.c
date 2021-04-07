#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){
    char    alphabet[2] = {'a', 'b'};
    char    current_char;
    int const     length_of_alphabet = 2;
    int     currently_how_many_chars_on_screen = 1;

    while(1){
        int     i, j;

        for(i = 0; i<currently_how_many_chars_on_screen; i++){
            for(j = 0; j<length_of_alphabet; j++){
                printf("%c", alphabet[j]);
                //selamın aleyküm
            }
        }
        printf("\n");
        currently_how_many_chars_on_screen++;
    printf("%d", currently_how_many_chars_on_screen);
    sleep(1);
    }

    return EXIT_SUCCESS;
}
