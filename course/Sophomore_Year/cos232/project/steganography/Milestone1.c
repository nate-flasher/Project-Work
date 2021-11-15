#include <stdio.h>
//
// Created by nflasher on 9/10/19.
//
int main(int argc, char **argv){
    FILE *fileIn = fopen(argv[1], "r");

    FILE *fileOut = fopen(argv[2], "w");

    char *secretMessage = argv[3];

    fclose(fileIn);
    fclose(fileOut);
    return 0;
}
