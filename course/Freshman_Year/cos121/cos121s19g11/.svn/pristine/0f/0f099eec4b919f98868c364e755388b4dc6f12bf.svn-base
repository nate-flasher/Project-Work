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
	    int* dataItems = lst.getDataItems();

	    dataItems[0] = 3;
	    dataItems[1] = 2;
	    dataItems[2] = 1;
	    lst.setSize(3);
	    lst.setCursorLocation(2);
	    ListArrayWrapper<int> list2(lst);

	    //Test Postconditions
	    int maxSize = list2.getMaxSize();
	    int size = list2.getSize();
	    int cursor = list2.getCursorLocation();
	    TSM_ASSERT_EQUALS("hint: copy constructor sets max size incorrectly", maxSize, 5);
	    TSM_ASSERT_EQUALS("hint: copy constructor sets size incorrectly", size, 3);
	    TSM_ASSERT_EQUALS("hint: copy constructor sets cursor incorrectly", cursor, 2);

	    int* dataItems2 = list2.getDataItems();

	    TSM_ASSERT_EQUALS("hint: copy constructor data is incorrect", dataItems2[0], 3);
	    TSM_ASSERT_EQUALS("hint: copy constructor data is incorrect", dataItems2[1], 2);
	    TSM_ASSERT_EQUALS("hint: copy constructor data is incorrect", dataItems2[2], 1);
	    TSM_ASSERT_DIFFERS("hint: copy constructor is supposed to do a deep copy", dataItems, dataItems2);
	}

	void testAssignmentOperator() {
            // Create a ListArrayWrapper object and check vars
	    ListArrayWrapper<int> lst(5);
	    int* dataItems = lst.getDataItems();

	    dataItems[0] = 7;
	    dataItems[1] = 11;
	    dataItems[2] = -4;

	    lst.setSize(3);
	    lst.setCursorLocation(2);

	    ListArrayWrapper<int> list2(5);
	    list2 = lst;

	    //Test Postconditions
	    int* dataItems2 = list2.getDataItems();
	    TSM_ASSERT_EQUALS("hint: operator= copies data incorrectly", dataItems2[0], 7);
	    TSM_ASSERT_EQUALS("hint: operator= copies data incorrectly", dataItems2[1], 11);
	    TSM_ASSERT_EQUALS("hint: operator= copies data incorrectly", dataItems2[2], -4);
	    TSM_ASSERT_DIFFERS("hint: operator= is supposed to do a deep copy", dataItems, dataItems2);

	    int maxSize = list2.getMaxSize();
	    int size = list2.getSize();
	    int cursor = list2.getCursorLocation();
	    TSM_ASSERT("hint: operator= sets max size incorrectly", maxSize>=5);
	    TSM_ASSERT_EQUALS("hint: operator= sets size incorrectly", size, 3);
	    TSM_ASSERT_EQUALS("hint: operator= sets cursor incorrectly", cursor, 2);
	}

	void testGoToNext() {
            // Create a ListArrayWrapper object and check vars
	    ListArrayWrapper<int> list(5);

	    //Test Postconditions
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
	    TSM_ASSERT("hint: gotoNext cursor should be at zero", list3.getCursorLocation()==0);

	    TSM_ASSERT("hint: gotoNext should return true when cursor can be advanced", list3.gotoNext()==true);
	    list3.setCursorLocation(1);
	    TSM_ASSERT("hint: gotoNext should return true when cursor can be advanced", list3.gotoNext()==true);
	    list3.setCursorLocation(2);
	    TSM_ASSERT("hint: gotoNext should return true when cursor can be advanced", list3.gotoNext()==true);
	    list3.setCursorLocation(3);
	    TSM_ASSERT_THROWS_NOTHING("hint: gotoNext should not throw exception at end of list", list3.gotoNext());
	    TSM_ASSERT("hint: gotoNext should return false when cursor cannot be advanced", list3.gotoNext()==false);

	    maxSize = list3.getMaxSize();
	    size = list3.getSize();
	    cursor = list3.getCursorLocation();
	    TSM_ASSERT_EQUALS("hint: gotoNext should not modify max size", maxSize, 5);
	    TSM_ASSERT_EQUALS("hint: gotoNext should not modify size", size, 4);
	    TSM_ASSERT_EQUALS("hint: gotoNext does not set cursor correctly", cursor, 3);
	}

	void testGoToPrior() {
            // Create a ListArrayWrapper object and check vars
	    ListArrayWrapper<int> list(5);

	    //Test Postconditions
	    list.gotoPrior();

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

	void testGoToEnd() {
            // Create a ListArrayWrapper object and check vars
	    ListArrayWrapper<int> list(5);

	    //Test Postconditions
	    list.gotoEnd();

	    int maxSize = list.getMaxSize();
	    int size = list.getSize();
	    int cursor = list.getCursorLocation();
	    TSM_ASSERT_EQUALS("hint: gotoEnd should not modify max size", maxSize, 5);
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

	void testGoToBeginning() {
            // Create a ListArrayWrapper object and check vars
	    ListArrayWrapper<int> list(5);

	    //Test Postconditions
	    list.gotoBeginning();

	    int maxSize = list.getMaxSize();
	    int size = list.getSize();
	    int cursor = list.getCursorLocation();
	    TSM_ASSERT_EQUALS("hint: gotoBeginning should not modify maxSize", maxSize==5, true);
	    TSM_ASSERT_EQUALS("hint: gotoBeginning should not modify size", size, 0);
	    TSM_ASSERT_EQUALS("hint: gotoBeginning incorrectly not modify cursor if throws exception", cursor, -1);
	//}

	//void testGoToBeginningInOneItemList() {
            // Create a ListArrayWrapper object and check vars
	    ListArrayWrapper<int> list2(5);
	    list2.add(6);

	    //Test Postconditions
	    TSM_ASSERT_THROWS_NOTHING("hint: gotoBeginning should not throw exception for non-empty list", list2.gotoBeginning());

	    maxSize = list2.getMaxSize();
	    size = list2.getSize();
	    cursor = list2.getCursorLocation();
	    TSM_ASSERT_EQUALS("hint: gotoBeginning should not modify max size", maxSize==5, true);
	    TSM_ASSERT_EQUALS("hint: gotoBeginning should not modify size", size, 1);
	    TSM_ASSERT_EQUALS("hint: gotoBeginning does not set cursor correctly", cursor, 0);
	//}

	//void testGoToBeginningInMultiItemList() {
            // Create a ListArrayWrapper object and check vars
	    ListArrayWrapper<int> list3(5);
	    list3.add(6);
	    list3.add(27);
	    list3.add(5);

	    //Test Postconditions
	    TSM_ASSERT_THROWS_NOTHING("hint: gotoBeginning should not throw exception for non-empty list", list3.gotoBeginning());

	    maxSize = list3.getMaxSize();
	    size = list3.getSize();
	    cursor = list3.getCursorLocation();
	    TSM_ASSERT_EQUALS("hint: gotoBeginning should not modify max size", maxSize==5, true);
	    TSM_ASSERT_EQUALS("hint: gotoBeginning should not modify size", size, 3);
	    TSM_ASSERT_EQUALS("hint: gotoBeginning does not set cursor correctly", cursor, 0);
	}

	void testIsEmpty() {
            // Create a ListArrayWrapper object and check vars
	    ListArrayWrapper<int> list(5);

	    //Test Postconditions
	    TSM_ASSERT_EQUALS("hint: isEmpty incorrectly reports not empty", list.isEmpty(), true);
	//}

	//void testIsEmptyInNonEmptyList() {
            // Create a ListArrayWrapper object and check vars
	    ListArrayWrapper<int> list2(5);
	    list2.add(1);

	    //Test Postconditions
	    TSM_ASSERT_EQUALS("hint: isEmpty incorrectly reports empty", list2.isEmpty(), false);
	//}

	//void testIsEmptyInFullList() {
            // Create a ListArrayWrapper object and check vars
	    ListArrayWrapper<int> list3(2);
	    list3.add(1);
	    list3.add(3);

	    //Test Postconditions
	    TSM_ASSERT_EQUALS("hint: isEmpty incorrectly reports empty", list3.isEmpty(), false);
	}

	void testIsFull() {
            // Create a ListArrayWrapper object and check vars
	    ListArrayWrapper<int> list(5);

	    //Test Postconditions
	    TSM_ASSERT_EQUALS("hint: isFull incorrectly reports full", list.isFull(), false);
	//}

	//void testIsFullInNonEmptyList() {
            // Create a ListArrayWrapper object and check vars
	    ListArrayWrapper<int> list2(5);
	    list2.add(1);

	    //Test Postconditions
	    TSM_ASSERT_EQUALS("hint: isFull incorrectly reports full", list2.isFull(), false);
	//}

	//void testIsFullInFullList() {
            // Create a ListArrayWrapper object and check vars
	    ListArrayWrapper<int> list3(2);
	    list3.add(1);
	    list3.add(3);

	    //Test Postconditions
	    TSM_ASSERT_EQUALS("hint: isFull incorrectly reports not full", list3.isFull(), true);
	}

	void testGetCursorPosition() {
	    ListArrayWrapper<int> lst(5);

	    // Test postconditions
	    TSM_ASSERT_EQUALS("hint: getCursorPosition should return -1 when list is empty", lst.getCursorPosition(), -1);

	    // Setup preconditions
	    lst.add(random()%100);
	    lst.add(random()%100);
	    lst.add(random()%100);

	    // Test postconditions
	    TSM_ASSERT_EQUALS("hint: getCursorPosition should return the index of the node marked by cursor", lst.getCursorPosition(), 2);
	}

	void testGetSize() {
	    ListArrayWrapper<int> lst(5);

	    // Test postconditions
	    TSM_ASSERT_EQUALS("hint: size should be 0 when list is empty", lst.getSize(), 0);

	    // Setup preconditions
	    lst.add(random()%100);
	    lst.add(100+random()%100);
	    lst.add(200+random()%100);

	    // Test postconditions
	    TSM_ASSERT_EQUALS("hint: getCursorPosition should return a count of the number of items in the list", lst.getSize(), 3);
	}

	void testGetCursor() {
	    ListArrayWrapper<int> lst(5);

	    // Test postconditions
	    TSM_ASSERT_THROWS("hint: getCursor should throw exception with empty list", lst.getCursor(), logic_error);

	    // Setup preconditions
	    int num = random()%100;
	    lst.add(num);

	    // Test postconditions
	    TSM_ASSERT_EQUALS("hint: getCursor should return the data item marked by the cursor", lst.getCursor(), num);

	    // Setup preconditions
	    int num2 = random()%100;
	    lst.add(num2);

	    // Test postconditions
	    TSM_ASSERT_EQUALS("hint: getCursor should return the data item marked by the cursor", lst.getCursor(), num2);
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

	void testSearch() {
	    ListArrayWrapper<int> lst(15);
	    int first = -24;
	    int second = +1005;
	    TSM_ASSERT("hint: should not find something in empty list", lst.search(first)==false);
	    lst.add(first);

	    for(int i=0; i<10; i++){
		lst.add(10*i + random()%10);
	    }
	    lst.add(second);
	    int* dataItems = lst.getDataItems();
	    TSM_ASSERT("hint: missed first item in list", lst.search(first)==true);
	    TSM_ASSERT("hint: missed middle item in list", lst.search(dataItems[5])==true);
	    TSM_ASSERT("hint: missed last item in list", lst.search(second)==true);

	    TSM_ASSERT("hint: found an item that is not in list", lst.search(-104)==false);
	    TSM_ASSERT("hint: found an item that is not in list", lst.search(300+random()%100)==false);
	}

	void testRemove() {
	    ListArrayWrapper<int> lst(15);
	    TSM_ASSERT_THROWS("hint: remove() should throw logic_error on empty list", lst.remove(), logic_error);
	    lst.add(9);
	    lst.add(7);
	    lst.add(5);
	    lst.add(3);
	    lst.add(1);

	    lst.setCursorLocation(2);
	    int maxSize = lst.getMaxSize();
	    int size = lst.getSize();
	    int cursor = lst.getCursorLocation();
	    int* dataItems = lst.getDataItems();

	    TSM_ASSERT("hint: cursor location should be 2 after setting that", lst.getCursorLocation()==2);
	    lst.remove();

	    TSM_ASSERT("hint: remove() should not modify max size", maxSize==15);
	    TSM_ASSERT("hint: remove() should decrement size", size-1==lst.getSize());
	    TSM_ASSERT("hint: remove() should not modify the cursor location for non-final positions", cursor==lst.getCursorLocation());

	    TSM_ASSERT("hint: remove() should not have moved items to the left of cursor", dataItems[0]==9);
	    TSM_ASSERT("hint: remove() should not have moved items to the left of cursor", dataItems[1]==7);
	    TSM_ASSERT("hint: remove() should have moved over items to the right of cursor", dataItems[2]==3);
	    TSM_ASSERT("hint: remove() should have moved over items to the right of cursor", dataItems[3]==1);

	    lst.setCursorLocation(lst.getSize()-1);
	    maxSize = lst.getMaxSize();
	    size = lst.getSize();

	    lst.remove();

	    TSM_ASSERT("hint: remove() should not modify max size", maxSize==15);
	    TSM_ASSERT("hint: remove() should decrement size when removing last item", size-1==lst.getSize());
	    TSM_ASSERT("hint: remove() should set the cursor location to 0 when removing rightmost item in list", 0==lst.getCursorLocation());

	}

	void testReplace() {
	    ListArrayWrapper<int> lst(15);
	    TSM_ASSERT_THROWS("hint: replace() should throw logic_error on empty list", lst.replace(123), logic_error);

	    lst.add(9);
	    lst.add(7);
	    lst.add(5);
	    lst.add(3);
	    lst.add(1);
	    lst.setCursorLocation(2);
	    int maxSize = lst.getMaxSize();
	    int size = lst.getSize();
	    int cursor = lst.getCursorLocation();
	    int* dataItems = lst.getDataItems();

	    lst.replace(111);

	    TSM_ASSERT("hint: replace() should not modify max size", maxSize==15);
	    TSM_ASSERT("hint: replace() should not modify size", size==lst.getSize());
	    TSM_ASSERT("hint: replace() should not modify the cursor location", cursor==lst.getCursorLocation());

	    TSM_ASSERT("hint: remove() should not have changed items other than at cursor", dataItems[0]==9);
	    TSM_ASSERT("hint: remove() should not have changed items other than at cursor", dataItems[1]==7);
	    TSM_ASSERT("hint: remove() should not have changed items other than at cursor", dataItems[2]==111);
	    TSM_ASSERT("hint: remove() should not have changed items other than at cursor", dataItems[3]==3);
	    TSM_ASSERT("hint: remove() should not have changed items other than at cursor", dataItems[4]==1);
	}

	void testClear() {
	    ListArrayWrapper<int> lst(15);
	    TSM_ASSERT_THROWS_NOTHING("hint: clearing an empty list is not an error", lst.clear());

	    lst.add(9);
	    lst.add(7);
	    lst.add(5);
	    lst.add(3);
	    lst.add(1);
	    lst.setCursorLocation(2);
	    int maxSize = lst.getMaxSize();
	    int size = lst.getSize();

	    lst.clear();

	    TSM_ASSERT("hint: clear() should not modify max size", lst.getMaxSize()==15);
	    TSM_ASSERT("hint: clear() should set size to 0", lst.getSize()==0);
	    TSM_ASSERT("hint: clear() should set the cursor location to -1", lst.getCursorLocation()==-1);
	}
};

#endif   // ifndef __INSTRUCTOR__LISTARRAY_TEST_H
