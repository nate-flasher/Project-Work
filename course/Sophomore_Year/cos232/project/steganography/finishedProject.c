#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
//
// Created by nflasher on 9/10/19.
//
typedef struct {
    unsigned type;              
    unsigned size;             
    unsigned reserved1;        
    unsigned reserved2;       
    unsigned offset;          
    unsigned dib_header_size; 
    unsigned width_px;         
    unsigned height_px;       
    unsigned num_planes;     
    unsigned bits_per_pixel; 
    unsigned compression;    
    unsigned image_size_bytes;
    unsigned x_resolution_ppm;
    unsigned y_resolution_ppm;
    unsigned num_colors;      
    unsigned important_colors;
} BMPHeader;

typedef struct{
    unsigned char blue;
    unsigned char green;
    unsigned char red;
    unsigned char alpha;
} pixelBytes;

int main(int argc, char **argv){

    if (argc != 4){
        printf("Error, Need an fileIn, fileOut, and msg");
    }

    FILE *fileIn = fopen(argv[1], "r");

    FILE *fileOut = fopen(argv[2], "w");

    char *secretMessage = argv[3];

    int secretMessageLength = 0;
    for(int i = 0; secretMessage[i] != '\0'; i++){
        secretMessageLength++;
    }
    int width = 0;
    int height = 0;
    int startPos = 54;

    fseek(fileIn, 18, SEEK_SET);
    fread(&width, sizeof(int), 1, fileIn);
    fread(&height, sizeof(int), 1, fileIn);

    fseek(fileIn, startPos, SEEK_SET);
    
    printf("Start Position of pixel array: %d\n", startPos);
    printf("Width of Image: %d\n", width);
    printf("Height of Image: %d\n", height);


    pixelBytes pixel; 

    BMPHeader header;
    
    fseek(fileIn, 0, SEEK_SET);
    fread(&header, sizeof(BMPHeader), 1, fileIn);
    fwrite(&header, sizeof(BMPHeader), 1, fileOut);

    fseek(fileIn, 54, SEEK_SET);
    fseek(fileOut, 54, SEEK_SET);
   
    int idx = 0;
    char lastcolor = 'r';
    bool inmsg = true;
    int endcount = 0;

    for(int imageParse = 0 ; imageParse < width*(height*-1) ; imageParse++){
        if(idx+1 < secretMessageLength) {
            if(lastcolor == 'r' && inmsg) { // Start on Blue
                fread(&pixel, 4, 1, fileIn);
                char mbyteB = (secretMessage[idx] & 00000001);
                pixel.blue = pixel.blue >> 1;
                pixel.blue = pixel.blue << 1;
                pixel.blue = pixel.blue | mbyteB;
                char mbyteG = ((secretMessage[idx]>>1) & 00000001);
                pixel.green = pixel.green >> 1;
                pixel.green = pixel.green << 1;
                pixel.green = pixel.green | mbyteG;
                char mbyteR = ((secretMessage[idx]>>1) & 00000001);
                pixel.red = pixel.red >> 1;
                pixel.red = pixel.red << 1;
                pixel.red = pixel.red | mbyteR;
                fwrite(&pixel, sizeof(pixelBytes), 1, fileOut);

                ////

                fread(&pixel, 4, 1, fileIn);
                mbyteB = ((secretMessage[idx]>>1) & 00000001);
                pixel.blue = pixel.blue >> 1;
                pixel.blue = pixel.blue << 1;
                pixel.blue = pixel.blue | mbyteB;
                mbyteG = ((secretMessage[idx]>>1) & 00000001);
                pixel.green = pixel.green >> 1;
                pixel.green = pixel.green << 1;
                pixel.green = pixel.green | mbyteG;
                mbyteR = ((secretMessage[idx]>>1) & 00000001);
                pixel.red = pixel.red >> 1;
                pixel.red = pixel.red << 1;
                pixel.red = pixel.red | mbyteR;
                fwrite(&pixel, sizeof(pixelBytes), 1, fileOut);

                ////

                fread(&pixel, 4, 1, fileIn);
                mbyteB = ((secretMessage[idx]>>1) & 00000001);
                pixel.blue = pixel.blue >> 1;
                pixel.blue = pixel.blue << 1;
                pixel.blue = pixel.blue | mbyteB;
                mbyteG = ((secretMessage[idx]>>1) & 00000001);
                pixel.green = pixel.green >> 1;
                pixel.green = pixel.green << 1;
                pixel.green = pixel.green | mbyteG;
                lastcolor = 'g';
                idx++;

            } else if(lastcolor == 'g' && inmsg) { // Start on Red
                char mbyteR = (secretMessage[idx] & 00000001); 
                pixel.red = pixel.red >> 1;
                pixel.red = pixel.red << 1;
                pixel.red = pixel.red | mbyteR;
                fwrite(&pixel, sizeof(pixelBytes), 1, fileOut);

                ////

                fread(&pixel, 4, 1, fileIn);
                char mbyteB = ((secretMessage[idx]>>1) & 00000001);
                pixel.blue = pixel.blue >> 1;
                pixel.blue = pixel.blue << 1;
                pixel.blue = pixel.blue | mbyteB;
                char mbyteG = ((secretMessage[idx]>>1) & 00000001);
                pixel.green = pixel.green >> 1;
                pixel.green = pixel.green << 1;
                pixel.green = pixel.green | mbyteG;
                pixel.red = pixel.red >> 1;
                pixel.red = pixel.red << 1;
                pixel.red = pixel.red | mbyteR;
                fwrite(&pixel, sizeof(pixelBytes), 1, fileOut);

                ////

                fread(&pixel, 4, 1, fileIn);
                mbyteB = ((secretMessage[idx]>>1) & 00000001);
                pixel.blue = pixel.blue >> 1;
                pixel.blue = pixel.blue << 1;
                pixel.blue = pixel.blue | mbyteB;
                mbyteG = ((secretMessage[idx]>>1) & 00000001);
                pixel.green = pixel.green >> 1;
                pixel.green = pixel.green << 1;
                pixel.green = pixel.green | mbyteG;
                mbyteR = ((secretMessage[idx]>>1) & 00000001);
                pixel.red = pixel.red >> 1;
                pixel.red = pixel.red << 1;
                pixel.red = pixel.red | mbyteR;
                fwrite(&pixel, sizeof(pixelBytes), 1, fileOut);

                ////

                fread(&pixel, 4, 1, fileIn);
                mbyteB = ((secretMessage[idx]>>1) & 00000001);
                pixel.blue = pixel.blue >> 1;
                pixel.blue = pixel.blue << 1;
                pixel.blue = pixel.blue | mbyteB;
                lastcolor = 'b';
                idx++;
            } else if(lastcolor == 'b' && inmsg) { // Start on Green
                char mbyteG = (secretMessage[idx] & 00000001);
                pixel.green = pixel.green >> 1;
                pixel.green = pixel.green << 1;
                pixel.green = pixel.green | mbyteG;
                char mbyteR = ((secretMessage[idx]>>1) & 00000001);
                pixel.red = pixel.red >> 1;
                pixel.red = pixel.red << 1;
                pixel.red = pixel.red | mbyteR;
                fwrite(&pixel, sizeof(pixelBytes), 1, fileOut);

                ////

                fread(&pixel, 4, 1, fileIn);
                char mbyteB = ((secretMessage[idx]>>1) & 00000001);
                pixel.blue = pixel.blue >> 1;
                pixel.blue = pixel.blue << 1;
                pixel.blue = pixel.blue | mbyteB;
                mbyteG = ((secretMessage[idx]>>1) & 00000001);
                pixel.green = pixel.green >> 1;
                pixel.green = pixel.green << 1;
                pixel.green = pixel.green | mbyteG;
                mbyteR = ((secretMessage[idx]>>1) & 00000001);
                pixel.red = pixel.red >> 1;
                pixel.red = pixel.red << 1;
                pixel.red = pixel.red | mbyteR;
                fwrite(&pixel, sizeof(pixelBytes), 1, fileOut);

                ////

                fread(&pixel, 4, 1, fileIn);
                mbyteB = ((secretMessage[idx]>>1) & 00000001);
                pixel.blue = pixel.blue >> 1;
                pixel.blue = pixel.blue << 1;
                pixel.blue = pixel.blue | mbyteB;
                mbyteG = ((secretMessage[idx]>>1) & 00000001);
                pixel.green = pixel.green >> 1;
                pixel.green = pixel.green << 1;
                pixel.green = pixel.green | mbyteG;
                mbyteR = ((secretMessage[idx]>>1) & 00000001);
                pixel.red = pixel.red >> 1;
                pixel.red = pixel.red << 1;
                pixel.red = pixel.red | mbyteR;
                fwrite(&pixel, sizeof(pixelBytes), 1, fileOut);
                lastcolor = 'r';
                idx++;
            }
        } else if (endcount == 0) {
            endcount = 1;
            printf("idx %d\n", idx);
        }
        if(endcount == 1 && lastcolor == 'r') {
            fread(&pixel, 4, 1, fileIn);
            pixel.blue = pixel.blue >> 1;
            pixel.blue = pixel.blue << 1;
            pixel.green = pixel.green >> 1;
            pixel.green = pixel.green << 1;
            pixel.red = pixel.red >> 1;
            pixel.red = pixel.red << 1;
            fwrite(&pixel, sizeof(pixelBytes), 1, fileOut);

            ////

            fread(&pixel, 4, 1, fileIn);
            pixel.blue = pixel.blue >> 1;
            pixel.blue = pixel.blue << 1;
            pixel.green = pixel.green >> 1;
            pixel.green = pixel.green << 1;
            pixel.red = pixel.red >> 1;
            pixel.red = pixel.red << 1;
            fwrite(&pixel, sizeof(pixelBytes), 1, fileOut);

            ////

            fread(&pixel, 4, 1, fileIn);
            pixel.blue = pixel.blue >> 1;
            pixel.blue = pixel.blue << 1;
            pixel.green = pixel.green >> 1;
            pixel.green = pixel.green << 1;
            lastcolor = 'g';
            endcount++;
        } else if(endcount == 1 && lastcolor == 'g') {
            pixel.red = pixel.red >> 1;
            pixel.red = pixel.red << 1;
            fwrite(&pixel, sizeof(pixelBytes), 1, fileOut);

            ////

            fread(&pixel, 4, 1, fileIn);
            pixel.blue = pixel.blue >> 1;
            pixel.blue = pixel.blue << 1;
            pixel.green = pixel.green >> 1;
            pixel.green = pixel.green << 1;
            pixel.red = pixel.red >> 1;
            pixel.red = pixel.red << 1;
            fwrite(&pixel, sizeof(pixelBytes), 1, fileOut);

            ////

            fread(&pixel, 4, 1, fileIn);
            pixel.blue = pixel.blue >> 1;
            pixel.blue = pixel.blue << 1;
            pixel.green = pixel.green >> 1;
            pixel.green = pixel.green << 1;
            pixel.red = pixel.red >> 1;
            pixel.red = pixel.red << 1;
            fwrite(&pixel, sizeof(pixelBytes), 1, fileOut);

            ////

            fread(&pixel, 4, 1, fileIn);
            pixel.blue = pixel.blue >> 1;
            pixel.blue = pixel.blue << 1;
            lastcolor = 'b';
            endcount++;
        } else if(endcount == 1 && lastcolor == 'b') {
            pixel.green = pixel.green >> 1;
            pixel.green = pixel.green << 1;
            pixel.red = pixel.red >> 1;
            pixel.red = pixel.red << 1;
            fwrite(&pixel, sizeof(pixelBytes), 1, fileOut);

            ////

            fread(&pixel, 4, 1, fileIn);
            pixel.blue = pixel.blue >> 1;
            pixel.blue = pixel.blue << 1;
            pixel.green = pixel.green >> 1;
            pixel.green = pixel.green << 1;
            pixel.red = pixel.red >> 1;
            pixel.red = pixel.red << 1;
            fwrite(&pixel, sizeof(pixelBytes), 1, fileOut);

            ////

            fread(&pixel, 4, 1, fileIn);
            pixel.blue = pixel.blue >> 1;
            pixel.blue = pixel.blue << 1;
            pixel.green = pixel.green >> 1;
            pixel.green = pixel.green << 1;
            pixel.red = pixel.red >> 1;
            pixel.red = pixel.red << 1;
            fwrite(&pixel, sizeof(pixelBytes), 1, fileOut);
            lastcolor = 'r';
            endcount++;
        } else {
            fread(&pixel, 4, 1, fileIn);
            fwrite(&pixel, sizeof(pixelBytes), 1, fileOut);
        }
    }
    fclose(fileIn);
    fclose(fileOut);



    return 0;
}


