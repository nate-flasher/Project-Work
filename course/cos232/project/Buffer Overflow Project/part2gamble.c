#include <stdio.h>

void win1000(){

    printf("You win 1000 dollars!");
    return;
}


void lose100(){

    printf("You lose 100 dollars!");
    return;
}

void getname(){
    char name[16];
    printf("Hello! What's your name?");
    scanf("%s", name);
}

int main(int argc, char *argv[]) {
    printf("%p\n", win1000);
    getname();
    lose100();
    //int answer;
    /*printf("Alrighty then, well is a game where you either win $1000 or $100 dollars or lose $1000 or $100 dollars. Pick a number: 1, 2, 3, or 4 to receive your fate! : ");
    scanf("%d", &answer);
    if(answer < 1 || answer > 4){
        exit(0);
    }
    srand ( time(NULL) );
    answer = rand() % 4;

        if(answer == 0){
            lose100();
        }
        else if(answer == 1) {
            lose1000();
        }
        else if(answer == 2){
            win100();
        }
        else{
            win1000();
        }*/


    return 0;

}
