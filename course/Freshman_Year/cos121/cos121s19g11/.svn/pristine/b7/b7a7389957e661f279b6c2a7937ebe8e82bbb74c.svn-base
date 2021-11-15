#ifndef __STUDENT_SINGLY_LINKED_LIST_TEST_H
#define __STUDENT_SINGLY_LINKED_LIST_TEST_H

#include <cxxtest/TestSuite.h>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include "LinkedListWrapper.cpp"

class Stu_Singly_Linked_List_Test : public CxxTest::TestSuite{
    public:
	void setUp() { srandom(time(NULL)); }

	void testDefaultConstructor() {
            // Create a default LinkedListWrapper object and check vars
	    LinkedListWrapper<char> lst;

	    //Test Postconditions
	    TSM_ASSERT("hint: having the default constructor set head to 0", lst.__getHeadPtr() == 0);
	    TSM_ASSERT("hint: having the default constructor set cursor to 0", lst.__getCursorPtr() == 0);
	}

	void testParameterizedConstructor() {
            // Create a default LinkedListWrapper object and check vars
	    LinkedListWrapper<char> lst(random()%100);

	    //Test Postconditions
	    TSM_ASSERT("hint: having the default constructor set head to 0", lst.__getHeadPtr() == 0);
	    TSM_ASSERT("hint: having the default constructor set cursor to 0", lst.__getCursorPtr() == 0);
	}

	void testAdd() {
            // Create a copied LinkedListWrapper object and check vars
	    LinkedListWrapper<char> lst;

	    char items[] = { 'a', 'c', 'e' };
	    lst.add(items[0]);
	    lst.add(items[2]);
	    lst.__setCursorPtr(lst.__getHeadPtr());
	    lst.add(items[1]);

	    //Test Postconditions
	    TSM_ASSERT_EQUALS("hint: having add work correctly", 
	                      verifyEquivalent(lst, items, 3), true );
	}

	void testRemove() {
            // Create a copied LinkedListWrapper object and check vars
	    LinkedListWrapper<char> lst;
	    TS_ASSERT_THROWS(lst.remove(), logic_error);

	    char items[] = { 'a', 'c', 'e' };
	    for(int i=0; i<3; i++) {
		lst.__add(items[i]);
	    }

	    lst.remove();

	    //Test Postconditions
	    TSM_ASSERT_EQUALS("hint: having remove work correctly",
	                      verifyEquivalent(lst, items, 2), true );
	    lst.__setCursorPtr(lst.__getHeadPtr());
	    TSM_ASSERT_EQUALS("hint: having remove work correctly", lst.gotoNext(), true );
	    TSM_ASSERT_EQUALS("hint: having remove work correctly", lst.gotoNext(), false );

	    lst.__setCursorPtr(lst.__getHeadPtr());
	    lst.remove();
	    TSM_ASSERT_EQUALS("hint: having remove work correctly", lst.getCursor(), 'c' );

	    lst.remove();
	    TSM_ASSERT("hint: having remove work correctly", lst.isEmpty());
	}
	

	void testReplace() {
	    LinkedListWrapper<char> lst;
	    TSM_ASSERT_THROWS("hint: having replace work correctly",lst.replace('x'), logic_error);

	    char items[] = { 'b', 'd', 'f' };
	    for(int i=0; i<3; i++) {
		lst.__add(char(items[i]-1));
	    }

	    lst.__setCursorPtr(lst.__getHeadPtr());
	    for(int i=0; i<3; i++) {
		lst.replace(items[i]);
		lst.__setCursorPtr(lst.__getCursorPtr()->next);
	    }

	    //Test Postconditions
	    TSM_ASSERT_EQUALS("hint: having replace work correctly", lst.isEmpty(), false );
	    TSM_ASSERT_EQUALS("hint: having replace work correctly", verifyEquivalent(lst, items, 3), true );
	}

	void testClear() {
	    LinkedListWrapper<char> lst;
	    TSM_ASSERT_EQUALS("hint: having clear work correctly on empty list", lst.isEmpty(), true );

	    char items[] = { 'b', 'd', 'f' };
	    for(int i=0; i<3; i++) {
		lst.__add(char(items[i]-1));
	    }
	    lst.clear();
	    TSM_ASSERT("hint: having clear work correctly", lst.__getHeadPtr()==0);
	    TSM_ASSERT("hint: having clear work correctly", lst.__getCursorPtr()==0);
	}

	void testIsEmpty() {
	    LinkedListWrapper<char> lst;
	    TSM_ASSERT_EQUALS("hint: having isEmpty work correctly",  lst.isEmpty(), true );
	    lst.__add('a');
	    TSM_ASSERT_EQUALS("hint: having isEmpty work correctly",  lst.isEmpty(), false );
	}

