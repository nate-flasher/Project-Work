/**
 * checkout2.cpp: checkout queue simulator. Simulates running one checkout register with one
 * customer queue.
 *
 * Nate Flasher
 * 03-05-19
 *
 * Compile by typing "g++ -Wall checkout.cpp conio.cpp"
 */

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <unistd.h>
#include <ctime>
#include <list>
#include "conio.h"

#define PAUSE_TIME 1
/***********************************************************************
 * A struct is a way of "clustering/clumping" related variables so that they can be used 
 * as one unit when you assign or compare them.
 * The Customer struct keeps track of everything that you need to know about one customer
 * for this simulation.
 * The Register struct keeps track of everything that you need to know about the activity
 * at the register.
 * Basic struct syntax is "struct StructName { variables };". The ';' at the end is required.
 ***********************************************************************/
struct Customer {
    int arrivalTime;
    int processingTime;
    int customerNumber;
};

struct Register {
    bool hasCustomer;
    int remainingTime;
    int customerNumber;
    bool running;
};

/***********************************************************************
 * Prototypes here. A prototype is the declaration of a function that specifies the function name,
 * the parameter types, and the return type. A function prototype is needed whenever the
 * C++ compiler sees a function call to a function before it sees the actual function body
 * (the function definition). 
 ***********************************************************************/
void printQueue( list<Customer>& customers, int currentMinute, conio::Color defaultTextColor );
void printQueue2( list<Customer>& customers, int currentMinute, conio::Color defaultTextColor );
void printQueue3( list<Customer>& customers, int currentMinute, conio::Color defaultTextColor );

void printLegend( conio::Color defaultTextColor );
bool redCustomer( list<Customer>& customers, int currentMinute);
bool greenCustomer( list<Customer>& customers, int currentMinute);


using namespace std;

