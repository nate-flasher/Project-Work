// Linked List Wrapper.h

#ifndef LINKEDLISTWRAPPER_H
#define LINKEDLISTWRAPPER_H

#include "ListLinked.cpp"

//template <typename DataType>
//class List<DataType>::ListNode;

template <typename DataType>
class LinkedListWrapper: public List<DataType> {
  public:
    //using List<DataType>::ListNode;

    LinkedListWrapper(int ignored=0);
    LinkedListWrapper(const LinkedListWrapper<DataType> &other);
    typename List<DataType>::ListNode* __getHeadPtr();
    typename List<DataType>::ListNode* __getCursorPtr();
    DataType __getCursor();
    void __setCursorPtr(typename List<DataType>::ListNode* ptr);
    void __add( const DataType& newDataItem );

};

#endif // ifndef LINKEDLISTWRAPPER_H
