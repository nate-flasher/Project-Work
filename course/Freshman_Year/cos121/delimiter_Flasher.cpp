/**
eckDelimiters.cpp -- a program that checks for properly balanced 
 * delimiters and marks the problems using the caret ('^') symbol.
 * @author PUT YOUR NAME HERE!
 * @date PUT TODAY'S DATE HERE!
 */

//-----------------------------------------------------------------
// All the includes go here
//-----------------------------------------------------------------
#include <iostream>
#include <string>
#include <cstring>
#include <stack>
#include <iomanip>         

//-----------------------------------------------------------------
// Prototypes. If you write other functions, put the prototypes
// (function signatures) here.
//-----------------------------------------------------------------
void checkDelimiters( char line[] );

//-----------------------------------------------------------------
// Defined constants
//-----------------------------------------------------------------
const int LINESIZE = 1024;

//-----------------------------------------------------------------
// Global variables
//-----------------------------------------------------------------
bool verbose = false;

using namespace std;

int main( int argc, char *argv[] ) {
   char line[LINESIZE];
 
   if( argc == 2 && strcmp( argv[1], "-v" ) == 0) {
      verbose = true;
   }

   if( verbose ) {
      cout << "This program checks a line of characters for balanced delimiter." << endl
  	   << "{ }, [ ], < >, ( )" << endl
	   << "Enter a line (<ENTER> to quit): ";
   }

   // Loop, processing lines one at a time, until reach EOF or empty string.
   cin.getline(line, sizeof line, '\n');

   while( cin && strlen(line) > 0 ) {
      checkDelimiters( line );
      if( verbose ) {
	 cout << "Enter a line (<ENTER> to quit): ";
      }
      cin.getline(line, sizeof line, '\n');
   }

   return 0;
}


//-----------------------------------------------------------------

/******************************************************************
 * Your code below. If you want extra functions, great. Write the code
 * below and add the function prototypes (signatures) with the other
 * function prototype for 'checkDelimiters' at the top of this file.
 ******************************************************************/
void checkDelimiters( char line[] ) {
	stack <char> delims;
    stack <int> counter;
	for(int i=0; line[i]!=char(0);++i){
	switch(line[i]){
	    case '(':
	    case '[':
	    case '<':
	    case '{':
            delims.push(line[i]);
            counter.push(i);
            break;
        case')':
            if (delims.empty()){
                cout<<"Error"<<endl;
                cout<<line<<endl;
                cout<<setw(i+1)<<"^"<<endl;
            }
            else if (delims.top() != '('){
                cout<<"Error"<<endl;
                cout<<line<<endl;
                cout<<setw(counter.top()+1)<<"^"<<setw(i-counter.top())<<"^"<<endl;
                return;
            }
            else{
                delims.pop();
                counter.pop();
            }
            break;


		case']':
            if (delims.empty()){
                cout<<"Error"<<endl;
                cout<<line<<endl;
                cout<<setw(i+1)<<"^"<<endl;
            }
            else if (delims.top() != '['){
                cout<<"Error"<<endl;
                cout<<line<<endl;
                cout<<setw(counter.top()+1)<<"^"<<setw(i-counter.top())<<"^"<<endl;
                return;
            }
            else{
                delims.pop();
                counter.pop();
            }
            break;

		case'>':
            if (delims.empty()){
                cout<<"Error"<<endl;
                cout<<line<<endl;
                cout<<setw(i+1)<<"^"<<endl;
            }
            else if (delims.top() != '<'){
                cout<<"Error"<<endl;
                cout<<line<<endl;
                cout<<setw(counter.top()+1)<<"^"<<setw(i-counter.top())<<"^"<<endl;
                return;
            }
            else{
                delims.pop();
                counter.pop();
            }
            break;
		

		case'}':
            if (delims.empty()){
                cout<<"Error"<<endl;
                cout<<line<<endl;
                cout<<setw(i+1)<<"^"<<endl;
            }
            else if (delims.top() != '{'){
                cout<<"Error"<<endl;
                cout<<line<<endl;
                cout<<setw(counter.top()+1)<<"^"<<setw(i-counter.top())<<"^"<<endl;
                return;
            }
            else{
                delims.pop();
                counter.pop();
            }
            break;

	}
}
    if (!delims.empty()){
        cout<<"Error"<<endl;
        cout<<line<<endl;
        cout<<setw(counter.top()+1)<<"^"<<endl;
    }
}
