#include "Sequence.h"


template <typename T>
class LimitSequence : public Sequence<T> {
    private:
       int index;
       Sequence<T>* theSequence;
       int theCount;
  public:
    LimitSequence(Sequence<T>* source, int count);
    T begin() override;
    bool is_end() const override;
    T next() override;
};

template <typename T>
LimitSequence<T>::LimitSequence(Sequence<T>* source, int count) : theSequence(source), theCount(count) {
}


template <typename T>
T LimitSequence<T>::begin(){
    index = 0;
    return theSequence->begin();
}


template <typename T>
bool LimitSequence<T>::is_end() const{
    if(theSequence->is_end()){
        return true;
    }
    else if(index == theCount){
        return true;
    }
    else{
        return false;
    }
}


template <typename T>
T LimitSequence<T>::next(){
    index++;
    return theSequence->next();
}
