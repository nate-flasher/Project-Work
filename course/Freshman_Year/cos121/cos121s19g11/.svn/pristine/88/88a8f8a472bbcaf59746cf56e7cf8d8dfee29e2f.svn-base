#ifndef __INSTRUCTOR__LISTARRAY_BASE_TEST_H
#define __INSTRUCTOR__LISTARRAY_BASE_TEST_H

#include <cxxtest/TestSuite.h>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include "ListArrayWrapper.cpp"
#include "ListArray.cpp"

class textTest : public CxxTest::TestSuite{
    public:
	// Should probably seed a testwide random number generator

	void testDefaultConstructor1() {
            // Create a default ListArrayWrapper object and check vars
	    ListArrayWrapper<int> lst;

	    //Test Postconditions
	    //TSM_ASSERT_EQUALS(lst.getMaxSize(), List<int>::MAX_LIST_SIZE);
	    TSM_ASSERT_EQUALS("hint: constructor sets max size incorrectly", 
	                      lst.getMaxSize(), List<int>::defaultMaxSize);
	    TSM_ASSERT_EQUALS("hint: constructor sets size incorrectly", lst.getSize(), 0);
	    TSM_ASSERT_EQUALS("hint: empty list should have cursor at -1", lst.getCursorLocation(), -1);
	}

	void testParameterizedConstructor1() {
            // Create a ListArrayWrapper object and check vars
	    ListArrayWrapper<int> lst(1);

	    //Test Postconditions
	    TSM_ASSERT_EQUALS("hint: constructor sets max size incorrectly", lst.getMaxSize(), 1);
	    TSM_ASSERT_EQUALS("hint: constructor sets size incorrectly", lst.getSize(), 0);
	    TSM_ASSERT_EQUALS("hint: empty list cursor should be -1", lst.getCursorLocation(), -1);
	}

	void testParameterizedConstructor2() {
            // Create a ListArrayWrapper object and check vars
	    ListArrayWrapper<int> lst(111);

	    //Test Postconditions
	    TSM_ASSERT_EQUALS("hint: constructor sets max size incorrectly", lst.getMaxSize(), 111);
	    TSM_ASSERT_EQUALS("hint: constructors sets size incorrectly", lst.getSize(), 0);
	    TSM_ASSERT_EQUALS("hint: empty list cursor should be -1", lst.getCursorLocation(), -1);
	}

	void testCopyConstructor1() {
            // Create a ListArrayWrapper object and check vars
	    ListArrayWrapper<int> lst(5);
	    // Could randomize these
	    lst.add(3);
	    lst.add(2);
	    lst.add(1);
	    ListArrayWrapper<int> list2(lst);

	    //Test Postconditions
	    int* dataItems = list2.getDataItems();
	    TSM_ASSERT_EQUALS("hint: copy constructor data is incorrect", dataItems[0], 3);
	    TSM_ASSERT_EQUALS("hint: copy constructor data is incorrect", dataItems[1], 2);
	    TSM_ASSERT_EQUALS("hint: copy constructor data is incorrect", dataItems[2], 1);

	    int maxSize = list2.getMaxSize();
	    int size = list2.getSize();
	    int cursor = list2.getCursorLocation();
	    TSM_ASSERT_EQUALS("hint: copy constructor sets max size incorrectly", maxSize>=5, true);
	    TSM_ASSERT_EQUALS("hint: copy constructor sets size incorrectly", size, 3);
	    TSM_ASSERT_EQUALS("hint: copy constructor sets cursor incorrectly", cursor, 2);
	}

