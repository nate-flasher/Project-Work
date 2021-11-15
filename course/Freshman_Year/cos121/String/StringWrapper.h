//--------------------------------------------------------------------
//  Laboratory 1                                     StringWrapper.h
//  Class declaration for the array implementation of the String ADT
//--------------------------------------------------------------------

#ifndef STRINGWRAPPER_H
#define STRINGWRAPPER_H

#include <stdexcept>
#include <iostream>
#include "String.h"

using namespace std;

class StringWrapper : public String
{
  public:

    // Constructors and operator=
    StringWrapper ();                             // Default constructor
    StringWrapper ( const char *charSeq );        // Copy constructor: char *
    StringWrapper ( const String &other );        // Copy constructor: String

    // Helps with testing the class
    char* getBuffer();
    int getBufferSize();

  private:

};

#endif
