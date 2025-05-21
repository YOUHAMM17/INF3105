#include <iostream>
using namespace std;

int main() {
    int x;

    // Prompt the user to enter a value for x
    cout << "Enter an integer: ";
    cin >> x;

    if (x % 2 == 0) {
        x = x * 8;  // Assign the result back to x
    } else {
        x = x * 9;  // Assign the result back to x
    }

    // Output the modified value of x
    cout << "Modified x: " << x << endl;

    return 0;
}