int main(int argc, char* argv[], char* envp[]) {

    /***********************************************************************
     * Seed the random number generator.
     * (Do a search on "random number generator to get more detail.)
     * Equally instructive is to run the simulation with the generator seeded and not seeded.
     * - Not seeded will produce the exact same "random number" sequence for each
     * program run. Good for debugging and manually verifying results, but bad
     * for simulating random behavior in general.
     * NOTE: You must only run srand() ONCE anywhere in the program!
     * Doing it more than once can really mess things up.
     ***********************************************************************/
    srand( time(NULL) );

    list<Customer> customerQ;
    list<Customer> customerQ2;
    list<Customer> customerQ3;

    int simLength,               // Length of simulation (minutes)
	customerNumber = 0,      // Customer arrival order number (like number in driver's license branch)
        waitTime = 0,            // How long dequeued customer waited
        totalServed = 0,         // Total customers served
        totalWait   = 0,         // Total waiting time
        maxWait     = 0,         // Longest wait
        numArrivals = 0;         // Number of new arrivals
      
    int waitTime2 = 0,          
    totalServed2 = 0,         
    totalWait2   = 0,         
    maxWait2     = 0;         

    Customer currentCustomer = { -1, -1, -1};  // The current customer
    Register register1 = { false, 0, -1, false};     // The register gets declared and initialized
    Register register2 = { false, 0, -1, false};   // **Added Register Two
    Register register3 = { false, 0, -1, false}; // Simulation Two
    Register register4 = { false, 0, -1, false}; // Simulation Two

    // Figure out what to do with the text color (light vs. dark screen)
    conio::Color defaultTextColor;
    cout << "Is the screen color dark? ([Y]/n) ";
    char ans;
    cin.get(ans);
    if( ans=='n' || ans=='N' ) {
        defaultTextColor = conio::BLACK;
    } else {
        defaultTextColor = conio::WHITE;
    }
    if( ans != '\n' ) {
	cin.ignore(100, '\n');
    }

    // Determine how long to run the simulator.
    cout << endl << "Enter the length of time to run the simulator : ";
    cin >> simLength;

    for ( int minute=1 ; minute<=simLength ; minute++ )
    {
	// system("some command") will run any command that you could have typed at the prompt.
	// I could also have done this with conio, but wanted to demonstrate "system()".
	system("clear");

	/***********************************************************************
         * Determine the number of new customers and add them to the queue ...
	 * one chance of one new arrival (the 1), one chance of two new arrivals (the 2),
	 * three chances of no new arrivals (the 0 or 3). 
	 ***********************************************************************/
	switch(rand() % 4) {
          case 1 : numArrivals = 1; break;
          case 2 : numArrivals = 2; break;
          default: numArrivals = 0;
        }

	/***********************************************************************
         * ... and add them to the queue.
	 * Like above, one chance that register time takes 4 minutes (super-slow),
	 * one chance that it takes 2 minutes, two chances that it takes one minute.
	 ***********************************************************************/
        for ( int j=0 ; j<numArrivals ; j++ ) {
	    customerNumber++;

	    /* -- For your reference.
	     struct Customer { int arrivalTime; int processingTime; int customerNumber; };
	    */

	    Customer newCustomer;
	    // Set the customer variable fields.
	    newCustomer.arrivalTime = minute;

	    // Different way of formatting the case statements. Decide which you think is more readable.
	    switch ( rand() % 5 ) {    
	      case 4 : newCustomer.processingTime = 4;
		       break;
	      case 2 : newCustomer.processingTime = 2;
		       break;
	      default: newCustomer.processingTime = 1;
		       break;
	    }
	    newCustomer.customerNumber = customerNumber;

	    // Put the customer at the back of the queue. Below is the
	    // STL version of the standard queue 'enqueue' command.
            customerQ.push_back(newCustomer);

            if(customerQ2.size() > customerQ3.size()){ // Simulation Two Queuing
                customerQ3.push_back(newCustomer);
            }
            else{
                customerQ2.push_back(newCustomer);
            }
	}

	/***********************************************************************
         * Dequeue the first customer in line (if any). Increment
         * totalServed, add the time that this customer waited to
         * totalWait, and update maxWait if this customer waited
         * longer than any previous customer.
	 ***********************************************************************/

	// Try to get next customer if register is has no customer.
	if( ! register1.hasCustomer ) {

	    // Can only get a customer if the queue is not empty.
	    if ( ! customerQ.empty() )
	    {
	        // Make a copy of the customer record at the front of the queue.
	        // Don't remove customer from queue yet, else they don't show in queue.
		// Remove the customer when the customer has completed activity at the register.
		// NOTE: front() + pop_front() together are the STL equivalent 
		// of the classic queue "dequeue" command.
	        currentCustomer = customerQ.front();

		customerQ.pop_front();
	        /* -- for your reference
		 struct Register { bool hasCustomer; int remainingTime; int customerNumber; };
		 struct Customer { int arrivalTime; int processingTime; int customerNumber; };
		*/
		// Set the register stuff
	        register1.hasCustomer = true;
	        register1.remainingTime = currentCustomer.processingTime;
	        register1.customerNumber = currentCustomer.customerNumber;
	    }
	}

            

            if( !register2.hasCustomer ) {

                // Can only get a customer if the queue is not empty.
                if ( ! customerQ.empty() )
                {
                    // Make a copy of the customer record at the front of the queue.
                    // Don't remove customer from queue yet, else they don't show in queue.
                    // Remove the customer when the customer has completed activity at the register.
                    // NOTE: front() + pop_front() together are the STL equivalent 
                    // of the classic queue "dequeue" command.
                    currentCustomer = customerQ.front();

                    customerQ.pop_front();
                    /* -- for your reference
                     struct Register { bool hasCustomer; int remainingTime; int customerNumber; };
                     struct Customer { int arrivalTime; int processingTime; int customerNumber; };
                    */
                    // Set the register stuff
                    register2.hasCustomer = true;
                    register2.remainingTime = currentCustomer.processingTime;
                    register2.customerNumber = currentCustomer.customerNumber;
                }
            }


	if( ! register3.hasCustomer ) {

	    // Can only get a customer if the queue is not empty.
	    if ( ! customerQ2.empty() )
	    {
	        // Make a copy of the customer record at the front of the queue.
	        // Don't remove customer from queue yet, else they don't show in queue.
		// Remove the customer when the customer has completed activity at the register.
		// NOTE: front() + pop_front() together are the STL equivalent 
		// of the classic queue "dequeue" command.
	        currentCustomer = customerQ2.front();

		customerQ2.pop_front();
	        /* -- for your reference
		 struct Register { bool hasCustomer; int remainingTime; int customerNumber; };
		 struct Customer { int arrivalTime; int processingTime; int customerNumber; };
		*/
		// Set the register stuff
	        register3.hasCustomer = true;
	        register3.remainingTime = currentCustomer.processingTime;
	        register3.customerNumber = currentCustomer.customerNumber;
	    }
	}


	if( ! register4.hasCustomer ) {

	    // Can only get a customer if the queue is not empty.
	    if ( ! customerQ3.empty() )
	    {
	        // Make a copy of the customer record at the front of the queue.
	        // Don't remove customer from queue yet, else they don't show in queue.
		// Remove the customer when the customer has completed activity at the register.
		// NOTE: front() + pop_front() together are the STL equivalent 
		// of the classic queue "dequeue" command.
	        currentCustomer = customerQ3.front();

		customerQ3.pop_front();
	        /* -- for your reference
		 struct Register { bool hasCustomer; int remainingTime; int customerNumber; };
		 struct Customer { int arrivalTime; int processingTime; int customerNumber; };
		*/
		// Set the register stuff
	        register4.hasCustomer = true;
	        register4.remainingTime = currentCustomer.processingTime;
	        register4.customerNumber = currentCustomer.customerNumber;
	    }
	}
        

	/***********************************************************************
         * Display information about the simulation.
	 ***********************************************************************/
        cout << conio::gotoRowCol(1, 1) << "CHECKOUT REGISTER SIMULATION NUMBER 1";
        cout << conio::gotoRowCol(2, 1) << "Simulation minute: " << minute;

	// E.g., "Serving customer: 8   (2 minutes left)"
	cout << conio::gotoRowCol(3, 1) << "REGISTER 1: Serving customer: ";
	if( register1.hasCustomer ) {             
	    cout << conio::fgColor(conio::CYAN) << register1.customerNumber << ' '
	         << conio::fgColor(defaultTextColor)
	         << conio::gotoRowCol(3, 37) << "(" << register1.remainingTime 
		 << " minute" << ((register1.remainingTime == 1)? "" : "s") << " left)";

	}
	else {
	    cout << conio::fgColor(conio::CYAN) << setw(10) << "none" 
	         << conio::fgColor(defaultTextColor);
	}
       

        // **Second Register
	cout << conio::gotoRowCol(4, 1) << "REGISTER 2: Serving customer: ";
	if( register2.hasCustomer ) {
	    cout << conio::fgColor(conio::CYAN) << register2.customerNumber << ' '
	         << conio::fgColor(defaultTextColor)
	         << conio::gotoRowCol(4, 37) << "(" << register2.remainingTime 
		 << " minute" << ((register2.remainingTime == 1)? "" : "s") << " left)";
	}
	else {
	    cout << conio::fgColor(conio::CYAN) << setw(10) << "none" 
	         << conio::fgColor(defaultTextColor);
	}


        // ================================================
        // ================================================
        // Display Registers for Simulation with two queues
        //
        
        cout << conio::gotoRowCol(7, 1) << "CHECKOUT REGISTER SIMULATION NUMBER 2";
        cout << conio::gotoRowCol(8, 1) << "Simulation minute: " << minute;

	// E.g., "Serving customer: 8   (2 minutes left)"
	cout << conio::gotoRowCol(9, 1) << "REGISTER 1: Serving customer: ";
	if( register3.hasCustomer ) {             
	    cout << conio::fgColor(conio::CYAN) << register3.customerNumber << ' '
	         << conio::fgColor(defaultTextColor)
	         << conio::gotoRowCol(9, 37) << "(" << register3.remainingTime 
		 << " minute" << ((register3.remainingTime == 1)? "" : "s") << " left)";

	}
	else {
	    cout << conio::fgColor(conio::CYAN) << setw(10) << "none" 
	         << conio::fgColor(defaultTextColor);
	}
       

        
	cout << conio::gotoRowCol(11, 1) << "REGISTER 2: Serving customer: ";
	if( register4.hasCustomer ) {
	    cout << conio::fgColor(conio::CYAN) << register4.customerNumber << ' '
	         << conio::fgColor(defaultTextColor)
	         << conio::gotoRowCol(11, 37) << "(" << register4.remainingTime 
		 << " minute" << ((register4.remainingTime == 1)? "" : "s") << " left)";
	}
	else {
	    cout << conio::fgColor(conio::CYAN) << setw(10) << "none" 
	         << conio::fgColor(defaultTextColor);
	}

	cout << conio::gotoRowCol(6, 1) << "# customers finished: " << totalServed;
	cout << conio::gotoRowCol(14, 1) << "# customers finished: " << totalServed2;


	// Show queue with the people in the queue, including highlighting to show how long they have waited.
	printQueue( customerQ, minute, defaultTextColor );
	printQueue2( customerQ2, minute, defaultTextColor );
	printQueue3( customerQ3, minute, defaultTextColor );
	printLegend( defaultTextColor );

	// Move the cursor out of the way and use "flush" to force all accumulated output to be sent to screen.
	cout << conio::gotoRowCol(30, 1) << flush;

	/***********************************************************************
	 * Another minute has gone by. 
	 * - Decrement the register count if there is a customer.
	 * - If customer has finished at register, mark register is empty.
	 ***********************************************************************/
	if( register1.hasCustomer ) {
	    register1.remainingTime--;

	    // If just finished serving this customer, mark register as not busy
	    // and remove current customer from queue.
	    if( register1.remainingTime == 0 ) {
		totalServed++;
		register1.hasCustomer = false;

		// Update general information used for statistics
	        waitTime = minute-currentCustomer.arrivalTime;
	        totalWait += waitTime;
	        if( waitTime > maxWait )
		    maxWait = waitTime;

		// Remove customer from queue
		// NOTE: front() + pop_front() together are the STL equivalent 
		// of the classic queue "dequeue" command.

		// Update the screen information
		cout << conio::gotoRowCol(6, 1) << "# customers finished: " << totalServed;
	    }
	}

	if( register2.hasCustomer ) {
	    register2.remainingTime--;

	    // If just finished serving this customer, mark register as not busy
	    // and remove current customer from queue.
	    if( register2.remainingTime == 0 ) {
		totalServed++;
		register2.hasCustomer = false;

		// Update general information used for statistics
	        waitTime = minute-currentCustomer.arrivalTime;
	        totalWait += waitTime;
	        if( waitTime > maxWait )
		    maxWait = waitTime;

		// Remove customer from queue
		// NOTE: front() + pop_front() together are the STL equivalent 
		// of the classic queue "dequeue" command.
		// Update the screen information
		cout << conio::gotoRowCol(6, 1) << "# customers finished: " << totalServed;
	    }
	}

	if( register3.hasCustomer ) {
	    register3.remainingTime--;

	    // If just finished serving this customer, mark register as not busy
	    // and remove current customer from queue.
	    if( register3.remainingTime == 0 ) {
		totalServed2++;
		register3.hasCustomer = false;

		// Update general information used for statistics
	        waitTime2 = minute-currentCustomer.arrivalTime;
	        totalWait2 += waitTime2;
	        if( waitTime2 > maxWait2 )
		    maxWait2 = waitTime2;

		// Remove customer from queue
		// NOTE: front() + pop_front() together are the STL equivalent 
		// of the classic queue "dequeue" command.

		// Update the screen information
		cout << conio::gotoRowCol(14, 1) << "# customers finished: " << totalServed2;
	    }
	}

	if( register4.hasCustomer ) {
	    register4.remainingTime--;

	    // If just finished serving this customer, mark register as not busy
	    // and remove current customer from queue.
	    if( register4.remainingTime == 0 ) {
		totalServed2++;
		register4.hasCustomer = false;

		// Update general information used for statistics
	        waitTime2 = minute-currentCustomer.arrivalTime;
	        totalWait2 += waitTime2;
	        if( waitTime2 > maxWait2 )
		    maxWait2 = waitTime2;

		// Remove customer from queue
		// NOTE: front() + pop_front() together are the STL equivalent 
		// of the classic queue "dequeue" command.
		// Update the screen information
		cout << conio::gotoRowCol(14, 1) << "# customers finished: " << totalServed2;
	    }
	}

	/***********************************************************************
	 * Pause simulation for one second so screen doesn't go by too quickly to read.
	 ***********************************************************************/
	sleep(PAUSE_TIME);

    } // End of the simulation loop

    /***********************************************************************
     * Print out simulation results.
     ***********************************************************************/
    cout << conio::gotoRowCol(25, 1) << endl;
    cout << "Customers served : " << totalServed << endl;
    cout << "Average wait     : " << setprecision(2)
         << double(totalWait)/totalServed << endl;
    cout << "Longest wait     : " << maxWait << endl;

    cout << conio::gotoRowCol(30, 1) << endl;
    cout << "Customers served : " << totalServed2 << endl;
    cout << "Average wait     : " << setprecision(2)
         << double(totalWait2)/totalServed2 << endl;
    cout << "Longest wait     : " << maxWait2 << endl;


    return 0;
}

