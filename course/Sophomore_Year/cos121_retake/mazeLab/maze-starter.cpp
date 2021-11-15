//------------------------------------------------------------------------
// Starter kit for the maze solver problem. You have permission to use any
// of the code below, or to totally ignore it. -sb
//------------------------------------------------------------------------
#include <unistd.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "conio.h"

using namespace std;
using namespace conio;

using matrix = vector<vector<char>>;

void loadFile(matrix& inputMatrix); //DONE
void displayMatrix(const matrix& outputMatrix); //DONE
void getStart(int& startRow, int& startCol);
bool canEscape(int row, int col, matrix& escapeMatrix); //needs to be recursive
//need a base case and a recursion case. BASE CASES TO CONSIDER: 1. (easiest)if we are at the exit(answer, escaping?: yes) 2. on an object(answer: no) 3. if we are out of bounds(answer: no) 4. Have we been here? (no!)

//RECURSIVE CASES:  1. try north, if yes, then answer(we escaped will be yes), if no, try south, if yes(we escaped), otherwise try east, if yes(we escaped), if no, try west if its a yes (we can escape), if its a no:::then we want to backtrack

//if(we arent on an exit, object, outside the maze, or been here before){
// then try our recursive cases if we'eve tried all recursive cases and all fail then we mark that its a fail with an X




int main() {
    matrix masterMatrix(10, vector<char>(10, ' ')); //creates a matrix of 10x10 characters

    // Call a function that prompts for the file name (e.g., "maze1.txt"),
    // reads the file and loads the maze characters into masterMatrix.
    loadFile(masterMatrix);
    displayMatrix(masterMatrix);

    // Call a function that prompts user for the starting row and column.
    // Reading the row and column from cin also causes a "priming read"
    // so that we can use "cin" as a boolean test for input data happiness. :-)
    int startRow, startCol;
    getStart(startRow, startCol);

    // While the input stream is happy because the last read worked, keep looping.
    while(cin) {
	matrix current = masterMatrix; //creates a new current matrix thats identical to master matrix 
        //masterMatrix is the clean original matrix which we store in current so we can edit/play with current until we check if we can escape from a different spot
	if( canEscape(startRow, startCol, current) ){ 
	    cout << "Happy day" << endl; //does this if canEscape returns true
	} else {
	    cout << "Less happy day" << endl;
	}
    displayMatrix(current);
	getStart(startRow, startCol);
    }

     return 0;
}

// this is the start of this function
void loadFile(matrix& inputMatrix) {//grabs the file and stores that in the matrix we've created
    string fileName;
    cout << "Enter file name: ";
    cin >> fileName;
    ifstream fileIn{fileName}; //tries to open file here

    while (!fileIn) {
        cout << "Couldn't open " << fileName << endl;
        fileIn.close();
        cout << "Enter file name: ";
        cin >> fileName;
        fileIn.open(fileName);
    }
    //we will want to read in the file here through a for loop and store it in the matrix
    for(int row = 0; row< 10; row++){
        for(int col = 0; col < 10; col++){
            char readCharFromFile;
            fileIn >> readCharFromFile;
            inputMatrix[row][col] = readCharFromFile; 
        }
    }
    // Now go ahead and read in all the contents of the maze into
    // inputMatrix
}

// all other functions need to be implemented below...


void displayMatrix(const matrix& outputMatrix){ 
    cout << conio::clrscr();
    cout << conio::gotoRowCol(1, 1); 
    cout << " ";
    for(int i = 0; i < 10; i++){
        cout << i;
    }
    cout << endl;
    for(int row = 0; row< 10; row++){
        cout << row;
        for(int col = 0; col < 10; col++){
            if(outputMatrix[row][col] == '@'){
                cout << conio::fgColor(LIGHT_GREEN);
            }
            if(outputMatrix[row][col] == '$'){
                cout << conio::fgColor(YELLOW);
            }
            if(outputMatrix[row][col] == 'E'){
                cout << conio::fgColor(LIGHT_GREEN);
            }
            if(outputMatrix[row][col] == 'X'){
                cout << conio::fgColor(LIGHT_RED);
            }
            cout << outputMatrix[row][col];
            cout << conio::fgColor(WHITE);
            if(col % 10 == 9){
                cout << endl;
            }
        } 
    }
}
void getStart(int& startRow, int& startCol){
    cout << "Enter starting row: ";
    cin >> startRow;
    cout << "Enter starting column: ";
    cin >> startCol;

}
bool canEscape(int row, int col, matrix& escapeMatrix){
    if(row < 0 || row > 9 || col < 0 || col > 9){
        return false;
    }
    if(escapeMatrix[row][col] == 'E'){
        return true;
    }
    if(escapeMatrix[row][col] == '#'){
        return false;
    }
    if(escapeMatrix[row][col] == '$'){
        return false;
    }
    if(escapeMatrix[row][col] == 'X'){
        return false;
    }


    escapeMatrix[row][col] = '$';
   // escapeMatrix[row][col] = '@';

    displayMatrix(escapeMatrix);
    sleep(1);
    if(canEscape(row-1, col, escapeMatrix)){
        escapeMatrix[row][col] = '@';
        return true;
    }
    else if(canEscape(row+1, col, escapeMatrix)){
        escapeMatrix[row][col] = '@';
        return true;
    }
    else if(canEscape(row, col-1, escapeMatrix)){
        escapeMatrix[row][col] = '@';
        return true;
    }
    else if(canEscape(row, col+1, escapeMatrix)){
        escapeMatrix[row][col] = '@';
        return true;
    }
    else{
        escapeMatrix[row][col] = 'X';
        return false;
    }
    





}
