/**
 * checkout.cpp: checkout queue simulator. Simulates running one checkout register with one
 * customer queue.
 *
 * @author Nate Flasher
 * @date   10/15/19
 */

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <unistd.h>
#include <ctime>
#include <deque>

#include "conio.h"

using namespace std;

const int PAUSE_TIME = 1;

/***********************************************************************
 * The Customer struct keeps track of everything that you need to know
 * about one customer for this simulation.
 * The Register struct keeps track of everything that you need to know
 * about the activity at the register.
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
};

/***********************************************************************
 * Prototypes here. A prototype is the declaration of a function that
 * specifies the function name, the parameter types, and the return type.
 * A function prototype is needed whenever the C++ compiler sees a function
 * call to a function before it sees the actual function body (the function
 * definition).
 ***********************************************************************/
conio::Color getTextColor();
int getNumArrivals();

void addCustomersToQueue(int numNewCustomers, deque<Customer> *customerQ,
			 int minute, int nextCustomerNumber);
void getNextCustomer(Register *curRegister, Customer *curCustomer,
		     deque<Customer> *customerQ);
void updateCustomerAndStats(Register *curRegister, Customer curCustomer,
			    deque<Customer> *customerQ, int minute,
			    int *totalServed, int *totalWait, int *maxWait);

void printQueue(deque<Customer> customers, int currentMinute,
		conio::Color defaultTextColor, int row);
void printLegend(conio::Color defaultTextColor, int startRow);

void displaySimInfo(conio::Color defaultTextColor, Register register1, Register register2, Register register3, Register register4,
		    deque<Customer> customerQ, deque<Customer> sim2Que1, deque<Customer> sim2Que2, int minute);
void displayRegisterInfo(conio::Color defaultTextColor, int row,
			 Register curRegister, int numRegister);
void displayCustServed(int totalServed, int totalServedSim2);

int main() {
    /**********************************************************************
     * Seed the random number generator.
     * (Do a search on "random number generator to get more detail.)
     * Equally instructive is to run the simulation with the generator
     * seeded and not seeded.
     * - Not seeded will produce the exact same "random number" sequence
     *   for each program run. Good for debugging and manually verifying
     *   results, but bad for simulating random behavior in general.
     * NOTE: You must only run srand() ONCE anywhere in the program!
     * Doing it more than once can really mess things up.
     **********************************************************************/
    srand( time(NULL) );

    deque<Customer> customerQ;



    deque<Customer> sim2Que1;
    deque<Customer> sim2Que2;




    int simLength,               // Length of simulation (minutes)
        customerNumber = 0,      // Customer ID
        totalServed = 0,         // Total customers served
        totalServedSim2 = 0,
        totalWait2 = 0,
        totalWait   = 0,         // Total waiting time
        maxWait2 = 0,
        maxWait     = 0;         // Longest wait

    // The register gets declared and initialized
    Register register1 = { false, 0, -1 };

    Register register2 = { false, 0, -1 };

    Register register3 = { false, 0, -1 };

    Register register4 = { false, 0, -1 };
    // The current customer for register1
    Customer currentCustomer1 = { -1, -1, -1};

    Customer currentCustomer2 = { -1, -1, -1};

    Customer currentCustomer3 = { -1, -1, -1};

    Customer currentCustomer4 = { -1, -1, -1};

    conio::Color defaultTextColor = getTextColor();

    // Determine how long to run the simulator.
    cout << "\nEnter the length of time to run the simulator : ";
    cin >> simLength;

    // system("some command") will run any command that you could have
    // typed at the prompt.  I could also have done this with conio, but
    // wanted to demonstrate "system()".
    system("clear");


    for (int minute = 1; minute <= simLength; ++minute) {
	int numNewCustomers = getNumArrivals();
        for(int i=0;i<numNewCustomers;i++){
                if(sim2Que1.size() < sim2Que2.size()){
	                addCustomersToQueue(1, &sim2Que1, minute,
			    customerNumber);
                }
                else if(sim2Que1.size() > sim2Que2.size()){
	                addCustomersToQueue(1, &sim2Que2, minute,
			    customerNumber);
        
                }
                else{
                        if((rand() % 2) == 0){
	                        addCustomersToQueue(1, &sim2Que1, minute,
			    customerNumber);
                                
                        }
                        else{
	                        addCustomersToQueue(1, &sim2Que2, minute,
			    customerNumber);
                        }
                }
	customerNumber += 1;
        }
	addCustomersToQueue(numNewCustomers, &customerQ, minute,
			    customerNumber);

	getNextCustomer(&register1, &currentCustomer1, &customerQ);
        getNextCustomer(&register2, &currentCustomer2, &customerQ);
	getNextCustomer(&register3, &currentCustomer3, &sim2Que1); 
	getNextCustomer(&register4, &currentCustomer4, &sim2Que2); 
	displaySimInfo(defaultTextColor, register1, register2, register3, register4, customerQ, sim2Que1, sim2Que2, minute);
	updateCustomerAndStats(&register1, currentCustomer1, &customerQ,
			       minute, &totalServed, &totalWait, &maxWait);
    
	updateCustomerAndStats(&register2, currentCustomer2, &customerQ,
			       minute, &totalServed, &totalWait, &maxWait);
	updateCustomerAndStats(&register3, currentCustomer3, &sim2Que1, // edit later
			       minute, &totalServedSim2, &totalWait2, &maxWait2);
	updateCustomerAndStats(&register4, currentCustomer4, &sim2Que2, //edit later
			       minute, &totalServedSim2, &totalWait2, &maxWait2);
	displayCustServed(totalServed, totalServedSim2); //edit later

         // Pause simulation for one second so screen doesn't go by too
	 // quickly to read.
        sleep(PAUSE_TIME);
        system("clear");
    } // End of the simulation loop

    /**********************************************************************
     * Print out simulation results.
     **********************************************************************/
    cout << conio::gotoRowCol(15, 1) << "\n";
    cout << "Simulation 1 : " << "\n";
    cout << "Customers served : " << totalServed << "\n";
    cout << "Total wait time : " << totalWait << "\n";
    cout << "Average wait     : " << setprecision(2)
         << double(totalWait)/totalServed << "\n";
    cout << "Longest wait     : " << maxWait << "\n";

    cout << "Simulation 2 : " << "\n";
    cout << "Customers served : " << totalServedSim2 << "\n";
    cout << "Total wait time : " << totalWait2 << "\n";
    cout << "Average wait     : " << setprecision(2)
         << double(totalWait2)/totalServedSim2 << "\n";
    cout << "Longest wait     : " << maxWait2 << "\n";
    return 0;
}