/***********************************************************************
 * Prints the customers in the queue using their customer numbers. Also does 
 * color coding of customers to show how long they have been waiting for service.
 * @param customers The list of customers, passed in as a reference so as to avoid
 *                  making a copy of it.
 * @param currentMinute The current minute in the simulation. Used to calculate
 *                  how long a customer has been in the queue.
 * @param defaultTextColor The default text color to set the text color
 *        back to after having changed it to other colors.
 ***********************************************************************/
void printQueue( list<Customer>& customers, int currentMinute, conio::Color defaultTextColor ) {
    list<Customer>::iterator it;
    cout << conio::gotoRowCol(5, 1) << "Customer queue: ";

    for (it=customers.begin(); it!=customers.end(); ++it) {
	if(currentMinute - it->arrivalTime > 10) {
	    cout << conio::fgColor(conio::LIGHT_RED);
	}
	else if(currentMinute - it->arrivalTime > 5) {
	    cout << conio::fgColor(conio::LIGHT_MAGENTA);
	}
	else {
	    cout << conio::fgColor(conio::LIGHT_GREEN);
	}
	cout << it->customerNumber << ' ' << conio::fgColor(defaultTextColor);
    }
}


void printQueue2( list<Customer>& customers, int currentMinute, conio::Color defaultTextColor ) {
    list<Customer>::iterator it;
    cout << conio::gotoRowCol(10, 1) << "Customer queue: ";

    for (it=customers.begin(); it!=customers.end(); ++it) {
	if(currentMinute - it->arrivalTime > 10) {
	    cout << conio::fgColor(conio::LIGHT_RED);
	}
	else if(currentMinute - it->arrivalTime > 5) {
	    cout << conio::fgColor(conio::LIGHT_MAGENTA);
	}
	else {
	    cout << conio::fgColor(conio::LIGHT_GREEN);
	}
	cout << it->customerNumber << ' ' << conio::fgColor(defaultTextColor);
    }
}


