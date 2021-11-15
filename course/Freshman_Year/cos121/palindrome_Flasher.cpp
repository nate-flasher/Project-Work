// Nate Flasher
//02/14/19

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

string reverse(const string word);
void swap(char &v1, char &v2);
bool isPal(const string word);

/** 
 * The functions reverse, swap, and isPal are defined before the main
 * function so the compiler knows how they behave before main refers to
 * those functions. These "predefinitions" are called "prototypes".
 *
 * reverse takes a string, for this program a word, and rearranges its
 * characters from last to first, then returns the changed string. This is
 * done by starting at the beginning and end of the string and switching
 * characters until the middle is reached.
 */

string reverse(const string word) {

    //Initialize an integer called start and set it equal to zero
    int start = 0;


    int end = word.length() - 1;

    string temp = word;

    //This loop switches characters in the string, starting at the ends and
    //stoping when the middle of the string is reached or passed.
    while (start < end) {
       swap(temp[start], temp[end]);
       start++;
       end--;
    }
    return temp;
}



/**
 * swap takes two character variables and switches their contents. The "&" before
 * "v1" and "v2" means they are passed by reference. You will learn more about this
 * later, but it means that the changes swap makes will also be in effect outside
 * the function.
 */

void swap(char &v1, char &v2) {

    //Switch the characters in "v1" and "v2". You will need a temporary holder or else
    //both variables will contain the same character. No return is needed.
    char tempChar = v1;
v1 = v2;
v2 = tempChar;



}


/**
 * isPal takes a string and compares it to itself reversed. If they are the same, it
 * is a palindrome. The expression "word == reverse(word)" will evaluate to true or
 * false and then be returned.
 */

bool isPal(const string word) {
    return (word == reverse(word));
}


//============================================================================

/*
 * main opens a text file based on user prompting and checks if the words in it are
 * palindromes, displaying its conclusions. Program returns "0" to show it ran properly.
 */

int main() {
    
    //add code to declare and initialize a string called "palindromeStr" and another called "fileName"
    string palindromeStr = "";
    string fileName = "";



    //prompt user for a file name and store its name in the string "fileName"
    cout << "Please enter a filename: ";
    cin >> fileName;




    // Create an ifstream (input file stream) object named "words". 
    ifstream words;
    



    // Then tell the words object to open the file held in the fileName variable. 
    // Note: When telling words to open the file name specified in the fileName variable,
    // you must type "fileName.c_str()" instead of just "fileName".
    words.open(fileName.c_str());



    // Make sure the file opened properly; the code below reports and stops program if not open.
    // cerr is the Console ERRor stream.

    if (! words.is_open()) {
	cerr << "error opening file" << endl;
	return 1;
    }


    // Do a priming read. Without a priming read, the program could enter the while
    // loop the first time with the file stream in error.
    getline(words, palindromeStr);


    // While the stream is not erring and its not the end of the file
    while (words)
    {
	if (isPal(palindromeStr)) {
            cout << "\"" << palindromeStr + "\" is a palindrome.";
        } else {
            cout << "\"" << palindromeStr + "\" is not a palindrome.";
        }
	cout << endl;
	getline(words, palindromeStr);
    }

    //close the file
    words.close();

    return 0;
}
