//--------------------------------------------------------------------
//  Class declaration for the String class.
//  Last mod: Mon Apr 11 12:30:07 EDT 2016
//--------------------------------------------------------------------

/**
 * @author Stefan Brandle
 * @date April 2016
 * @file String.h
 */

#ifndef STRING_H
#define STRING_H

#include <iostream>
#include <string>
#include <cstring>

using namespace std;

class String
{
  public:

    // Constructors, destructors, and assignment
    String( );                                       // Default constructor
    String( const String &other );                   // Copy constructor
    String( const char *charSeq );                   // Conversion constructor: C-string to String
    String& operator = ( const String &other );      // Assignment
    ~String();                                       // Destructor

    // Transformer functions
    // - Setters
    // TODO: need to change to const ... &other
    void set( String other );                        // Sets string equiv to other
    void set( string other );                        // Sets string equiv to other
    void set( char *charSeq );                       // Sets string equiv to charSeq
    //     Other transformers
    void clear();                                    // Clear string

    // Observer functions
    // - Getters
    const char* c_str() const;                       // Returns C-string
    // - Other observers
    int getLength() const;                           // # characters
    char operator[]( int n ) const;                  // Subscript
    bool operator==( const String& other ) const;    // Overload == for String
    void print () const;                             // Print the string for debugging

  protected:

    // Data members
    int bufferSize;   /// Size of the string buffer
    char *buffer;     /// Pointer to a string buffer containing a null-terminated sequence of characters

};
#endif    /* ifndef STRING_H */
