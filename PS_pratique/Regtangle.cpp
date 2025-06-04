#include <iostream>
using namespace std;

// Class definition for Rectangle   
class Rectangle
{
    double length;
    double width;

public:
    Rectangle(double l, double w); // Corrected the class name here
    double area()const;
    double perimeter()const;
};

// Constructor definition
Rectangle::Rectangle(double l, double w) // Corrected the class name here
{
    length = l;
    width = w;
}

// Method to calculate area
double Rectangle::area() const 
{
    double incrementedLength = length + 1;
    return incrementedLength * width;
}


// Method to calculate perimeter
double Rectangle::perimeter()const
{
    return 2 * (length + width);
}
// Main function to test the class  
int main()      
{
    Rectangle r(7, 4); // Creating an object of Rectangle class
    cout << "Area of Rectangle is: " << r.area() << endl;
    cout << "Perimeter of Rectangle is: " << r.perimeter() << endl;
    
    return 0;
}