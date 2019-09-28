#include <stdio.h>
#include <string.h>
#include <stdlib.h>


char encrypt(char *typeOfChrypt, int key, int text){
    if (text >= 65 && text <= 90) {

        if (strcmp(typeOfChrypt , "-e") == 0) {
            text = text + key;
            return (char) text;
        } else {
            text = text - key;
            return (char) text;
        }
    } else if (text >= 97 && text <= 122) {


        if (strcmp(typeOfChrypt , "-e") == 0) {
            text = text + key;
            return (char) text;
        } else {
            text = text - key;
            return (char) text;
        }



    } else {
        return (char) text;
    }
}


int main(int argc, char *argv[]) {
    char *key = argv[2];
    int convertedKey = atoi(key);
    char temp[strlen(argv[3])];

    for( int i=0; i < strlen(argv[3]); i++){
        temp[i] = encrypt(argv[1], convertedKey, argv[3][i]);
        printf("%s\n%s\n", &argv[3][i], temp);
    }
    return 0;
}