/***********************************************************************
 * Prints the customers in the queue using their customer numbers. Also does
 * color coding of customers to show how long they have been waiting for
 * service.
 * @param customers The queue of customers
 * @param currentMinute The current minute in the simulation. Used to
 *            calculate how long a customer has been in the queue.
 * @param defaultTextColor The default text color to set the text color
 *            back to after having changed it to other colors.
 ***********************************************************************/
void printQueue(deque<Customer> customers, int currentMinute,
		conio::Color defaultTextColor, int row)
{
        cout << conio::gotoRowCol(row, 1) << "Customer queue: ";

        for (auto customer : customers) {
            if (currentMinute - customer.arrivalTime > 10) {
                cout << conio::fgColor(conio::LIGHT_RED);
            }
            else if (currentMinute - customer.arrivalTime > 5) {
                cout << conio::fgColor(conio::LIGHT_MAGENTA);
            }
            else {
                cout << conio::fgColor(conio::LIGHT_GREEN);
            }
            cout << customer.customerNumber << ' '
             << conio::fgColor(defaultTextColor);
        }
    }

    /***********************************************************************
     * Prints the customer queue coloring legend.
     * @param defaultTextColor The default text color to set the text color
     *            back to after having changed it to other colors.
     * @param startRow The first line of the legend.
     ***********************************************************************/
    void printLegend(conio::Color defaultTextColor, int startRow) {
        cout << conio::gotoRowCol(startRow, 1) << "Wait time legend\n"
             << conio::fgColor(conio::LIGHT_GREEN) << '*'
         << conio::fgColor(defaultTextColor) << " = wait < 5 min\n"
             << conio::fgColor(conio::LIGHT_MAGENTA) << '*'
         << conio::fgColor(defaultTextColor) << " = wait 5-9 min\n"
             << conio::fgColor(conio::LIGHT_RED) << '*'
         << conio::fgColor(defaultTextColor) << " = wait 10+ min\n";
    }

    conio::Color getTextColor() {
        conio::Color textColor = conio::WHITE;

        cout << "Is the screen color dark? ([Y]/n) ";
        char ans;
        cin.get(ans);
        if (ans=='n' || ans=='N') {
            textColor = conio::BLACK;
        }
        if (ans != '\n') {
            cin.ignore(100, '\n');
        }

        return textColor;
    }
    /***********************************************************************
     * Determine the number of new customers and add them to the queue ...
     * one chance of one new arrival (the 1), one chance of two new arrivals
     * (the 2), two chances of no new arrivals (the 0 or 3).
     *
     * Feel free to adjust the if statement in order to produce a greater
     * or lesser "customer load".
     ***********************************************************************/
    int getNumArrivals() {
        int numArrivals = rand() % 4;
        if (numArrivals == 3) {
        numArrivals = 0;
        }

        return numArrivals;
    }

    /***********************************************************************
     * ... and add them to the queue.
     * Like above, one chance that register time takes 4 minutes (super-slow),
     * one chance that it takes 2 minutes, three chances that it takes one
     * minute.  Again, feel free to adjust parameters.
     ***********************************************************************/
    void addCustomersToQueue(int numNewCustomers, deque<Customer> *customerQ,
                 int minute, int nextCustomerNumber)
    {
        for (int j = 0; j < numNewCustomers; ++j) {
        Customer newCustomer;
        // Set the customer variable fields.
        newCustomer.arrivalTime = minute;

        switch (rand() % 5) {
          case 4 : newCustomer.processingTime = 4;
               break;
          case 2 : newCustomer.processingTime = 2;
               break;
          default: newCustomer.processingTime = 1;
               break;
        }
        newCustomer.customerNumber = nextCustomerNumber++;

        // Put the customer at the back of the queue. Below is the
        // STL version of the standard queue 'enqueue' command.
        customerQ->push_back(newCustomer);
        }
    }
    /***********************************************************************
     * Dequeue the first customer in line (if any). 
     ***********************************************************************/
    void getNextCustomer(Register *curRegister, Customer *curCustomer,
                 deque<Customer> *customerQ)
    {
        // Try to get next customer if register is has no customer.
        if (!curRegister->hasCustomer) {
        // Can only get a customer if the queue is not empty.
        if (!customerQ->empty()) {
            // Make a copy of the customer record at the front of the queue.
            // Don't remove customer from queue yet, else they don't show
            // in queue.  Remove the customer when the customer has
            // completed activity at the register.
            *curCustomer = customerQ->front();
            // Remove customer from queue
            customerQ->pop_front();

            // Set the register attributes
            curRegister->hasCustomer = true;
            curRegister->remainingTime = curCustomer->processingTime;
            curRegister->customerNumber = curCustomer->customerNumber;
        }
        }
    }
    /***********************************************************************
     * Display information about the simulation.
     ***********************************************************************/
    void displaySimInfo(conio::Color defaultTextColor, Register register1, Register register2, Register register3, Register register4,
                deque<Customer> customerQ, deque<Customer> sim2Que1, deque<Customer> sim2Que2, int minute)
    {
        cout << conio::gotoRowCol(1, 1) << "CHECKOUT REGISTER SIMULATION";
        cout << conio::gotoRowCol(2, 1) << "Simulation minute: " << minute;
        cout << conio::gotoRowCol(4, 1) << "Simulation 1: ";

        cout << conio::gotoRowCol(10, 1) << "Simulation 2: ";

        displayRegisterInfo(defaultTextColor, 5, register1, 1);
       
        displayRegisterInfo(defaultTextColor, 6, register2, 2);

        displayRegisterInfo(defaultTextColor, 11, register3, 3);

        displayRegisterInfo(defaultTextColor, 12, register4, 4);

        // Show queue with the people in the queue, including highlighting to
        // show how long they have waited.
        printQueue(customerQ, minute, defaultTextColor, 7);



        printQueue(sim2Que1, minute, defaultTextColor, 13);
        printQueue(sim2Que2, minute, defaultTextColor, 14);


    printLegend(defaultTextColor, 20);
}