	void testAssignmentOperator() {
            // Create a ListArrayWrapper object and check vars
	    ListArrayWrapper<int> list(5);
	    list.add(7);
	    list.add(11);
	    list.add(-4);
	    ListArrayWrapper<int> list2(5);
	    list2 = list;

	    //Test Postconditions
	    int* dataItems = list2.getDataItems();
	    TSM_ASSERT_EQUALS("hint: operator= copies data incorrectly", dataItems[0], 7);
	    TSM_ASSERT_EQUALS("hint: operator= copies data incorrectly", dataItems[1], 11);
	    TSM_ASSERT_EQUALS("hint: operator= copies data incorrectly", dataItems[2], -4);

	    int maxSize = list2.getMaxSize();
	    int size = list2.getSize();
	    int cursor = list2.getCursorLocation();
	    TSM_ASSERT_EQUALS("hint: operator= sets max size incorrectly", maxSize>=5, true);
	    TSM_ASSERT_EQUALS("hint: operator= sets size incorrectly", size, 3);
	    TSM_ASSERT_EQUALS("hint: operator= sets cursor incorrectly", cursor, 2);
	}

	void testaddOneItem() {
            // Create a ListArrayWrapper object and check vars
	    ListArrayWrapper<int> list(5);
	    list.add(42);

	    //Test Postconditions
	    int* dataItems = list.getDataItems();
	    TSM_ASSERT_EQUALS("hint: add adds first item incorrectly", dataItems[0], 42);

	    int maxSize = list.getMaxSize();
	    int size = list.getSize();
	    int cursor = list.getCursorLocation();
	    TSM_ASSERT_EQUALS("hint: add should not modify max size", maxSize==5, true);
	    TSM_ASSERT_EQUALS("hint: add sets size incorrectly", size, 1);
	    TSM_ASSERT_EQUALS("hint: add sets cursor incorrectly", cursor, 0);
	}

	void testaddThreeItems() {
            // Create a ListArrayWrapper object and check vars
	    ListArrayWrapper<int> list(5);
	    list.add(74);
	    list.add(9);
	    list.add(22);

	    //Test Postconditions
	    int* dataItems = list.getDataItems();
	    TSM_ASSERT_EQUALS("hint: add does not place data correctly in array", dataItems[0], 74);
	    TSM_ASSERT_EQUALS("hint: add does not place data correctly in array", dataItems[1], 9);
	    TSM_ASSERT_EQUALS("hint: add does not place data correctly in array", dataItems[2], 22);

	    int maxSize = list.getMaxSize();
	    int size = list.getSize();
	    int cursor = list.getCursorLocation();
	    TSM_ASSERT_EQUALS("hint: add should not modify max size", maxSize>=5, true);
	    TSM_ASSERT_EQUALS("hint: add sets size incorrectly", size, 3);
	    TSM_ASSERT_EQUALS("hint: add sets cursor incorrectly", cursor, 2);
	}

	void testaddTooManyItems() {
            // Create a ListArrayWrapper object and check vars
	    ListArrayWrapper<int> list(5);
	    list.add(74);
	    list.add(9);
	    list.add(22);
	    list.add(1);
	    list.add(27);
	    TSM_ASSERT_THROWS("hint: add does not deal with a full list correctly", list.add(99), logic_error);

	    //Test Postconditions
	    int* dataItems = list.getDataItems();
	    TSM_ASSERT_EQUALS("hint: add should not modify a full list", dataItems[0], 74);
	    TSM_ASSERT_EQUALS("hint: add should not modify a full list", dataItems[1], 9);
	    TSM_ASSERT_EQUALS("hint: add should not modify a full list", dataItems[2], 22);
	    TSM_ASSERT_EQUALS("hint: add should not modify a full list", dataItems[3],  1);
	    TSM_ASSERT_EQUALS("hint: add should not modify a full list", dataItems[4], 27);

	    int maxSize = list.getMaxSize();
	    int size = list.getSize();
	    int cursor = list.getCursorLocation();
	    TSM_ASSERT_EQUALS("hint: add should not modify max size", maxSize==5, true);
	    TSM_ASSERT_EQUALS("hint: add should not modify a full list", size, 5);
	    TSM_ASSERT_EQUALS("hint: add should not modify a full list", cursor, 4);
	}

