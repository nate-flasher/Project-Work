//--------------------------------------------------------------------
//  Class declaration for the String class.
//  Last mod: Mon Apr 11 12:30:07 EDT 2016
//--------------------------------------------------------------------

/**
 * @author Stefan Brandle
 * @date April 2016
 * @file String.h
 */

#ifndef STRING_CPP
#define STRING_CPP

#include <iostream>
#include <string>
#include <cstring>


using namespace std;

#include "String.h"

// Constructors, destructors, and assignment
                                       // Default constructor
String::String( ) {
    bufferSize = 1;
    buffer = new char[1];
    buffer[0] = '\0';
}

/*

String s1;
...
int i = 0;
int j(i); // int j = i;


g++ -Wall test.cpp String.cpp
*/

// Copy constructor
// String s2(s1); // String s2 = s1;
String::String( const String &other ) {
    bufferSize = other.bufferSize;
    buffer = new char[bufferSize];
    strcpy(buffer, other.buffer);
}

// Conversion constructor: C-string to String
// String s3("Hi, mom!");
String::String( const char *charSeq ) {
    bufferSize = strlen(charSeq) + 1;
    buffer = new char[bufferSize];
    strcpy(buffer, charSeq);
}

// Assignment
// s3 = s1;
String& String::operator= ( const String &other ) {
    if(this == &other) return *this;
    
    if(bufferSize < other.bufferSize) {
        delete[] buffer;
        bufferSize = other.bufferSize;
        buffer = new char[bufferSize];
    }
    strcpy(buffer, other.buffer);

    return *this;
}

// Destructor
String::~String() {
    delete[] buffer;
}


// Transformer functions
// - Setters
// TODO: need to change to const ... &other
                        // Sets string equiv to other
void String::set( String other ) {
    operator=(other);
}

                        // Sets string equiv to other
void String::set( string other ) {
    delete[] buffer;
    bufferSize = other.length() + 1;
    buffer = new char[bufferSize];
    strcpy(buffer, other.c_str());
}

                       // Sets string equiv to charSeq
void String::set( char *charSeq ) {
  bufferSize= strlen(charSeq)+1;
  buffer=new char[bufferSize];
  strcpy(buffer, charSeq);
}

//     Other transformers
                                    // Clear string
void String::clear() {
    buffer[0]='\0';    
}


// Observer functions
// - Getters
                       // Returns C-string
const char* String::c_str() const {
    return buffer;
}

// - Other observers
                           // # characters
int String::getLength() const {
    return strlen(buffer);
}

                  // Subscript
char String::operator[]( int n ) const {
    if(n<0||n>=strlen(buffer)){
        return '\0';
    }
    else{
        return buffer[n];
    }
}

    // Overload == for String
bool String::operator==( const String& other ) const {
    if(strcmp(buffer, other.buffer)==0){
        return true;    
    }
    else {
        return false;
    }
}

                             // Print the string for debugging
void String::print () const {
    cout<<buffer;
}


#endif    /* ifndef STRING_H */