void displayCustServed(int totalServed, int totalServedSim2) {
    cout << conio::gotoRowCol(8, 1) << "# customers finished: "
	 << totalServed;




    cout << conio::gotoRowCol(15, 1) << "# customers finished for simulation 2: " << totalServedSim2; 





    // Move the cursor out of the way and use "flush" to force all
    // accumulated output to be sent to screen.
    cout << conio::gotoRowCol(15, 1) << flush;
}

void displayRegisterInfo(conio::Color defaultTextColor, int row,
			 Register curRegister, int numRegister)
{
    // E.g., "Serving customer: 8   (2 minutes left)"
    cout << conio::gotoRowCol(row, 1) << "Register " << numRegister << ":";
    if (curRegister.hasCustomer) {
	cout << conio::fgColor(conio::CYAN) << curRegister.customerNumber
	     << ' ' << conio::fgColor(defaultTextColor)
	     << conio::gotoRowCol(row, 25) << "("
	     << curRegister.remainingTime << " minute"
	     << ((curRegister.remainingTime == 1)? "" : "s") << " left)";
    } else {
	cout << conio::fgColor(conio::CYAN) << setw(10) << "none"
	     << conio::fgColor(defaultTextColor);
    }
}

/***********************************************************************
 * Another minute has gone by.
 * - Decrement the register count if there is a customer.
 * - If customer has finished at register, mark register is empty.
 ***********************************************************************/
void updateCustomerAndStats(Register *curRegister, Customer curCustomer,
			    deque<Customer> *customerQ, int minute,
			    int *totalServed, int *totalWait, int *maxWait)
{
    if (curRegister->hasCustomer) {
	// If just finished serving this customer, mark register as not busy
	// and remove current customer from queue.
	if (--curRegister->remainingTime == 0) {
	    ++*totalServed;
	    curRegister->hasCustomer = false;

	    // Update general information used for statistics
	    int waitTime = minute-curCustomer.arrivalTime;
	    *totalWait += waitTime;
	    if (waitTime > *maxWait) {
		*maxWait = waitTime;
	    }

	}
    }
}