	void testRemoveFirstItem() {
            // Create a ListArrayWrapper object and check vars
	    ListArrayWrapper<int> list(5);
	    list.add(17);
	    list.add(55);
	    list.add(2);
	    list.gotoBeginning();
	    TSM_ASSERT_THROWS_NOTHING("hint: remove should not throw an exception for non-empty list", list.remove());

	    //Test Postconditions
	    int maxSize = list.getMaxSize();
	    int size = list.getSize();
	    int cursor = list.getCursorLocation();
	    TSM_ASSERT_EQUALS("hint: remove should not modify max size", maxSize==5, true);
	    TSM_ASSERT_EQUALS("hint: remove does not modify size correctly", size, 2);
	    TSM_ASSERT_EQUALS("hint: remove does not reposition cursor correctly in all cases", cursor, 0);

	    int* dataItems = list.getDataItems();
	    TSM_ASSERT_EQUALS("hint: remove does not move existing data correctly", dataItems[0], 55);
	    TSM_ASSERT_EQUALS("hint: remove does not move existing data correctly", dataItems[1], 2);
	}

	void testRemoveMiddleItem() {
            // Create a ListArrayWrapper object and check vars
	    ListArrayWrapper<int> list(5);
	    list.add(17);
	    list.add(55);
	    list.add(2);
	    list.gotoBeginning();
	    list.gotoNext();
	    TSM_ASSERT_THROWS_NOTHING("hint: remove should not throw exception for non-empty list", list.remove());

	    //Test Postconditions
	    int maxSize = list.getMaxSize();
	    int size = list.getSize();
	    int cursor = list.getCursorLocation();
	    TSM_ASSERT_EQUALS("hint: remove should not modify max size", maxSize==5, true);
	    TSM_ASSERT_EQUALS("hint: remove does not set size correctly", size, 2);
	    TSM_ASSERT_EQUALS("hint: remove does not set cursor correctly", cursor, 1);

	    int* dataItems = list.getDataItems();
	    TSM_ASSERT_EQUALS("hint: remove does not move existing data correctly", dataItems[0], 17);
	    TSM_ASSERT_EQUALS("hint: remove does not move existing data correctly", dataItems[1], 2);
	}

	void testRemoveLastItem() {
            // Create a ListArrayWrapper object and check vars
	    ListArrayWrapper<int> list(5);
	    list.add(17);
	    list.add(55);
	    list.add(2);
	    TSM_ASSERT_THROWS_NOTHING("hint: remove should not throw exception for non-empty list", list.remove());

	    //Test Postconditions
	    int maxSize = list.getMaxSize();
	    int size = list.getSize();
	    int cursor = list.getCursorLocation();
	    TSM_ASSERT_EQUALS("hint: remove should not modify max size", maxSize==5, true);
	    TSM_ASSERT_EQUALS("hint: remove does not set size correctly", size, 2);
	    TSM_ASSERT_EQUALS("hint: remove does not set cursor correctly", cursor, 0);

	    int* dataItems = list.getDataItems();
	    TSM_ASSERT_EQUALS("hint: remove does not move existing data correctly", dataItems[0], 17);
	    TSM_ASSERT_EQUALS("hint: remove does not move existing data correctly", dataItems[1], 55);
	}

	void testRemoveFromEmptyList() {
            // Create a ListArrayWrapper object and check vars
	    ListArrayWrapper<int> list(5);
	    TSM_ASSERT_THROWS("hint: remove should throw an exception an empty list", list.remove(), logic_error);

	    //Test Postconditions
	    int maxSize = list.getMaxSize();
	    int size = list.getSize();
	    int cursor = list.getCursorLocation();
	    TSM_ASSERT_EQUALS("hint: remove should not modify max size", maxSize==5, true);
	    TSM_ASSERT_EQUALS("hint: remove should not modify empty list", size, 0);
	    TSM_ASSERT_EQUALS("hint: remove should not modify empty list", cursor, -1);
	}

