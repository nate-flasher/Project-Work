#ifndef LISTARRAYWRAPPER_H
#define LISTARRAYWRAPPER_H

//--------------------------------------------------------------------
//  Laboratory 3                                    ListArrayWrapper.h
// 
//  Wrapper class that allows tester access to the internal data and
//  functions in the ListArray class.
//--------------------------------------------------------------------

#include <iostream>
#include "ListArray.cpp"

template < typename DataType >
class ListArrayWrapper : public List<DataType> {
  public:

    // Constructors
    ListArrayWrapper ( );	// Default constructor
    ListArrayWrapper ( int maxNumber );
    ListArrayWrapper ( const ListArrayWrapper& source );		// Copy constructor
    
    // Overloaded assignment operator
    ListArrayWrapper& operator= ( const ListArrayWrapper& source );

    // Destructor
    virtual ~ListArrayWrapper ();

    // List manipulation operations
    void setMaxSize( int maxSize );
    int getMaxSize() const;
    void setSize( int size );
    void setCursorLocation(int cursor);
    int getCursorLocation() const;
    DataType* getDataItems() const;

    using List<DataType>::maxSize;
    using List<DataType>::cursor;
    using List<DataType>::size;
    using List<DataType>::dataItems;
};

#endif	// ifndef LISTARRAYWRAPPER_H
