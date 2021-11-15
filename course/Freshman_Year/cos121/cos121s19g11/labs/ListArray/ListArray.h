#ifndef LISTARRAY_H
#define LISTARRAY_H
/**
 * @author Stefan Brandle
 * @file ListArray.h
 * @brief Array-based List class declaration file.
 */

#include <stdexcept>

using namespace std;

template <typename DataType>
class List {
  public:
    static const int defaultMaxSize = 8;

    // Constructors, destructor, and related
    List();
    List(int maxItems);
    List(const List& other);
    virtual ~List();
    List& operator=(const List& other);

    // Iterators
    bool gotoNext();
    bool gotoPrior();
    void gotoBeginning() throw (logic_error);
    void gotoEnd() throw (logic_error);

    // Observers
    bool isEmpty() const;
    bool isFull() const;
    int getCursorPosition() const;
    int getSize() const;
    DataType getCursor() const throw (logic_error);
    DataType operator[]( int position ) const throw (logic_error);
    void showStructure() const;		// Debugging function

    // Transformers/mutators
    bool search(DataType value);
    void add( const DataType& newItem ) throw (logic_error);
    void add( const List& otherList ) throw (logic_error);
    void remove() throw (logic_error);
    void remove( const DataType& delItem );
    void replace( const DataType& replaceItem ) throw (logic_error);
    void clear();

  protected:
    // Data members
    int maxSize,		// Array size => maximum items in list
        size,			// Current number of items in list
	cursor;			// Current location of cursor
    DataType *dataItems;	// Pointer to array holding list items
};

#endif
