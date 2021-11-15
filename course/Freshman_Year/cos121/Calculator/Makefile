CXXTEST = Calculator_test.h
FILES = Calculator.cpp
run:	runner
	./runner
runner:	runner.cpp Calculator.cpp
	g++ -o runner runner.cpp Calculator.cpp
runner.cpp: Calculator.cpp Calculator_test.h
	cxxtestgen.pl --error-printer -o runner.cpp Calculator_test.h
clean:
	rm -f *.o runner runner.cpp

Calculator.cpp: Calculator.h
