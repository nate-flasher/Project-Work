#ifndef LISTLINKED_CPP
#define LISTLINKED_CPP

#include <iostream>
#include <stdexcept>

#include "ListLinked.h"

using namespace std;

template <typename DataType>
List<DataType>::ListNode::ListNode( DataType newData, ListNode* next ) {
    dataItem = newData;
    this->next = next; 
}

template <typename DataType>
List<DataType>::List() {
    head = 0;
    cursor = 0;
}

template <typename DataType>
List<DataType>::List(int /* maxItems */) {
    head = cursor = 0;
}

template <typename DataType>
List<DataType>::List(const List& other) {
    head = cursor = 0;
    operator=(other);
}

template <typename DataType>
List<DataType>::~List() {
    clear();
}

template <typename DataType>
List<DataType>& List<DataType>::operator=(const List& other) {
    if(&other==this)return *this;
    clear();
    add(other);
    return *this;
}


// Iterators
template <typename DataType>
bool List<DataType>::gotoNext() {
    if(isEmpty() || cursor->next == 0){
        return false;
    }else{
        cursor = cursor->next;
        return true;
    }

}

template <typename DataType>
bool List<DataType>::gotoPrior() {
    if(isEmpty()){
        return false;
    }
    if(cursor==head){
        return false;
    }
    ListNode* temp=cursor;
    cursor=head;
    while(cursor->next != temp){
        cursor = cursor->next;
    }
    return true;
}

template <typename DataType>
void List<DataType>::gotoBeginning() throw(logic_error){
    if(isEmpty()){
        throw logic_error("list is empty");
    }
    cursor=head;
}

template <typename DataType>
void List<DataType>::gotoEnd() throw(logic_error){
    if(isEmpty()){
        throw logic_error("list is empty");
    }
   while( cursor->next!=0){
        cursor=cursor->next;
   }
}


// Observers
template <typename DataType>
bool List<DataType>::isEmpty() const {
    if(head==0){
    return true;
    }else{
    return false;
    }
}

template <typename DataType>
bool List<DataType>::isFull() const {
        return false;
}

template <typename DataType>
int List<DataType>::getCursorPosition() const {
    if(isEmpty()){
        return -1;
    }
    ListNode* temp=head;
    int index=0;
    while (temp != cursor){
        index++;
        temp = temp->next;
    }
    return index;
}

template <typename DataType>
int List<DataType>::getSize() const {
    ListNode* temp=head;
    int size = 0;
    while (temp != 0 ){
        size++;
        temp = temp->next;
    }
    return size;
}

template <typename DataType>
DataType List<DataType>::getCursor() const throw (logic_error) {
    if(isEmpty()) throw logic_error("List is empty");
    return cursor->dataItem;
}

template <typename DataType>
DataType List<DataType>::operator[]( int position ) const throw (logic_error) {
    if(isEmpty()) throw logic_error("List is empty");
    ListNode* temp=head;
    while(temp != position){
        temp= temp->next;
    }
    return temp->dataItem;
}

template <typename DataType>
void List<DataType>::showStructure() const {

// Outputs the items in a list. If the list is empty, outputs
// "Empty list". This operation is intended for testing and
// debugging purposes only.

    if ( isEmpty() )
    {
       cout << "Empty list" << endl;
    } 
    else
    {
	for (ListNode* temp = head; temp != 0; temp = temp->next) {
	    if (temp == cursor) {
		cout << "[";
	    }

	    // Assumes that dataItem can be printed via << because
	    // is is either primitive or operator<< is overloaded.
	    cout << temp->dataItem;	

	    if (temp == cursor) {
		cout << "]";
	    }
	    cout << " ";
	}
	cout << endl;
    }
}
		// Debugging function

// Transformers/mutators
template <typename DataType>
bool List<DataType>::search(DataType value) {
    ListNode* temp=head;
    while(temp->dataItem != value){
        if(temp->next==0){
            return false;
        }
        temp=temp->next;
    }
    return true;
}

template <typename DataType>
void List<DataType>::add( const DataType& newItem ) throw (logic_error) {
    if(isFull()) throw logic_error("list is full");
    if(isEmpty()){
    head = new ListNode(newItem,0);
    cursor = head;
    }else{
    ListNode* temp = new ListNode(newItem, cursor->next);
    cursor->next = temp;
    cursor = temp;
    }
}

template <typename DataType>
void List<DataType>::add( const List& otherList ) throw (logic_error) {
    if(isFull()) throw logic_error("list is full");
   ListNode* temp = otherList.head;
   while(temp!=0){
       add(temp->dataItem);
       temp = temp->next;
    }
}

template <typename DataType>
void List<DataType>::remove() throw (logic_error) {
    if(isEmpty()) throw logic_error("list is empty");
    if(cursor==head){
    cursor = cursor->next;
    delete head;
    head=cursor;
    }else{
    gotoPrior();
    ListNode* temp = cursor->next;
    cursor->next=cursor->next->next;
    }
}

template <typename DataType>
void List<DataType>::remove( const DataType& delItem ) {
     ListNode* temp=head;
     ListNode* behind=temp;
     ListNode* ahead=temp->next;
     int i=0;
     while(temp->dataItem != delItem){
        if(temp->next==0){
            return;
        }
        behind=temp;
        temp=temp->next;
        ahead=ahead->next;
        i++;
     }
     delete temp;
     if(i>0){
        behind->next=ahead;
     }else{
        if(cursor==head){
        head=ahead;
        cursor=head;
     }
        head=ahead;
    }
}
template <typename DataType>
void List<DataType>::replace( const DataType& replaceItem ) throw (logic_error) {
    if(isEmpty()) throw logic_error("list is empty");
    cursor->dataItem=replaceItem;
    
}

template <typename DataType>
void List<DataType>::clear() {
    cursor = head;
    while(cursor != 0){
        cursor = cursor->next;
        delete head;
        head = cursor;
        
    }
    
}

#endif
