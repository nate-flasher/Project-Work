#include <iostream>
#include "ArithmeticSequence.h"
#include "big_integer.h"
#include "GeometricSequence.h"
#include "InfiniteArithmeticSequence.h"
#include "LimitSequence.h"
#include "FibSequence.h"
#include "MyTest.h"
using namespace std;


template <typename T>
void sum(Sequence<T>& seq) {
    T result = 0;

    for (T i = seq.begin(); !seq.is_end(); i = seq.next()) {
        result += i;
    }

    cout << "sum = " << result << "\n";
}




int main() {
    ArithmeticSequence<int> test(0,10,1);
    sum(test);
    cout << "\n";

    GeometricSequence<double> geotest(2,50,1.2);
    sum(geotest);
    cout << "\n";

    InfiniteArithmeticSequence<int> inftest(2,50000);

    LimitSequence<int> limittest(&inftest, 30000);
    sum(limittest);
    cout << "\n";

    FibSequence<int> fibtest;
    LimitSequence<int> limittest2(&fibtest, 100);
    sum(limittest2);
    cout << "\n";
    

    MySequence<int> myTest;
    LimitSequence<int> limittest3(&myTest, 5);
    sum(limittest3);
    cout << "\n";
}
