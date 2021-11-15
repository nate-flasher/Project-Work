/**
 * LinkedListWrapper.cpp: the wrapper code for the class that provides
 * access functions for the Linked List class.
 */

#ifndef LINKEDLISTWRAPPER_CPP
#define LINKEDLISTWRAPPER_CPP

#include "LinkedListWrapper.h"

template <typename DataType>
LinkedListWrapper<DataType>::LinkedListWrapper(int ignored)
:List<DataType>(ignored)
{}

template <typename DataType>
LinkedListWrapper<DataType>::LinkedListWrapper(const LinkedListWrapper<DataType> &other)
:List<DataType>(other)
{}

template <typename DataType>
typename List<DataType>::ListNode* LinkedListWrapper<DataType>::__getHeadPtr()
{
    return List<DataType>::head;
}

template <typename DataType>
typename List<DataType>::ListNode* LinkedListWrapper<DataType>::__getCursorPtr()
{
    return List<DataType>::cursor;
}

template <typename DataType>
void LinkedListWrapper<DataType>::__setCursorPtr(typename List<DataType>::ListNode* ptr) {
    List<DataType>::cursor = ptr;
}

template <typename DataType>
DataType LinkedListWrapper<DataType>::__getCursor()
{
    return List<DataType>::cursor->dataItem;
}

template <typename DataType>
void LinkedListWrapper<DataType>::__add( const DataType& newDataItem )
{
    if ( this->head == 0 ) {
	this->cursor = this->head = new typename List<DataType>::ListNode(newDataItem, 0);
    } else {
	this->cursor = this->cursor->next = 
	      new typename List<DataType>::ListNode(newDataItem, this->cursor->next);
    }
}

#endif  // ifndef LINKEDLISTWRAPPER_CPP
