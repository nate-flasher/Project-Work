#rule: dependency

#intructions to make rule

checkout: conio.o checkout.o
        g++ -o checkout conio.o checkout.o

conio.o: conio.cpp conio.h
        g++ -c conio.cpp

checkout.o: checkout.cpp conio.h
        g++ -c checkout.cpp
