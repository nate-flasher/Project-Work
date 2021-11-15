/**
 * @Ryan Costello, Wyatt Deno, Nate Flasher
 * @file ListArray.cpp
 * @brief The array-based List class implementation file.
 */

#ifndef LISTARRAY_CPP
#define LISTARRAY_CPP

#include <iostream>
#include "ListArray.h"

using namespace std;

template <typename DataType>
List<DataType>::List()
// Initialize the object's member variables
: maxSize(defaultMaxSize), size(0), cursor(-1)
{
    // Make the array to put the items in and point dataItems there.
    dataItems = new DataType[maxSize];
}

template <typename DataType>
List<DataType>::List( int maxItems ) {
    maxSize = maxItems;
    size = 0;
    cursor= -1;
    dataItems = new DataType[maxSize];
}

template <typename DataType>
List<DataType>::List( const List<DataType>& other ) {
    // You do: create dataItems array and copy all valid data from the other list
    size = other.size;
    cursor = other.cursor;
    maxSize = other.maxSize;
    dataItems = new DataType[maxSize];
    for (int i =0; i<size;i++){
        dataItems[i]=other.dataItems[i];
    }
}

template <typename DataType>
List<DataType>::~List() {
    // You do: return dynamically allocated memory
    delete[] dataItems;
}

template <typename DataType>
List<DataType>& List<DataType>::operator=( const List<DataType>& other ) {
    // Handle being asked to assign yourself to yourself
    // Do that by comparing address of other list to your address.

    // You do: delete your dataItems array

    // You do: make a new dataItems array of the correct size

    // To get chained assignment working, return a reference to yourself
    // by doing following. Chained assignment is "a = b = c".
    return *this;
}

// Iterators

template <typename DataType>
bool List<DataType>::gotoNext() {
    if(isEmpty()) return false;
    if(cursor == size-1) return false;
    cursor++;
    return true
}

template <typename DataType>
bool List<DataType>::gotoPrior() {
    if(isEmpty()) return false;
    if(cursor == 0) return false;
    cursor--;
    return true;
}

template <typename DataType>
void List<DataType>::gotoBeginning() throw (logic_error) {
    if (isEmpty()) throw logic_error("The list was empty");
    cursor = 0;
}

template <typename DataType>
void List<DataType>::gotoEnd() throw (logic_error) {
    if (isEmpty()) throw logic_error("The list was empty");
    cursor = size-1;
}

// Observers

template <typename DataType>
bool List<DataType>::isEmpty() const {
    return size==0;
}

template <typename DataType>
bool List<DataType>::isFull() const {
    return size==maxSize;
}

template <typename DataType>
int List<DataType>::getCursorPosition() const {
    return cursor;
}

template <typename DataType>
int List<DataType>::getSize() const {
    return size;
}

template <typename DataType>
DataType List<DataType>::getCursor() const throw (logic_error) {
    if(isEmpty()) throw logic_error("The list is empty");
    return dataItems[cursor];
}


template <typename DataType>
DataType List<DataType>::operator[]( int position ) const throw (logic_error) {
    if(isEmpty()) throw logic_error("The list was empty");
    if(position < 0 || position>=size) throw logic_error("Position is empty");
    return dataItems[position];
}

template <typename DataType>
void List<DataType>::showStructure() const                      // Debugging function
// Outputs the data items in a list. if the list is empty, outputs
// "empty list". this operation is intended for testing/debugging
// purposes only.

{
    int j;   // loop counter

    if ( size == 0 )
       cout << "empty list" << endl;
    else
    {
       cout << "size = " << size
            <<  "   cursor = " << cursor << endl;
       for ( j = 0 ; j < maxSize ; j++ )
           cout << j << "\t";
       cout << endl;
       for ( j = 0 ; j < size ; j++ ) {
           if( j == cursor ) {
              cout << "[";
              cout << dataItems[j];
              cout << "]";
              cout << "\t";
           }
           else
              cout << dataItems[j] << "\t";
       }
       cout << endl;
    }
}

// Transformers/mutators
template <typename DataType>
bool List<DataType>::search( DataType value ) {
    for (int i=0; i<size; i++){
        if (dataItems[i] == value) return true;
    }
    return false;
}

template <typename DataType>
void List<DataType>::add( const DataType& newItem ) throw (logic_error) {
    if(isFull()) throw logic_error("The list is full");
    for (int i = size; i > (cursor+1); i--){
        dataItems[i]=dataItems[i-1];
    }
    cursor++;
    dataItems[cursor] = newItem;
    size++;
    
}

template <typename DataType>
void List<DataType>::add( const List<DataType>& otherList ) throw (logic_error) {
    if (isFull() || size+otherList.size > maxSize) throw logic_error("List too big");
    for (i = size + otherList.size; i>cursor; i-- ){
        dataItems[i]=dataItems[i-otherList.size];
    }
    for( i = 0;i<otherList.size;i++){
        dataItems[cursor+i] = otherList.dataItems[i];

    }
    size += otherList.size;

}

template <typename DataType>
void List<DataType>::remove( ) throw ( logic_error) {
    if(isEmpty()) throw logic_error("The list is empty");
    for(int i = cursor; i < size-1; i++){
        dataItems[i]=dataItems[i+1];
    }
    size--;
    if(cursor==size) {
        cursor = 0;
    }
    if(isEmpty()) {
        cursor = -1;
    }
}

template <typename DataType>
void List<DataType>::remove( const DataType& delItem ) {
    for(i=0;i<size;i++){
        if(dataItems[i]==delItem){
            for(int j=i; j < size-1;j++){
                dataItems[j]=dataItems[j+1];
            }
            size--;
            return;
        
        }
    }
}

template <typename DataType>
void List<DataType>::replace( const DataType& replaceItem ) throw (logic_error) {
    if(isEmpty()) throw logic_error("The list is empty");
    dataItems[cursor]=replaceItem;
}

template <typename DataType>
void List<DataType>::clear() {
    // Don't throw away the array. Just declare it to be empty.

}

#endif     // #ifndef LIST_CPP