	void testIsFull() {
	    LinkedListWrapper<char> lst;
	    TSM_ASSERT_EQUALS("hint: having isFull work correctly",  lst.isFull(), false );
	    lst.__add('a');
	    TSM_ASSERT_EQUALS("hint: having isEmpty work correctly",  lst.isFull(), false );
	}

	void testGotoEnd() {
	    LinkedListWrapper<char> lst;

	    char items[] = { 'b', 'd', 'f' };
	    for(int i=0; i<3; i++) {
		lst.__add(items[i]);
	    }
	    lst.__setCursorPtr(lst.__getHeadPtr());

	    lst.gotoEnd();
	    TSM_ASSERT_EQUALS("hint: having gotoEnd work correctly",  lst.getCursor(), 'f' );
	}

	void testGotoNext() {
	    LinkedListWrapper<char> lst;
	    TSM_ASSERT_EQUALS("hint: having gotoNext work correctly on empty list",  lst.gotoNext(), false );

	    char items[] = { 'h', 'i', 'j' };
	    for(int i=0; i<3; i++) {
		lst.__add(items[i]);
	    }

	    TSM_ASSERT_EQUALS("hint: having gotoNext work correctly",  lst.getCursor(), 'j' );
	    TSM_ASSERT_EQUALS("hint: having gotoNext work correctly",  lst.gotoNext(), false );
	}

	void testGotoPrior() {
	    LinkedListWrapper<char> lst;
	    TSM_ASSERT_EQUALS("hint: having gotoPrior work correctly on empty list",  lst.gotoPrior(), false );

	    char items[] = { 'h', 'i', 'j' };
	    for(int i=0; i<3; i++) {
		lst.__add(items[i]);
	    }

	    lst.gotoEnd();
	    TSM_ASSERT_EQUALS("hint: having gotoPrior work correctly",  lst.getCursor(), 'j' );

	    lst.gotoPrior();
	    TSM_ASSERT_EQUALS("hint: having gotoPrior work correctly",  lst.getCursor(), 'i' );

	    lst.gotoPrior();
	    TSM_ASSERT_EQUALS("hint: having gotoPrior work correctly",  lst.getCursor(), 'h' );

	    TSM_ASSERT_EQUALS("hint: having gotoPrior work correctly",  lst.gotoPrior(), false );
	}

	void testCopyConstructor() {
            // Create a copied LinkedListWrapper object and check vars
	    LinkedListWrapper<char> lst;
	    lst.__add('a');
	    lst.__add('c');
	    lst.__add('e');
	    LinkedListWrapper<char> lst2(lst);

	    //Test Postconditions
	    char items[] = { 'a', 'c', 'e' };
	    TSM_ASSERT_EQUALS("hint: having copy constructor work correctly",
	                       verifyEquivalent(lst2, items, 3), true );
	}

	void testAssignmentOperator() {
            // Create a copied LinkedListWrapper object and check vars
	    LinkedListWrapper<char> lst;
	    LinkedListWrapper<char> lst2;
	    char items[] = { 'a', 'c', 'e' };
	    for(int i=0; i<3; i++) {
		lst.__add(char(items[i]));
		lst2.__add(char(items[i]+1));
	    }
	    lst2=lst;

	    //Test Postconditions
	    TSM_ASSERT_EQUALS("hint: having operator= work correctly", verifyEquivalent(lst2, items, 3), true );
	}

	bool verifyEquivalent(LinkedListWrapper<char>& lst, char items[], int size) {
	    if(lst.isEmpty()) {
		if(size == 0) 
		    return true;
		else
		    return false;
	    }

	    lst.gotoBeginning();
	    int i=0;
	    do {
		if(items[i] != char(lst.__getCursor())) return false;
		++i;
	    } while (lst.gotoNext() && i<size);
	    return lst.gotoNext() == false;
	}

	void testGetSize() {
	    LinkedListWrapper<char> lst;
	    TSM_ASSERT_EQUALS("hint: getSize doesn't return correct size for empty list", lst.getSize(), 0);
	    lst.__add('a');
	    lst.__add('c');
	    lst.__add('e');

	    //Test Postconditions
	    TSM_ASSERT_EQUALS("hint: getSize doesn't return correct size for non-empty list", lst.getSize(), 3);
	}

	void testGetCursorPosition() {
	    LinkedListWrapper<char> lst;
	    TSM_ASSERT_EQUALS("hint: getCursorPosition doesn't return correct position for empty list", lst.getCursorPosition(), -1);
	    lst.__add('a');
	    lst.__add('c');
	    lst.__add('e');

	    //Test Postconditions
	    lst.gotoEnd();
	    TSM_ASSERT_EQUALS("hint: getCursorPosition doesn't return correct position for non-empty list", lst.getCursorPosition(), 2);
	    lst.gotoBeginning();
	    TSM_ASSERT_EQUALS("hint: getCursorPosition doesn't return correct position for non-empty list", lst.getCursorPosition(), 0);
	}

};

#endif   // __STUDENT_SINGLY_LINKED_LIST_TEST_H
