#ifndef STRING_TEST_H
#define STRING_TEST_H

#include <cxxtest/TestSuite.h>
#include <iostream>
#include <string>
#include <cstring>

#include "StringWrapper.h"

class textTest : public CxxTest::TestSuite{
    public:
	
	void testDefaultConstructor() {
	    //Testing:  String( )
	    //Run Function and do setup
	    StringWrapper testString;

	    //Test Postconditions
	    //  Make sure that buffer contains an empty string
	    TS_ASSERT_EQUALS(strcmp(testString.getBuffer(), ""), 0);
	    //  Make sure that buffer size is 1 for empty string
	    TS_ASSERT_EQUALS(testString.getBufferSize(), 1);
	}

	void testCopyConstructor() {
	    //Testing:  String( const String &other )
	    //Run Function and do setup
	    StringWrapper testString("Hello");
	    StringWrapper testString2(testString);

	    //Test Postconditions
	    // Buffers should be same size
	    TS_ASSERT_EQUALS(testString.getBufferSize(), testString2.getBufferSize());
	    // Buffers should be equivalent ...
	    TS_ASSERT_EQUALS(strcmp(testString.getBuffer(), testString2.getBuffer()), 0);
	    //    but not identical (did a deep copy).
	    TS_ASSERT_DIFFERS(testString.getBuffer(), testString2.getBuffer());
	}

	void testConversionConstructor() {
	    //Testing:  String ( const char *charSeq )
	    //Run Function and do setup
	    StringWrapper testString("Hello");

	    //Test Postconditions
	    //  Should have the right contents
	    TS_ASSERT_EQUALS(strcmp(testString.getBuffer(), "Hello"), 0);
	    //  Buffer should be correct size
	    TS_ASSERT_EQUALS(testString.getBufferSize(), 6);
	}

	void testAssignmentOperator() {
	    //Testing:  String& operator = ( const String &other )
	    //Run Function and do setup
	    StringWrapper testString("Hello");
	    StringWrapper testString2("Hi");
	    testString2 = testString;

	    //Test Postconditions
	    // Buffers should be equivalent ...
	    TS_ASSERT_EQUALS(strcmp(testString.getBuffer(), testString2.getBuffer()), 0);
	    //    but not identical.
	    TS_ASSERT_DIFFERS(testString.getBuffer(), testString2.getBuffer());
	    // Buffers should be same size
	    TS_ASSERT_EQUALS(testString.getBufferSize(), testString2.getBufferSize());
	}

	void testSetString() {
	    //Testing:  void set( String other );
	    //Run Function and do setup
	    StringWrapper testString("Hello");
	    StringWrapper testString2("Hi");
	    testString2.set(testString);

	    //Test Postconditions
	    // Buffers should be equivalent ...
	    TS_ASSERT_EQUALS(strcmp(testString.getBuffer(), testString2.getBuffer()), 0);
	    //    but not identical.
	    TS_ASSERT_DIFFERS(testString.getBuffer(), testString2.getBuffer());
	    // Buffers should be same size
	    TS_ASSERT_EQUALS(testString.getBufferSize(), testString2.getBufferSize());
	}

	void testSetCPPString() {
	    //Testing:  void set( string other );
	    //Run Function and do setup
	    String testString("Hello");
	    StringWrapper testString2("Hi");
	    testString2.set(testString);

	    //Test Postconditions
	    // Buffers should be equivalent ...
	    TS_ASSERT_EQUALS(strcmp(testString.c_str(), testString2.getBuffer()), 0);
	    //    but not identical.
	    TS_ASSERT_DIFFERS(testString.c_str(), testString2.getBuffer());
	    // Buffer should be correct size
	    TS_ASSERT_EQUALS(strlen(testString.c_str())+1, testString2.getBufferSize());
	}

