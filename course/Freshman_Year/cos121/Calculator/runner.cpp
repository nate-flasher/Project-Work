/* Generated file, do not edit */

#ifndef CXXTEST_RUNNING
#define CXXTEST_RUNNING
#endif

#define _CXXTEST_HAVE_STD
#include <cxxtest/TestListener.h>
#include <cxxtest/TestTracker.h>
#include <cxxtest/TestRunner.h>
#include <cxxtest/RealDescriptions.h>
#include <cxxtest/ErrorPrinter.h>

int main() {
 return CxxTest::ErrorPrinter().run();
}
#include "Calculator_test.h"

static Instructor__test suite_Instructor__test;

static CxxTest::List Tests_Instructor__test = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_Instructor__test( "Calculator_test.h", 18, "Instructor__test", suite_Instructor__test, Tests_Instructor__test );

static class TestDescription_Instructor__test_testInitial : public CxxTest::RealTestDescription {
public:
 TestDescription_Instructor__test_testInitial() : CxxTest::RealTestDescription( Tests_Instructor__test, suiteDescription_Instructor__test, 23, "testInitial" ) {}
 void runTest() { suite_Instructor__test.testInitial(); }
} testDescription_Instructor__test_testInitial;

static class TestDescription_Instructor__test_testSetValue1 : public CxxTest::RealTestDescription {
public:
 TestDescription_Instructor__test_testSetValue1() : CxxTest::RealTestDescription( Tests_Instructor__test, suiteDescription_Instructor__test, 31, "testSetValue1" ) {}
 void runTest() { suite_Instructor__test.testSetValue1(); }
} testDescription_Instructor__test_testSetValue1;

static class TestDescription_Instructor__test_testClear : public CxxTest::RealTestDescription {
public:
 TestDescription_Instructor__test_testClear() : CxxTest::RealTestDescription( Tests_Instructor__test, suiteDescription_Instructor__test, 40, "testClear" ) {}
 void runTest() { suite_Instructor__test.testClear(); }
} testDescription_Instructor__test_testClear;

static class TestDescription_Instructor__test_testAdd : public CxxTest::RealTestDescription {
public:
 TestDescription_Instructor__test_testAdd() : CxxTest::RealTestDescription( Tests_Instructor__test, suiteDescription_Instructor__test, 50, "testAdd" ) {}
 void runTest() { suite_Instructor__test.testAdd(); }
} testDescription_Instructor__test_testAdd;

static class TestDescription_Instructor__test_testSubtract : public CxxTest::RealTestDescription {
public:
 TestDescription_Instructor__test_testSubtract() : CxxTest::RealTestDescription( Tests_Instructor__test, suiteDescription_Instructor__test, 62, "testSubtract" ) {}
 void runTest() { suite_Instructor__test.testSubtract(); }
} testDescription_Instructor__test_testSubtract;

static class TestDescription_Instructor__test_testMultiply : public CxxTest::RealTestDescription {
public:
 TestDescription_Instructor__test_testMultiply() : CxxTest::RealTestDescription( Tests_Instructor__test, suiteDescription_Instructor__test, 73, "testMultiply" ) {}
 void runTest() { suite_Instructor__test.testMultiply(); }
} testDescription_Instructor__test_testMultiply;

static class TestDescription_Instructor__test_testdivideBy : public CxxTest::RealTestDescription {
public:
 TestDescription_Instructor__test_testdivideBy() : CxxTest::RealTestDescription( Tests_Instructor__test, suiteDescription_Instructor__test, 84, "testdivideBy" ) {}
 void runTest() { suite_Instructor__test.testdivideBy(); }
} testDescription_Instructor__test_testdivideBy;

#include <cxxtest/Root.cpp>
