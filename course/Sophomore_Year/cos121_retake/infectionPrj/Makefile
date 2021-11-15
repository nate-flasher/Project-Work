infection: Actor.o Hospital.o Board.o conio.o Human.o killer.o Location.o main.o
	g++ Actor.o Hospital.o Board.o conio.o Human.o killer.o Location.o main.o -o infection 

Actor.o: Actor.cpp Actor.h Board.h Location.h
	g++ -c Actor.cpp
Board.o: Board.cpp Board.h Actor.h Location.h
	g++ -c Board.cpp
conio.o: conio.cpp conio.h
	g++ -c conio.cpp
Human.o: Human.cpp Human.h Board.h Actor.h
	g++ -c Human.cpp
killer.o: killer.cpp killer.h Actor.h
	g++ -c killer.cpp
Location.o: Location.cpp Location.h 
	g++ -c Location.cpp
Hospital.o: Hospital.cpp Hospital.h Actor.h
	g++ -c Hospital.cpp
main.o: main.cpp Board.h
	g++ -c main.cpp