	void testReplaceFirstItem() {
            // Create a ListArrayWrapper object and check vars
	    ListArrayWrapper<int> list(5);
	    list.add(17);
	    list.add(55);
	    list.add(2);
	    list.gotoBeginning();
	    TSM_ASSERT_THROWS_NOTHING("hint: replace should not throw exception for non-empty list", list.replace(85));

	    //Test Postconditions
	    int maxSize = list.getMaxSize();
	    int size = list.getSize();
	    int cursor = list.getCursorLocation();
	    TSM_ASSERT_EQUALS("hint: replace should not modify max size", maxSize==5, true);
	    TSM_ASSERT_EQUALS("hint: replace should not modify size", size, 3);
	    TSM_ASSERT_EQUALS("hint: replace should not modify cursor", cursor, 0);

	    int* dataItems = list.getDataItems();
	    TSM_ASSERT_EQUALS("hint: replace does not modify data correctly", dataItems[0], 85);
	    TSM_ASSERT_EQUALS("hint: replace does not modify data correctly", dataItems[1], 55);
	    TSM_ASSERT_EQUALS("hint: replace does not modify data correctly", dataItems[2], 2);
	}

	void testReplaceMiddleItem() {
            // Create a ListArrayWrapper object and check vars
	    ListArrayWrapper<int> list(5);
	    list.add(17);
	    list.add(55);
	    list.add(2);
	    list.gotoBeginning();
	    list.gotoNext();
	    TSM_ASSERT_THROWS_NOTHING("hint: replace should not throw exception for non-empty list", list.replace(-11));

	    //Test Postconditions
	    int maxSize = list.getMaxSize();
	    int size = list.getSize();
	    int cursor = list.getCursorLocation();
	    TSM_ASSERT_EQUALS("hint: replace should not modify max size", maxSize==5, true);
	    TSM_ASSERT_EQUALS("hint: replace should not modify size", size, 3);
	    TSM_ASSERT_EQUALS("hint: replace should not modify cursor", cursor, 1);

	    int* dataItems = list.getDataItems();
	    TSM_ASSERT_EQUALS("hint: replace does not modify data correctly", dataItems[0], 17);
	    TSM_ASSERT_EQUALS("hint: replace does not modify data correctly", dataItems[1], -11);
	    TSM_ASSERT_EQUALS("hint: replace does not modify data correctly", dataItems[2], 2);
	}

	void testReplaceLastItem() {
            // Create a ListArrayWrapper object and check vars
	    ListArrayWrapper<int> list(5);
	    list.add(17);
	    list.add(55);
	    list.add(2);
	    TSM_ASSERT_THROWS_NOTHING("hint: replace should not throw exception for non-empty list", list.replace(29));

	    //Test Postconditions
	    int maxSize = list.getMaxSize();
	    int size = list.getSize();
	    int cursor = list.getCursorLocation();
	    TSM_ASSERT_EQUALS("hint: replace should not modify max size", maxSize==5, true);
	    TSM_ASSERT_EQUALS("hint: replace should not modify size", size, 3);
	    TSM_ASSERT_EQUALS("hint: replace should not modify cursor", cursor, 2);

	    int* dataItems = list.getDataItems();
	    TSM_ASSERT_EQUALS("hint: replace does not modify data correctly", dataItems[0], 17);
	    TSM_ASSERT_EQUALS("hint: replace does not modify data correctly", dataItems[1], 55);
	    TSM_ASSERT_EQUALS("hint: replace does not modify data correctly", dataItems[2], 29);
	}

	void testReplaceFromEmptyList() {
            // Create a ListArrayWrapper object and check vars
	    ListArrayWrapper<int> list(5);
	    TSM_ASSERT_THROWS("hint: replace should throw exception for empty list", list.replace(38), logic_error);

	    //Test Postconditions
	    int maxSize = list.getMaxSize();
	    int size = list.getSize();
	    int cursor = list.getCursorLocation();
	    TSM_ASSERT_EQUALS("hint: replace should not modify max size", maxSize==5, true);
	    TSM_ASSERT_EQUALS("hint: replace should not modify size", size, 0);
	    TSM_ASSERT_EQUALS("hint: replace should not modify cursor", cursor, -1);
	}

	void testClearEmptyList() {
            // Create a ListArrayWrapper object and check vars
	    ListArrayWrapper<int> list(5);
	    list.clear();

	    //Test Postconditions
	    int maxSize = list.getMaxSize();
	    int size = list.getSize();
	    int cursor = list.getCursorLocation();
	    TSM_ASSERT_EQUALS("hint: clear should not modify max size", maxSize==5, true);
	    TSM_ASSERT_EQUALS("hint: clear does not set size correctly", size, 0);
	    TSM_ASSERT_EQUALS("hint: clear does not set cursor correctly", cursor, -1);
	}

