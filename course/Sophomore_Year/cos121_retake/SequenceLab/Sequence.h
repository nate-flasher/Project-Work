#ifndef SEQUENCE_H
#define SEQUENCE_H

template <typename T>
class Sequence {
  public:
    virtual T begin() = 0;
    virtual bool is_end() const = 0;
    virtual T next() = 0;
};

#endif
