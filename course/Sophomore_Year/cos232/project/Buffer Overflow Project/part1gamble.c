#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void swap (int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}


void shuffle(int buffer[], int n){

    srand ( time(NULL) );

    for (int i = n-1; i > 0; i--) //starts from last element and swaps them 1 by 1.
    {
        int j = rand() % (i+1); //picks a random index from 0 to i

        // Swap buffer[i] with the element at random index
        swap(&buffer[i], &buffer[j]);
    }
}


int main(int argc, char *argv[]) {
    int buffer[] = {-1000, -500, -250, -100, -50, -10, 10, 50, 100, 250, 500, 1000};
    char name[2];
    int randomIndex = rand() % 12;
    int winnings = buffer[randomIndex];
    int sizeOfBuffer = sizeof(buffer) / sizeof(buffer[0]); //because each integer is 4 bytes. We don't want our size to be 48 as in 48 bytes, rather 12 as in 12 integers inside of it.
    srand ( time(NULL) );

    printf("Hello what's your name?");
    scanf("%s", name);
    printf("Result: %d", winnings);
    printf(" dollars!\n");

    shuffle(buffer, sizeOfBuffer);

    return 0;

}

