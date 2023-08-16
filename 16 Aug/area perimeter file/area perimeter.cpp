//
// Program to compute area and perimeter of a rectangle given
// length and width.
//
// Topic: Illustrate output with cout, compare to printf
//


#include <iostream>
using namespace std;

int main(void)
{
	double length;
	double width;
	double area;
	double perimeter;

	// Use cout to output inormation to the screen.

    cout << "Give me a length..." << endl;
    cin >> length;
    cout << "Give me a width..." << endl;
    cin >> width;

    area = length * width;
    perimeter = 2 * (length + width);

    cout << "Length = " << length << endl
         << "Width = " << width << endl
         << "Perimeter = " << perimeter << endl
         << "Area = " << area << endl;

	// Now the same output using printf

	printf("\n\nWith printf\n\nLength = %6.2lf Width = %6.2lf Perimeter = %6.2lf Area = %6.2lf\n",
		   length, width, perimeter, area);

	return 0;
}