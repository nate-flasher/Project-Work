#include <iostream>
#include <sodium.h>
//call next.isValid() to see if it's valid pointer
//also check to see if what next points to is valid (use next.get())
//next.get() returns a valid stack element pointer
//ValidStackElement<T>* xyz = next.get();
//next.isValid() checks to see if next is valid
// xyz -> isValid(); (checks if next stack element is valid)
/*my ValidPointer{
  public:

  T *get();  this will point to a valid stack element that holds a T (which is data)

}
*/

//build valid stack element, and that will look like <-
//next make valid stack



using namespace std;

template <typename T>
class ValidStackElement{
    public:
        T data;
        ValidPointer<ValidStackElement<T>> next;
        ValidStackElement(T data, ValidStackElement<T>* next);
        bool isValid();

};

bool ValidStackElement<T>::isValid(){
    ValidStackElement<T>* nextElemPtr; //check to see if this is nullptr
    nextElemPtr->isValid(); // don't do this unless line above isn't a nullptr
}

template <typename T>
class ValidPointer{
};

template <typename T>
class ValidStack{
//top that points to valid stack element
};

bool ValidStack::isValid(){
//this is where we check to make sure valid stack pointer is valid
//and we need to recursively call each element and see if they're valid
//parent problem we are trying to solve
}

int main(){

}


