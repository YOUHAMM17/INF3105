/* #include <iostream>
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
 */
#include <algorithm>
#include<iostream> // Header file for input/output stream
using namespace std; // Using the standard namespace

int find_largest(int nums[], int n) { // Function definition for finding the largest element in an array
  return *max_element(nums, nums + n); // Return the maximum element in the array using max_element from algorithm library
}

int main() { // Main function where the program execution starts
  int nums[] = { // Declaring and initializing an integer array
    5,
    4,
    9,
    12,
    8
  };
  int n = sizeof(nums) / sizeof(nums[0]); // Determining the number of elements in the array

  cout << "Original array:"; // Output message indicating the original array is being displayed
  for (int i=0; i < n; i++) // Loop to display each element of the array
    cout << nums[i] <<" "; // Output each element of the array

  cout << "\nLargest element of the said array: "<< find_largest(nums, n); // Output message showing the largest element in the array
  return 0; // Return statement indicating successful execution and program termination
}
