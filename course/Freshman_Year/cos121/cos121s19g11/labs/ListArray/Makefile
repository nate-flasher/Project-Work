CLASS = ListArray
CPP = g++
TEST = testlist
TESTOBJS = $(TEST).o

mesg:
	@echo "Make targets are 'testlist', 'runcxx', and 'clean'"
	@echo "E.g., type 'make runcxx'"

testlist: testlist.o
	g++ -Wall -g -o testlist testlist.o

# *.dSYM are OS X debugging files
clean:
	rm -f $(TEST) $(TESTDNA) *.o listrunner*
	@rm -rf *.dSYM

testlist.o: testlist.cpp ListArray.cpp ListArray.h

LISTTEST = __instructor_listarray_test_full.h
LISTFILES = ListArray.cpp ListArray.h
runcxx: listrunner
	./listrunner
listrunner:	listrunner.cpp $(LISTFILES)
	g++ -g -Og -o listrunner listrunner.cpp ListArray.cpp
listrunner.cpp: $(LISTFILES) $(LISTTEST)
	cxxtestgen.pl --error-printer -o listrunner.cpp $(LISTTEST)