	void testSetCString() {
	    //Testing:  void set( char *charSeq );
	    //Run Function and do setup
	    char testString [] = "Hello";
	    StringWrapper testString2("Hi");
	    testString2.set(testString);

	    //Test Postconditions
	    // Buffers should be equivalent ...
	    TS_ASSERT_EQUALS(strcmp(testString, testString2.getBuffer()), 0);
	    //    but not identical (did a deep copy).
	    TS_ASSERT_DIFFERS(testString, testString2.getBuffer());
	}

	void testClear() {
	    //Testing:  void clear()
	    //Run Function and do setup
	    StringWrapper testString("Hello");
	    testString.clear();

	    //Test Postconditions
	    TS_ASSERT_EQUALS(strcmp(testString.getBuffer(), ""), 0);
	}

	void test_c_str() {
	    //Testing:  const char* c_str() const
	    //Run Function and do setup
	    const char *str = "Hello";
	    StringWrapper testString2(str);
	    const char *testString = testString2.c_str();

	    //Test Postconditions
	    // Buffers should be equivalent ...
	    TS_ASSERT_EQUALS(strcmp(testString, testString2.getBuffer()), 0);
	    //    and identical (did not return a different C-string address, indicating possible memory leak)
	    TS_ASSERT_EQUALS(testString2.c_str(), testString2.getBuffer());
	}

	void testLength() {
	    //Testing:  int getLength() const
	    //Run Function and do setup
	    StringWrapper testString("Hello");
	    TS_ASSERT_EQUALS(testString.getLength(), 5);
	    StringWrapper testString2("");
	    TS_ASSERT_EQUALS(testString2.getLength(), 0);
	}

	void testIndexOperator() {
	    //Testing:  char operator[]( int n ) const
	    //Run Function and do setup
	    StringWrapper testString("Hello");

	    //Test Postconditions
	    TS_ASSERT_EQUALS(testString[0], 'H');
	    TS_ASSERT_EQUALS(testString[1], 'e');
	    TS_ASSERT_EQUALS(testString[2], 'l');
	    TS_ASSERT_EQUALS(testString[3], 'l');
	    TS_ASSERT_EQUALS(testString[4], 'o');
	    TS_ASSERT_EQUALS(testString[5], '\0');
	    //  And now test possibly missed casses
	    TS_ASSERT_EQUALS(testString[6], '\0');
	    TS_ASSERT_EQUALS(testString[10000], '\0');
	    TS_ASSERT_EQUALS(testString[-1], '\0');
	    TS_ASSERT_EQUALS(testString[-10000], '\0');

	    //Testing:  bool operator==( const String& other ) const
	    // Testing strings that are equivalent
	    //Run Function and do setup
	    StringWrapper testString1("Hello");
	    StringWrapper testString2("Hello");

	    //Test Postconditions
	    TS_ASSERT_EQUALS(testString1 == testString2, true);

	    // Testing strings that are not equivalent
	    //Run Function and do setup
	    StringWrapper testString3("Hello");	// Mixed case
	    StringWrapper testString4("hello");	// Different case

	    //Test Postconditions
	    TS_ASSERT_EQUALS(testString3 == testString4, false);

	    // Testing strings that are not same length
	    //Run Function and do setup
	    StringWrapper testString5("Hello");	
	    StringWrapper testString6("He");

	    //Test Postconditions
	    TS_ASSERT_EQUALS(testString5 == testString6, false);

	    // Testing with one empty string
	    //Run Function and do setup
	    StringWrapper testString7("Hello");	
	    StringWrapper testString8("");

	    //Test Postconditions
	    TS_ASSERT_EQUALS(testString7 == testString8, false);
	}

	void testOperatorEquals5() {
	    // Testing with two empty strings
	    //Run Function and do setup
	    StringWrapper testString1("");	
	    StringWrapper testString2("");

	    //Test Postconditions
	    TS_ASSERT_EQUALS(testString1 == testString2, true);
	}
};

#endif   // ifndef STRING_TEST_H
