#include <iostream>
#include <vector>
#include <string>
#include <sodium.h>

using namespace std;



template <typename T>
class ValidPointer{
    private:
        T *ptr;
        vector<unsigned char> hash_value;

    public:
        ValidPointer(T *thisPointer);
        bool isValid();
        //bool isNull();
        T* get();


};



template <typename T>
T* ValidPointer<T>::get(){
    return this->ptr;
}


template <typename T>
ValidPointer<T>::ValidPointer(T *thisPointer){
    if (thisPointer != nullptr) {
    hash_value = vector<unsigned char>(crypto_generichash_BYTES);

    crypto_generichash( this->hash_value.data(), this->hash_value.size(), (unsigned char*)thisPointer, sizeof(T), nullptr, 0);
    }
    this->ptr = thisPointer;
    
}
template <typename T>
bool ValidPointer<T>::isValid(){ // returns true if the pointer is pointing to 
    if (ptr != nullptr){
    vector<unsigned char> hash_value2(crypto_generichash_BYTES);
    
    crypto_generichash( hash_value2.data(), hash_value2.size(), (unsigned char*)ptr, sizeof(T), nullptr, 0);
    if(hash_value2 == hash_value){
        return true;
    }
    else{
        return false;
    }
    }
    return true;
    
    
}





template <typename T>
class ValidStackElement{
    public:
        T data; // variable that belongs to class
        ValidPointer<ValidStackElement<T>> next; //variable that belongs to class ...refers to next element in stack and keeps on going

        ValidStackElement(T init, ValidStackElement<T> *ptr); //constructor
        bool isValid(); //method
};


template <typename T>
ValidStackElement<T>::ValidStackElement(T init, ValidStackElement<T> *ptr)
    : data(init), next(ptr){

    }


template <typename T>
bool ValidStackElement<T>::isValid(){ // only need to call this on the head or first element
// check to make sure the current stack element is valid
    if (next.isValid() == true){ //checking to see if the pointer, next is valid
        ValidStackElement<T> *nextElemPtr = next.get();
        if(nextElemPtr != nullptr){
            return nextElemPtr->isValid(); //we use recursion when checking each validstackelement until we get to nullptr
        }
        else{
            return true;
        }

    }
    else {
        return false;
    }

// and check if all the other stack elements we are pointing to are valid
}






template <typename T>
class ValidStack{
    private:
        ValidPointer<ValidStackElement<T>> Top;//refers to first element in stack
    public:
        void push(T);
        T pop();
        bool isEmpty();
        bool isValid();
        ValidStack();
        
};

template <typename T>
ValidStack<T>::ValidStack()
    : Top(nullptr) {
    }

template <typename T>
void ValidStack<T>::push(T new_value){
  if(!isEmpty()){  
  ValidStackElement<T> *elementPtr = new ValidStackElement<T>(new_value, Top.get());

  Top = ValidPointer<ValidStackElement<T>>(elementPtr);
  }
  else{
  ValidStackElement<T> *elementPtr = new ValidStackElement<T>(new_value, nullptr);
  Top = ValidPointer<ValidStackElement<T>>(elementPtr);
    
  }
}

template <typename T>
bool ValidStack<T>::isEmpty() {
    return Top.get() == nullptr;
}

template <typename T>
T ValidStack<T>::pop() {
    if(!isEmpty()) {
        T result = Top.get()->data;
        Top = ValidPointer<ValidStackElement<T>>(Top.get()->next);
        return result;
    }
}

template <typename T>
bool ValidStack<T>::isValid(){
    if(!isEmpty()){
        return Top.get()->isValid() && Top.isValid();
    }
    else{
        return true;
    }

}


int main() {
    if (sodium_init() < 0) {
        return 1;
    }

    //create a valid stack, push something on, check if its valid
   ValidStack<int> my_valid_Stack;
    for(int i = 0; i<5; i++){
        my_valid_Stack.push(i);
        cout << my_valid_Stack.isValid() << "\n";
    }
   // my_valid_Stack.Top.get()->next.get()->data  = 20000000;
 //       cout << my_valid_Stack.isValid() << "\n";
    return 0;
}
