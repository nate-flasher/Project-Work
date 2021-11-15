#include "Sequence.h"


template <typename T>
class FibSequence : public Sequence<T> {
    private:
        T start_value1;
        T start_value2;
        T next_value;
        
  public:
    FibSequence();
    T begin() override;
    bool is_end() const override;
    T next() override;
};

template <typename T>
FibSequence<T>::FibSequence()  {
}


template <typename T>
T FibSequence<T>::begin(){
    start_value1 = 1;
    start_value2 = 1;
    return start_value1;
}


template <typename T>
bool FibSequence<T>::is_end() const{
    return false;
}


template <typename T>
T FibSequence<T>::next(){
    next_value = start_value1 + start_value2;
    start_value1 = start_value2;
    start_value2 = next_value;
    return next_value;
}
