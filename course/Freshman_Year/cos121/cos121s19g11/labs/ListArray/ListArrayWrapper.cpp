#ifndef LISTARRAYWRAPPER_CPP
#define LISTARRAYWRAPPER_CPP

//--------------------------------------------------------------------
//
//  Laboratory 3                                  ListArrayWrapper.cpp
// 
//  Wrapper class that allows tester access to the internal data and
//  functions in the ListArray class.
//
//--------------------------------------------------------------------

using namespace std;

#include "ListArrayWrapper.h"

// Constructors
template < typename DataType >
ListArrayWrapper<DataType>::ListArrayWrapper ( )
:List<DataType>()
{}

template < typename DataType >
ListArrayWrapper<DataType>::ListArrayWrapper ( int maxNumber )
:List<DataType>(maxNumber)
{}

template < typename DataType >
ListArrayWrapper<DataType>::ListArrayWrapper ( const ListArrayWrapper<DataType>& source ) 
:List<DataType>(source)
{}

template < typename DataType >
ListArrayWrapper<DataType>& ListArrayWrapper<DataType>::operator= ( const ListArrayWrapper<DataType>& source ) 
{
    List<DataType>::operator=(source);
    return *this;
}

// Destructor
template < typename DataType >
ListArrayWrapper<DataType>::~ListArrayWrapper () 
{}


// List manipulation operations
template < typename DataType >
void ListArrayWrapper<DataType>::setMaxSize( int maxSize ) {
    this->maxSize = maxSize;
}
template < typename DataType >
int ListArrayWrapper<DataType>::getMaxSize() const {
    return maxSize;
}

template < typename DataType >
void ListArrayWrapper<DataType>::setSize( int size ) {
    this->size = size;
}

template < typename DataType >
int ListArrayWrapper<DataType>::getCursorLocation() const {
    return cursor;
}

template < typename DataType >
void ListArrayWrapper<DataType>::setCursorLocation(int cursor) {
    this->cursor = cursor;
}

template < typename DataType >
DataType* ListArrayWrapper<DataType>::getDataItems() const {
    return dataItems;
}


#endif	// ifndef LISTARRAYWRAPPER_H
