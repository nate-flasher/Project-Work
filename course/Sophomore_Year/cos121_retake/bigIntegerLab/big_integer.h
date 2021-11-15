#ifndef BIG_INTEGER_H
#define BIG_INTEGER_H

#include <iostream>
#include <string>

using namespace std;

class BigInteger {
    string value;

  public:
    BigInteger(const int start = 0);
    BigInteger(const std::string& start);

    BigInteger half() const;
    bool isEven() const;
    BigInteger operator^(const BigInteger& other) const; //done
    BigInteger operator+(const BigInteger& other) const; //defining + operator for our object
    BigInteger operator*(const BigInteger& other) const; //defining * operator for our object 

    bool operator<(const BigInteger& other) const;
    bool operator==(const BigInteger& other) const;

    void display(std::ostream& out) const;
   
};

#endif