	void testClearPartlyFullList() {
            // Create a ListArrayWrapper object and check vars
	    ListArrayWrapper<int> list(5);
	    list.add(7);
	    list.add(97);
	    list.clear();

	    //Test Postconditions
	    int maxSize = list.getMaxSize();
	    int size = list.getSize();
	    int cursor = list.getCursorLocation();
	    TSM_ASSERT_EQUALS("hint: clear should not modify max size", maxSize==5, true);
	    TSM_ASSERT_EQUALS("hint: clear does not set size correctly", size, 0);
	    TSM_ASSERT_EQUALS("hint: clear does not set cursor correctly", cursor, -1);
	}

	void testClearFullList() {
            // Create a ListArrayWrapper object and check vars
	    ListArrayWrapper<int> list(2);
	    list.add(7);
	    list.add(97);
	    list.clear();

	    //Test Postconditions
	    int maxSize = list.getMaxSize();
	    int size = list.getSize();
	    int cursor = list.getCursorLocation();
	    TSM_ASSERT_EQUALS("hint: clear should not modify max size", maxSize==2, true);
	    TSM_ASSERT_EQUALS("hint: clear does not set size correctly", size, 0);
	    TSM_ASSERT_EQUALS("hint: clear does not set cursor correctly", cursor, -1);
	}

	void testIsEmptyInEmptyList() {
            // Create a ListArrayWrapper object and check vars
	    ListArrayWrapper<int> list(5);

	    //Test Postconditions
	    TSM_ASSERT_EQUALS("hint: isEmpty incorrectly reports not empty", list.isEmpty(), true);
	}

	void testIsEmptyInNonEmptyList() {
            // Create a ListArrayWrapper object and check vars
	    ListArrayWrapper<int> list(5);
	    list.add(1);

	    //Test Postconditions
	    TSM_ASSERT_EQUALS("hint: isEmpty incorrectly reports empty", list.isEmpty(), false);
	}

	void testIsEmptyInFullList() {
            // Create a ListArrayWrapper object and check vars
	    ListArrayWrapper<int> list(2);
	    list.add(1);
	    list.add(3);

	    //Test Postconditions
	    TSM_ASSERT_EQUALS("hint: isEmpty incorrectly reports empty", list.isEmpty(), false);
	}

	void testIsFullInEmptyList() {
            // Create a ListArrayWrapper object and check vars
	    ListArrayWrapper<int> list(5);

	    //Test Postconditions
	    TSM_ASSERT_EQUALS("hint: isFull incorrectly reports full", list.isFull(), false);
	}

	void testIsFullInNonEmptyList() {
            // Create a ListArrayWrapper object and check vars
	    ListArrayWrapper<int> list(5);
	    list.add(1);

	    //Test Postconditions
	    TSM_ASSERT_EQUALS("hint: isFull incorrectly reports full", list.isFull(), false);
	}

	void testIsFullInFullList() {
            // Create a ListArrayWrapper object and check vars
	    ListArrayWrapper<int> list(2);
	    list.add(1);
	    list.add(3);

	    //Test Postconditions
	    TSM_ASSERT_EQUALS("hint: isFull incorrectly reports not full", list.isFull(), true);
	}

	void testGoToBeginningInEmptyList() {
            // Create a ListArrayWrapper object and check vars
	    ListArrayWrapper<int> list(5);

	    //Test Postconditions
	    TSM_ASSERT_THROWS("hint: gotoBeginning should throw exception with empty list", list.gotoBeginning(), logic_error);

	    int maxSize = list.getMaxSize();
	    int size = list.getSize();
	    int cursor = list.getCursorLocation();
	    TSM_ASSERT_EQUALS("hint: gotoBeginning should not modify maxSize", maxSize==5, true);
	    TSM_ASSERT_EQUALS("hint: gotoBeginning should not modify size", size, 0);
	    TSM_ASSERT_EQUALS("hint: gotoBeginning incorrectly not modify cursor if throws exception", cursor, -1);
	}

