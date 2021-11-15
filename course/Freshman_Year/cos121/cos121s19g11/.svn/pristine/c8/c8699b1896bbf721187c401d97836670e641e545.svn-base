CLASS = ListLinked
CPP = g++
TEST = testlist

mesg:
	@echo "Make targets are 'testlist', 'runcxx', and 'clean'"
	@echo "E.g., type 'make runcxx'"

testlist: testlist.o
	g++ -Wall -g -o testlist testlist.o

# *.dSYM are OS X debugging files
clean:
	rm -f $(TEST) $(TESTDNA) *.o listrunner*
	@rm -rf *.dSYM

testlist.o: testlist.cpp ListLinked.cpp ListLinked.h

LISTTEST = __student_singly_linked_list_test.h
LISTFILES = ListLinked.cpp ListLinked.h
runcxx: listrunner
	./listrunner
listrunner:	listrunner.cpp $(LISTFILES)
	g++ -g -Og -o listrunner listrunner.cpp ListLinked.cpp
listrunner.cpp: $(LISTFILES) $(LISTTEST)
	cxxtestgen.pl --error-printer -o listrunner.cpp $(LISTTEST)