void printQueue3( list<Customer>& customers, int currentMinute, conio::Color defaultTextColor ) {
    list<Customer>::iterator it;
    cout << conio::gotoRowCol(12, 1) << "Customer queue: ";

    for (it=customers.begin(); it!=customers.end(); ++it) {
	if(currentMinute - it->arrivalTime > 10) {
	    cout << conio::fgColor(conio::LIGHT_RED);
	}
	else if(currentMinute - it->arrivalTime > 5) {
	    cout << conio::fgColor(conio::LIGHT_MAGENTA);
	}
	else {
	    cout << conio::fgColor(conio::LIGHT_GREEN);
	}
	cout << it->customerNumber << ' ' << conio::fgColor(defaultTextColor);
    }
}



bool redCustomer( list<Customer>& customers, int currentMinute) {
    list<Customer>::iterator it;
    for (it=customers.begin(); it!=customers.end(); ++it) {
	if(currentMinute - it->arrivalTime > 10) {
	    return true;
	}

    }
    return false;
}

bool greenCustomer( list<Customer>& customers, int currentMinute) {
    list<Customer>::iterator it;
    int i = 0;
    for (it=customers.begin(); it!=customers.end(); ++it) {
        if(i > 0){
            break;
        }

	if(currentMinute - it->arrivalTime < 5) {
	    return true;
	}
        else{
            return false;
        }
        i++;

}
return false;
}

/***********************************************************************
 * Prints the customer queue coloring legend.
 * @param defaultTextColor The default text color to set the text color
 *        back to after having changed it to other colors.
 ***********************************************************************/
void printLegend( conio::Color defaultTextColor ) {
    cout << conio::gotoRowCol(20, 1) 
         << "Wait time legend " << endl
	 << conio::fgColor(conio::LIGHT_GREEN) << '*' << conio::fgColor(defaultTextColor) << " = wait < 5 min" << endl
	 << conio::fgColor(conio::LIGHT_MAGENTA) << '*' << conio::fgColor(defaultTextColor) << " = wait 5-9 min" << endl
	 << conio::fgColor(conio::LIGHT_RED) << '*' << conio::fgColor(defaultTextColor) << " = wait 10+ min" << endl;
}