	void testGoToBeginningInOneItemList() {
            // Create a ListArrayWrapper object and check vars
	    ListArrayWrapper<int> list2(5);
	    list2.add(6);

	    //Test Postconditions
	    TSM_ASSERT_THROWS_NOTHING("hint: gotoBeginning should not throw exception for non-empty list", list2.gotoBeginning());

	    int maxSize = list2.getMaxSize();
	    int size = list2.getSize();
	    int cursor = list2.getCursorLocation();
	    TSM_ASSERT_EQUALS("hint: gotoBeginning should not modify max size", maxSize==5, true);
	    TSM_ASSERT_EQUALS("hint: gotoBeginning should not modify size", size, 1);
	    TSM_ASSERT_EQUALS("hint: gotoBeginning does not set cursor correctly", cursor, 0);
	}

	void testGoToBeginningInMultiItemList() {
            // Create a ListArrayWrapper object and check vars
	    ListArrayWrapper<int> list3(5);
	    list3.add(6);
	    list3.add(27);
	    list3.add(5);

	    //Test Postconditions
	    TSM_ASSERT_THROWS_NOTHING("hint: gotoBeginning should not throw exception for non-empty list", list3.gotoBeginning());

	    int maxSize = list3.getMaxSize();
	    int size = list3.getSize();
	    int cursor = list3.getCursorLocation();
	    TSM_ASSERT_EQUALS("hint: gotoBeginning should not modify max size", maxSize==5, true);
	    TSM_ASSERT_EQUALS("hint: gotoBeginning should not modify size", size, 3);
	    TSM_ASSERT_EQUALS("hint: gotoBeginning does not set cursor correctly", cursor, 0);
	}

	void testGoToEndInEmptyList() {
            // Create a ListArrayWrapper object and check vars
	    ListArrayWrapper<int> list(5);

	    //Test Postconditions
	    TSM_ASSERT_THROWS("hint: gotoEnd should throw exception for empty list", list.gotoEnd(), logic_error);

	    int maxSize = list.getMaxSize();
	    int size = list.getSize();
	    int cursor = list.getCursorLocation();
	    TSM_ASSERT_EQUALS("hint: gotoEnd should not modify max size", maxSize==5, true);
	    TSM_ASSERT_EQUALS("hint: gotoEnd should not modify size", size, 0);
	    TSM_ASSERT_EQUALS("hint: gotoEnd should not change cursor for empty list", cursor, -1);
	//}

	//void testGoToEndInOneItemList() {
            // Create a ListArrayWrapper object and check vars
	    ListArrayWrapper<int> list2(5);
	    list2.add(6);

	    //Test Postconditions
	    TSM_ASSERT_THROWS_NOTHING("hint: gotoEnd should not throw exception for non-empty list", list2.gotoEnd());

	    maxSize = list2.getMaxSize();
	    size = list2.getSize();
	    cursor = list2.getCursorLocation();
	    TSM_ASSERT_EQUALS("hint: gotoEnd should not modify max size", maxSize==5, true);
	    TSM_ASSERT_EQUALS("hint: gotoEnd should not modify size", size, 1);
	    TSM_ASSERT_EQUALS("hint: gotoEnd does not set cursor correctly", cursor, 0);
	//}

	//void testGoToEndInMultiItemList() {
            // Create a ListArrayWrapper object and check vars
	    ListArrayWrapper<int> list3(5);
	    list3.add(6);
	    list3.add(27);
	    list3.add(5);
	    list3.setCursorLocation(0);

	    //Test Postconditions
	    TSM_ASSERT_THROWS_NOTHING("hint: gotoEnd should not throw exception for non-empty list", list3.gotoEnd());

	    maxSize = list3.getMaxSize();
	    size = list3.getSize();
	    cursor = list3.getCursorLocation();
	    TSM_ASSERT_EQUALS("hint: gotoEnd should not modify max size", maxSize==5, true);
	    TSM_ASSERT_EQUALS("hint: gotoEnd should not modify size", size, 3);
	    TSM_ASSERT_EQUALS("hint: gotoEnd does not set cursor correctly", cursor, 2);
	}

