#include "Sequence.h"


template <typename T>
class MySequence : public Sequence<T> {
    private:
        T start_value1;
        T next_value;
        
  public:
    MySequence();
    T begin() override;
    bool is_end() const override;
    T next() override;
};

template <typename T>
MySequence<T>::MySequence()  {
}


template <typename T>
T MySequence<T>::begin(){
    start_value1 = 2;
    return start_value1;
}


template <typename T>
bool MySequence<T>::is_end() const{
    return false;
}


template <typename T>
T MySequence<T>::next(){
    next_value = start_value1 * start_value1;
    start_value1++;
    return next_value;
}
