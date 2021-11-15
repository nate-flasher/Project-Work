#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//fprintf( stderr, ...)
char encrypt(char *typeOfChrypt, int key, int text) {
    if (text >= 65 && text <= 90) {


        if (strcmp(typeOfChrypt, "-e") == 0) {
            if ((text + key) > 90) {
                text = 64 + (key+text)%90;
                printf("%c", text);
                return (char) text;
            } else {
                text = text + key;
                printf("%c", text);
                return (char) text;
            }
        } else {
            if ((text - key) < 65) {
                text = 91 + (key-text)%65;
                printf("%c", text);
                return (char) text;
            } else {
                text = text - key;
                printf("%c", text);
                return (char) text;
            }
        }
    }

    else if (text >= 97 && text <= 122) {

            if (strcmp(typeOfChrypt, "-e") == 0) {
                if((text + key) > 122) {
                    text = 96 + (key+text)%122;
                    printf("%c", text);
                    return (char) text;
                }/*else if((text + key) < 97){
                    text = 123 + (key + text);
                    printf("%c", text);
                    return (char) text;
                }
                */
                else {
                    text = text + key;
                    printf("%c", text);
                    return (char) text;
                }
            } else {
                if((text - key) < 97) {
                    text = 123 + (key-text)%97;
                    printf("%c", text);
                    return (char) text;
                }else {
                    text = text - key;
                    printf("%c", text);
                    return (char) text;
                }
            }
        }

    else {
        return (char) text;
    }
}




int main(int argc, char *argv[]) {
    char *key = argv[2];
    int convertedKey = atoi(key);

    int modulusKey = convertedKey%26;

    char temp[strlen(argv[3])];



    for( int i=0; i < strlen(argv[3]); i++){
        temp[i] = encrypt(argv[1], modulusKey, argv[3][i]);
        //printf("%s\n%s\n", &argv[3][i], temp);
    }
    return 0;
}