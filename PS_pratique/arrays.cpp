#include <iostream>
using namespace std;

int main()
{
    cout << "Arrays..!\n";
    int myArray[5] = {5, 7, 6, 1, 0};
    
    // Initialize max with the first element of the array
    int max = myArray[0];
    
    for (int i = 0; i < 5; i++)
    {
        if (myArray[i] > max)
        {
            max = myArray[i];
        }
    }
    
    // Print the largest number
    cout << "The largest number in the array is: " << max << endl;
    
    return 0;
}
