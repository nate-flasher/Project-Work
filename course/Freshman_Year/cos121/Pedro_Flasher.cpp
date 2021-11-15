// Include the Input/Output data STREAM information needed by the program
// Nate Flasher
// 2/14/19

using namespace std;

#include <iostream>

int main() {
    // Your code goes below.
int num = 0;
int total = 0;
cin>>num;
while(cin) {
	total=num*2;
	cout<<total<<endl;
	cin>>num;


}

    // When the program has finished running, it should return the value 0 to the system to show that the program terminated without problems.
    return 0;
}