	void testGoToNextInEmptyList() {
            // Create a ListArrayWrapper object and check vars
	    ListArrayWrapper<int> list(5);

	    //Test Postconditions
	    // None

	    int maxSize = list.getMaxSize();
	    int size = list.getSize();
	    int cursor = list.getCursorLocation();
	    TSM_ASSERT_EQUALS("hint: gotoNext should not modify max size", maxSize==5, true);
	    TSM_ASSERT_EQUALS("hint: gotoNext should not modify size", size, 0);
	    TSM_ASSERT_EQUALS("hint: gotoNext should not modify cursor for empty list", cursor, -1);
	//}

	//void testGoToNextInOneItemList() {
            // Create a ListArrayWrapper object and check vars
	    ListArrayWrapper<int> list2(5);
	    list2.add(6);

	    //Test Postconditions
	    //TSM_ASSERT_EQUALS("hint: gotoNext should not return true at end of list", list2.gotoNext()==false, true);
	    TSM_ASSERT_THROWS_NOTHING("hint: gotoNext should not throw exception at end of list", list2.gotoNext());
	    TSM_ASSERT("hint: gotoNext should not return true at end of list", list2.gotoNext()==false);

	    maxSize = list2.getMaxSize();
	    size = list2.getSize();
	    cursor = list2.getCursorLocation();
	    TSM_ASSERT_EQUALS("hint: gotoNext should not modify max size", maxSize==5, true);
	    TSM_ASSERT_EQUALS("hint: gotoNext should not modify size", size, 1);
	    TSM_ASSERT_EQUALS("hint: gotoNext should not modify cursor when at end of list", cursor, 0);
	//}

	//void testGoToNextInMultiItemList() {
            // Create a ListArrayWrapper object and check vars
	    ListArrayWrapper<int> list3(5);
	    list3.add(6);
	    list3.add(27);
	    list3.add(5);
	    list3.add(61);

	    //Test Postconditions
	    list3.setCursorLocation(0);
	    TSM_ASSERT_EQUALS("hint: gotoNext should return true when cursor can be advanced", list3.gotoNext()==true, true);
	    list3.setCursorLocation(1);
	    TSM_ASSERT_EQUALS("hint: gotoNext should return true when cursor can be advanced", list3.gotoNext()==true, true);
	    list3.setCursorLocation(2);
	    TSM_ASSERT_EQUALS("hint: gotoNext should return true when cursor can be advanced", list3.gotoNext()==true, true);
	    list3.setCursorLocation(3);
	    TSM_ASSERT_THROWS_NOTHING("hint: gotoNext should not throw exception at end of list", list3.gotoNext());
	    TSM_ASSERT_EQUALS("hint: gotoNext should return false when cursor cannot be advanced", list3.gotoNext()==false, true);

	    maxSize = list3.getMaxSize();
	    size = list3.getSize();
	    cursor = list3.getCursorLocation();
	    TSM_ASSERT_EQUALS("hint: gotoNext should not modify max size", maxSize==5, true);
	    TSM_ASSERT_EQUALS("hint: gotoNext should not modify size", size, 4);
	    TSM_ASSERT_EQUALS("hint: gotoNext does not set cursor correctly", cursor, 3);
	}

