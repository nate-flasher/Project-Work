//--------------------------------------------------------------------
//  Laboratory 1                                       StringWrapper.cpp
//  **Instructor's Solution**
//  Class declaration for the array implementation of the String ADT
//--------------------------------------------------------------------

#ifndef STRINGWRAPPER_CPP
#define STRINGWRAPPER_CPP

#include <stdexcept>
#include <iostream>
#include "StringWrapper.h"

using namespace std;

StringWrapper::StringWrapper ()
: String() {}

StringWrapper::StringWrapper ( const char *charSeq )
: String(charSeq) {}

StringWrapper::StringWrapper ( const String &other )
: String(other) {}

// Helps with testing the class
char* StringWrapper::getBuffer() { return buffer; }

int StringWrapper::getBufferSize() { return bufferSize; }

#endif
