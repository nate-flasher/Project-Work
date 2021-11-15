//------------------------------------------------------------------------
// Starter kit for the maze solver problem. You have permission to use any
// of the code below, or to totally ignore it. -sb
//------------------------------------------------------------------------

#include <iostream>
#include <fstream>
#include <string>
#include "conio.h"

using namespace std;
using namespace conio;

void loadFile(char masterMatrix[10][10]);
void getStart(int& startRow, int& startCol);
bool canEscape(int row, int col, char matrix[10][10]);
void copyMatrix(char m1[10][10], char m2[10][10]);
const char MARKED = '!';
const char WALL = '#';
const char EXIT = 'E';
int main()
{
     int startRow, startCol;

     char masterMatrix[10][10];
     char matrix[10][10];

     // Call a function that prompts for the file name (e.g., "maze1.txt"),
     // reads the file and loads the maze characters into masterMatrix.
     loadFile(masterMatrix);

     // Call a function that prompts user for the starting row and column.
     // Reading the row and column from cin also causes a "priming read"
     // so that we can use "cin" as a boolean test for input data happiness. :-)
     getStart(startRow, startCol);

     // While the input stream is happy because the last read worked, keep looping.
     while(cin) {
        // Add your own code to copy the content of masterMatrix to matrix
        copyMatrix(masterMatrix,matrix);
        if( canEscape(startRow, startCol, matrix) ) {
            cout << "Happy day" << endl;
        } else {
            cout << "Less happy day" << endl;
        }
        getStart(startRow, startCol);
     }

     return 0;
}

void loadFile(char masterMatrix[10][10]) {
    string fileName;
    ifstream fileIn;
    cout << "Enter file name: ";
    cin >> fileName;
    fileIn.open( fileName.c_str() );

    while (!fileIn) {
        cout << "Couldn't open " << fileName << endl;
        fileIn.close();
        cout << "Enter file name: ";
        cin >> fileName;
        fileIn.open(fileName.c_str());
    }
    
    // Now go ahead and read in all the contents of the maze into masterMatrix
    for(int r=0; r<10;r++){
        for(int c=0; c<10;c++){
            masterMatrix[r][c]=fileIn.get();
        }
        fileIn.get();
    }
}
    void copyMatrix(char m1[10][10],char m2[10][10]){
        for(int r=0 ;r<10 ;r++ ){
            for(int c=0 ;c<10 ;c++){
                m2[r][c]=m1[r][c];
             }
         }
    }
void getStart(int& startRow, int& startCol){
    cout<<"Enter the start row";
    cin>>startRow;
    cout<<"Enter the start collumn";
    cin>>startCol;
}
bool canEscape(int row, int col, char matrix[10][10]){
    if (row<0|| row>9|| col<0|| col>9){
        return false;
    }
    else if (matrix[row][col] == WALL){
        return false;
    }
    else if (matrix[row][col] == MARKED){
        return false;
    }
    else if (matrix[row][col] == EXIT){
        return true;
    }
    else{ 
        matrix[row][col] = MARKED;

        return canEscape(row-1,col,matrix)||
            canEscape(row+1,col,matrix)||
            canEscape(row,col-1,matrix)||
            canEscape(row,col+1,matrix);
    }
}
