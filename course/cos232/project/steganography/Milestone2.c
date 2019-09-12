#include <stdio.h>
//
// Created by nflasher on 9/10/19.
//

void readBitmapMetadata(FILE *file1){
    int width = 0;
    int height = 0;
    int startPos = 0;

    fseek(file1, 18, SEEK_SET);
    fread(&width, sizeof(int), 1, file1);
    fread(&height, sizeof(int), 1, file1);

    fseek(file1, 0L, SEEK_SET);
    
    startPos = fgetc(file1);
    printf("Start Position of pixel array: %d\n", startPos);
    printf("Width of Image: %d\n", width);
    printf("Height of Image: %d\n", height);

}

int main(int argc, char **argv){

    if (argc != 4){
        printf("Error, Need an infile, outfile, and msg");
    }

    FILE *fileIn = fopen(argv[1], "r");

    FILE *fileOut = fopen(argv[2], "w");

    char *secretMessage = argv[3];

    readBitmapMetadata(fileIn);

    fclose(fileIn);
    fclose(fileOut);
    return 0;
}


