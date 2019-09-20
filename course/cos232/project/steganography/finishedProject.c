#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
//
// Created by nflasher on 9/10/19.
//
typedef struct {
    unsigned type;              // Magic identifier: 0x4d42
    unsigned size;              // File size in bytes
    unsigned reserved1;         // Not used
    unsigned reserved2;         // Not used
    unsigned offset;            // Offset to image data in bytes from beginning of file
    unsigned dib_header_size;   // DIB Header size in bytes
    unsigned width_px;          // Width of the image
    unsigned height_px;         // Height of image
    unsigned num_planes;        // Number of color planes
    unsigned bits_per_pixel;    // Bits per pixel
    unsigned compression;       // Compression type
    unsigned image_size_bytes;  // Image size in bytes
    unsigned x_resolution_ppm;  // Pixels per meter
    unsigned y_resolution_ppm;  // Pixels per meter
    unsigned num_colors;        // Number of colors
    unsigned important_colors;  // Important colors
} BMPHeader;

typedef struct{
    unsigned char blue;
    unsigned char green;
    unsigned char red;
    unsigned char alpha;
} pixelBytes;

/*
void readBitmapMetadata(FILE *file1, FILE *file2){
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

    BMPHeader header;
    
    fseek(file1, 0, SEEK_SET);
    fread(&header, sizeof(BMPHeader), 1, file1);
    fwrite(&header, sizeof(BMPHeader), 1, file2);

    fseek(file1, 54, SEEK_SET);
    fseek(file2, 54, SEEK_SET);

    for(int imageParse = 0 ; imageParse < width*(height*-1) ; imageParse++){
        fread(&pixel , 4 , 1, file1);
       // printf(" Blue: %d" , pixel.blue);
       // printf(" Green: %d" , pixel.green);
     //   printf(" Red: %d\n" , pixel.red);
        fwrite(&pixel, sizeof(pixelBytes), 1, file2);
    }
    


}
*/
int main(int argc, char **argv){

    if (argc != 4){
        printf("Error, Need an fileIn, fileOut, and msg");
    }

    FILE *fileIn = fopen(argv[1], "r");

    FILE *fileOut = fopen(argv[2], "w");

    char *secretMessage = argv[3];

   // readBitmapMetadata(fileIn, fileOut);
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
    //int count = 1;
    char lastcolor = 'r';
    bool inmsg = true;
    int endcount = 0;

    for(int imageParse = 0 ; imageParse < width*(height*-1) ; imageParse++){
	/*
        fread(&d, 1, 1, fileIn);
        printf("blue %d\n", d);
        mbyte = (secretMessage[idx] & 00000001);
        d = d >> 1;
        d = d << 1;
        d = d | mbyte;
        printf("blue %d\n", d);
        fwrite(&d, sizeof(char), 1, fileOut);
        fread(&d, 1, 1, fileIn);
        printf("green %d\n", d);
        mbyte = ((secretMessage[idx]>>1) & 00000001);
        d = d >> 1;
        d = d << 1;
        d = d | mbyte;
        printf("green %d\n", d);
        fwrite(&d, sizeof(char), 1, fileOut);
        fread(&d, 1, 1, fileIn);
        printf("red %d\n", d);
        mbyte = ((secretMessage[idx]) & 00000001);
        d = d >> 1;
        d = d << 1;
        d = d | mbyte;
        printf("red %d\n", d);
        fwrite(&d, sizeof(char), 1, fileOut);
        fread(&d, 1, 1, fileIn);
        fwrite(&d, sizeof(char), 1, fileOut);
        break;
        */
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
                //////////////
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
                ////////////
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
                //printf("msg: %c\n", secretMessage[idx]);
                //printf("Finished %c\n", secretMessage[idx]);
            } else if(lastcolor == 'g' && inmsg) { // Start on Red
                char mbyteR = (secretMessage[idx] & 00000001); 
                pixel.red = pixel.red >> 1;
                pixel.red = pixel.red << 1;
                pixel.red = pixel.red | mbyteR;
                fwrite(&pixel, sizeof(pixelBytes), 1, fileOut);
                ////////////
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
                //////////////
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
                //////////////
                fread(&pixel, 4, 1, fileIn);
                mbyteB = ((secretMessage[idx]>>1) & 00000001);
                pixel.blue = pixel.blue >> 1;
                pixel.blue = pixel.blue << 1;
                pixel.blue = pixel.blue | mbyteB;
                lastcolor = 'b';
                idx++;
                //printf("msg: %c\n", secretMessage[idx]);
                //printf("Finished %c\n", secretMessage[idx]);
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
                //////////////
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
                //////////////
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
                //printf("msg: %c\n", secretMessage[idx]);
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
            //////////////
            fread(&pixel, 4, 1, fileIn);
            pixel.blue = pixel.blue >> 1;
            pixel.blue = pixel.blue << 1;
            pixel.green = pixel.green >> 1;
            pixel.green = pixel.green << 1;
            pixel.red = pixel.red >> 1;
            pixel.red = pixel.red << 1;
            fwrite(&pixel, sizeof(pixelBytes), 1, fileOut);
            ////////////
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
            ////////////
            fread(&pixel, 4, 1, fileIn);
            pixel.blue = pixel.blue >> 1;
            pixel.blue = pixel.blue << 1;
            pixel.green = pixel.green >> 1;
            pixel.green = pixel.green << 1;
            pixel.red = pixel.red >> 1;
            pixel.red = pixel.red << 1;
            fwrite(&pixel, sizeof(pixelBytes), 1, fileOut);
            //////////////
            fread(&pixel, 4, 1, fileIn);
            pixel.blue = pixel.blue >> 1;
            pixel.blue = pixel.blue << 1;
            pixel.green = pixel.green >> 1;
            pixel.green = pixel.green << 1;
            pixel.red = pixel.red >> 1;
            pixel.red = pixel.red << 1;
            fwrite(&pixel, sizeof(pixelBytes), 1, fileOut);
            //////////////
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
            //////////////
            fread(&pixel, 4, 1, fileIn);
            pixel.blue = pixel.blue >> 1;
            pixel.blue = pixel.blue << 1;
            pixel.green = pixel.green >> 1;
            pixel.green = pixel.green << 1;
            pixel.red = pixel.red >> 1;
            pixel.red = pixel.red << 1;
            fwrite(&pixel, sizeof(pixelBytes), 1, fileOut);
            //////////////
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


