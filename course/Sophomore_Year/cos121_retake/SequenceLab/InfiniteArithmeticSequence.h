#include "Sequence.h"


template <typename T>
class InfiniteArithmeticSequence : public Sequence<T> {
    private:
        T start_value;
        T next_value;
        T current;
        
  public:
    InfiniteArithmeticSequence(T start, T step);
    T begin() override;
    bool is_end() const override;
    T next() override;
};

template <typename T>
InfiniteArithmeticSequence<T>::InfiniteArithmeticSequence(T start, T step) : start_value(start), next_value(step) {
}


template <typename T>
T InfiniteArithmeticSequence<T>::begin(){
    current = start_value;
    return current;
}


template <typename T>
bool InfiniteArithmeticSequence<T>::is_end() const{
    return false;
}


template <typename T>
T InfiniteArithmeticSequence<T>::next(){
    current = current * next_value;
    return current;
}
