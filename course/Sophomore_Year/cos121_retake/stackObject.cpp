#include <iostream>

using namespace std;

struct IntStackElement{ // struct and class are same thing. only difference is struct defaults to public. class defaults to private
    int data;
    IntStackElement *next;

};
class IntStack{ // recipie for what our stack will look like or do
    private: //implied
        IntStackElement *top;
    public:
        IntStack(); // initializes a newly created int stack
        void push(int new_value);
        int pop();
        bool isEmpty();
};

IntStack::IntStack(){
    top = nullptr;
}

void IntStack::push(int new_value){
    IntStackElement *temp = new IntStackElement; // temp points to new stack element that has data and next
    temp->data = new_value; // we follow pointer to the stack element and put data(new value) into the element 
    temp->next = top; // points to next element in stack
    top = temp; // top points to temp
}

int IntStack::pop(){
    if (!isEmpty(my_stack)) {
        int result = top->data;
        IntStackElement *old = top;
        top = top->next;
        delete old;

        return result;
    }
}

bool IntStack::isEmpty() {
    return top == nullptr;
}

int main(int argc, char **argv){
    // class      object
    IntStack my_stack; // brand new int stack. uses contructor to do so
    my_stack.push(5);
    return 0;

}
