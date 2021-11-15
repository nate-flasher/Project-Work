#include "Sequence.h"


template <typename T>
class ArithmeticSequence : public Sequence<T> {
    private:
        T start_value;
        T end_value;
        T next_value;
        T current;
        
  public:
    ArithmeticSequence(T start, T stop, T step);
    T begin() override;
    bool is_end() const override;
    T next() override;
};

template <typename T>
ArithmeticSequence<T>::ArithmeticSequence(T start, T stop, T step) : start_value(start), end_value(stop), next_value(step) {
}


template <typename T>
T ArithmeticSequence<T>::begin(){
    current = start_value;
    return current;
}


template <typename T>
bool ArithmeticSequence<T>::is_end() const{
    if(end_value < current){
        return true;
    }
    else{
        return false;
    }
}


template <typename T>
T ArithmeticSequence<T>::next(){
    current = current + next_value;
    return current;
}
