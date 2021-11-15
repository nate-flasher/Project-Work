//--------------------------------------------------------------------
//
//  Laboratory 3                                           test5.cpp
// 
//  Test program for the operations in the List ADT
//
//--------------------------------------------------------------------

#include <iostream>
#include <cctype>

#include "config.h"
#include "ListArray.cpp"

using namespace std;

void print_help();

int  main()
{
#if LAB5_TEST1
    List<int> testList;    // Test list
    int testData;          // List data item
#else
    List<char> testList;   // Test list
    char testData;         // List data item
#endif
    char cmd;              // Input command

    print_help();

    do
    {
        testList.showStructure();                     // Output list

        cout << endl << "Command: ";                  // Read command
        cin >> cmd;
	cmd = toupper(cmd);                           // Only use upper-case

        if ( cmd == '+'  ||  cmd == '='  ||  cmd == '#' )
           cin >> testData;

        try {
        switch ( cmd )
        {
          case 'H' :
               print_help();
               break;

          case '+' :                                  // Add
               cout << "Add " << testData << endl;
               testList.add(testData);
               break;

          case '-' :                                  // remove
               cout << "Remove the data item marked by the cursor"
                    << endl;
               testList.remove();
               break;

          case '=' :                                  // replace
               cout << "Replace the data item marked by the cursor "
                    << "with " << testData << endl;
               testList.replace(testData);
               break;

          case '@' :                                  // getCursor
               cout << "Element marked by the cursor is "
                    << testList.getCursor() << endl;
               break;

          case '<' :                                  // gotoBeginning
               testList.gotoBeginning();
               cout << "Go to the beginning of the list" << endl;
               break;

          case '>' :                                  // gotoEnd
               testList.gotoEnd();
               cout << "Go to the end of the list" << endl;
               break;

          case 'N' :                                  // gotoNext
               if ( testList.gotoNext() )
                  cout << "Go to the next data item" << endl;
               else
                  cout << "Failed -- either at the end of the list "
                       << "or the list is empty" << endl;
               break;

          case 'P' :                                  // gotoPrior
               if ( testList.gotoPrior() )
                  cout << "Go to the prior data item" << endl;
               else
                  cout << "Failed -- either at the beginning of the "
                       << "list or the list is empty" << endl;
               break;

          case 'C' :                                  // clear
               cout << "Clear the list" << endl;
               testList.clear();
               break;

          case 'E' :                                  // empty
               if ( testList.isEmpty() )
                  cout << "List is empty" << endl;
               else
                  cout << "List is NOT empty" << endl;
               break;

          case 'F' :                                  // full
               if ( testList.isFull() )
                  cout << "List is full" << endl;
               else
                  cout << "List is NOT full" << endl;
               break;

#if LAB5_TEST2
          case 'M' :                              // In-lab Exercise 2
               cout << "Move the data item marked by the cursor to the "
                    << "beginning of the list" << endl;
               testList.moveToBeginning();
               break;
#endif

#if LAB5_TEST3
          case '#' :                              // In-lab Exercise 3
               cout << "Add " << testData << " before the "
                    << "cursor" << endl;
               testList.insertBefore(testData);
               break;
#endif

          case 'Q' :                              // Quit test program
               break;

          default :                               // Invalid command
               cout << "Inactive or invalid command" << endl;
        }

	} // End of try block around entire switch statement
	catch ( logic_error &e ) {
               cout << "Code threw an exception: " << e.what() << endl;
	}
    }
    while ( cin && cmd != 'Q' );

    if( ! cin )
    {
        // This is useful if students are testing the list with ints, instead of
	// chars, and accidentally enter a non-digit char.
	cout << "Input error. Exiting." << endl;
    }

    return 0;
}

void print_help()
{
    cout << endl << "Commands:" << endl;
    cout << "  H   : Help (displays this message)" << endl;
    cout << "  +x  : Add x after the cursor" << endl;
    cout << "  -   : Remove the data item marked by the cursor" << endl;
    cout << "  =x  : Replace the data item marked by the cursor with x"
         << endl;
    cout << "  @   : Display the data item marked by the cursor" << endl;
    cout << "  <   : Go to the beginning of the list" << endl;
    cout << "  >   : Go to the end of the list" << endl;
    cout << "  N   : Go to the next data item" << endl;
    cout << "  P   : Go to the prior data item" << endl;
    cout << "  C   : Clear the list" << endl;
    cout << "  E   : Empty list?" << endl;
    cout << "  F   : Full list?" << endl;
    cout << "  M   : Move data item marked by cursor to beginning  "
         << "(" <<
#if LAB5_TEST2
	 "  Active   "
#else
	 "Inactive  "
#endif
	 << ": In-lab Ex. 2)" << endl;
    cout << "  #x  : Insert x before the cursor                  "
         << "  (" <<
#if LAB5_TEST3
	 "  Active "
#else
	 "Inactive "
#endif
	 << " : In-lab Ex. 3)" << endl;
    cout << "  Q   : Quit the test program" << endl;
    cout << endl;
}