	void testGoToPriorInEmptyList() {
            // Create a ListArrayWrapper object and check vars
	    ListArrayWrapper<int> list(5);

	    //Test Postconditions
	    // None

	    int maxSize = list.getMaxSize();
	    int size = list.getSize();
	    int cursor = list.getCursorLocation();
	    TSM_ASSERT_EQUALS("hint: gotoPrior should not modify max size", maxSize==5, true);
	    TSM_ASSERT_EQUALS("hint: gotoPrior should not modify size", size, 0);
	    TSM_ASSERT_EQUALS("hint: gotoPrior should not change cursor for empty list", cursor, -1);
	//}

	//void testGoToPriorInOneItemList() {
            // Create a ListArrayWrapper object and check vars
	    ListArrayWrapper<int> list2(5);
	    list2.add(6);

	    //Test Postconditions
	    TSM_ASSERT_THROWS_NOTHING("hint: gotoPrior should not throw exception at beginning of list", list2.gotoPrior());
	    TSM_ASSERT("hint: gotoPrior should return false at beginning of list", list2.gotoPrior()==false);

	    maxSize = list2.getMaxSize();
	    size = list2.getSize();
	    cursor = list2.getCursorLocation();
	    TSM_ASSERT_EQUALS("hint: gotoPrior should not modify max size", maxSize==5, true);
	    TSM_ASSERT_EQUALS("hint: gotoPrior should not modify size", size, 1);
	    TSM_ASSERT_EQUALS("hint: gotoPrior should not change cursor when at beginning of list", cursor, 0);
	//}

	//void testGoToPriorInMultiItemList() {
            // Create a ListArrayWrapper object and check vars
	    ListArrayWrapper<int> list3(5);
	    list3.add(6);
	    list3.add(27);
	    list3.add(5);
	    list3.add(61);

	    //Test Postconditions
	    list3.setCursorLocation(3);
	    TSM_ASSERT("hint: gotoPrior should return true when not at beginning of list", list3.gotoPrior()==true);
	    list3.setCursorLocation(2);
	    TSM_ASSERT("hint: gotoPrior should return true when not at beginning of list", list3.gotoPrior()==true);
	    list3.setCursorLocation(1);
	    TSM_ASSERT("hint: gotoPrior should return true when not at beginning of list", list3.gotoPrior()==true);
	    list3.setCursorLocation(0);
	    TSM_ASSERT_THROWS_NOTHING("hint: gotoPrior should not throw exception at beginning of list", list3.gotoPrior());
	    TSM_ASSERT("hint: gotoPrior should return false when at beginning of list", list3.gotoPrior()==false);

	    maxSize = list3.getMaxSize();
	    size = list3.getSize();
	    cursor = list3.getCursorLocation();
	    TSM_ASSERT_EQUALS("hint: gotoPrior should not modify max size", maxSize==5, true);
	    TSM_ASSERT_EQUALS("hint: gotoPrior should not modify size", size, 4);
	    TSM_ASSERT_EQUALS("hint: gotoPrior does not correctly set cursor", cursor, 0);
	}

	void testgetCursorInEmptyList() {
            // Create a ListArrayWrapper object and check vars
	    ListArrayWrapper<int> list(5);

	    //Test Postconditions
	    TSM_ASSERT_THROWS("hint: getCursor should throw exception for empty list", list.getCursor(), logic_error);

	    int maxSize = list.getMaxSize();
	    int size = list.getSize();
	    int cursor = list.getCursorLocation();
	    TSM_ASSERT_EQUALS("hint: getCursor should not modify max size", maxSize==5, true);
	    TSM_ASSERT_EQUALS("hint: getCursor should not modify size", size, 0);
	    TSM_ASSERT_EQUALS("hint: getCursor should not modify cursor", cursor, -1);
	//}

	//void testgetCursorInNonEmptyList() {
            // Create a ListArrayWrapper object and check vars
	    ListArrayWrapper<int> list2(5);
	    list2.add(49);
	    list2.add(29);
	    list2.add(16);
	    list2.setCursorLocation(1);

	    //Test Postconditions
	    TSM_ASSERT_EQUALS("hint: getCursor returns incorrect value", list2.getCursor(), 29);

	    maxSize = list2.getMaxSize();
	    size = list2.getSize();
	    cursor = list2.getCursorLocation();
	    TSM_ASSERT_EQUALS("hint: getCursor should not modify max size", maxSize==5, true);
	    TSM_ASSERT_EQUALS("hint: getCursor should not modify size", size, 3);
	    TSM_ASSERT_EQUALS("hint: getCursor should not modify cursor", cursor, 1);
	}

};

#endif   // ifndef __INSTRUCTOR__LISTARRAY_TEST_H
