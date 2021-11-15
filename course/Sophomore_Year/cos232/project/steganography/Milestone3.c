#include <stdio.h>
//
// Created by nflasher on 9/10/19.
//

typedef struct{
    unsigned char blue;
    unsigned char green;
    unsigned char red;
    unsigned char alpha;
} pixelBytes;

void readBitmapMetadata(FILE *file1){
    int width = 0;
    int height = 0;
    int startPos = 54;

    fseek(file1, 18, SEEK_SET);
    fread(&width, sizeof(int), 1, file1);
    fread(&height, sizeof(int), 1, file1);

    fseek(file1, startPos, SEEK_SET);
    
    printf("Start Position of pixel array: %d\n", startPos);
    printf("Width of Image: %d\n", width);
    printf("Height of Image: %d\n", height);


    pixelBytes pixel; 
    for(int imageParse = 0 ; imageParse < width*(height*-1) ; imageParse++){
        fread(&pixel , 4 , 1, file1);
        printf(" Blue: %d" , pixel.blue);
        printf(" Green: %d" , pixel.green);
        printf(" Red: %d\n" , pixel.red);

    }

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

    for( int msgParse = 0 ; secretMessage[msgParse] != '\0' ; msgParse++ ){
        printf("%c\n" , secretMessage[msgParse]);
    }


    return 0;
}


