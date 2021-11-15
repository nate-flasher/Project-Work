// Nate Flasher
// 02/14/19

#include <iostream>

// Below needed if use the setw() function
#include <iomanip>

using namespace std;

int main() {

    int maxWidth;
    cout << "How wide is the diamond (use an odd number)? ";
    cin >> maxWidth;

    cout << "The diamond is " << maxWidth << " wide."<< endl;

    // Print top half of diamond (growing)
    for (int numStars=1; numStars<=maxWidth; numStars+=2) {
        int numSpaces=(maxWidth-numStars)/2;
        for(int i=0; i<numSpaces; i++) {
            cout << ' ';
        }
        // Instead of the for loop above, you could do
        // cout << setw(numSpaces) << "";

        for (int i=0; i< numStars; i++) {
            cout << '*';
        }
        cout << endl;
    }

	
for (int numStars=maxWidth-1; numStars>=1; numStars-=2) {
        int numSpaces=(maxWidth-numStars)/2;
        for(int i=0; i<numSpaces+1; i++) {
            cout << ' ';
        }
        // Instead of the for loop above, you could do
        // cout << setw(numSpaces) << "";

        for (int i=0; i< numStars-1; i++) {
            cout << '*';
        }
        cout << endl;
    }
    return 0;
}
