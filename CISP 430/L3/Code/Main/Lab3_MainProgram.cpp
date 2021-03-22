//Lab3 Programming Excercise

#include <iostream>
#include <iomanip>
#include "circleType.h"

using namespace std;

int main() {
	circleType circle1(3, 2.5, 4);
	circleType circle2;

	cout << fixed << showpoint;
	cout << setprecision(2);

	cout << "***** Circle 1 *****" << endl;
	circle1.print();
	cout << endl;

	circle2.setPoint(-2.5, 7);
	circle2.setRadius(4);

	cout << "***** Circle 2 *****" << endl;
	circle2.print();
	cout << endl;

	double x, y;
	double r;
	
	circleType circle3;

	cout << "Enter x coordinate of the center: ";
	cin >> x;
	cout << endl;

	cout << "Enter y coordinate of the center: ";
	cin >> y;
	cout << endl;

	cout << "Enter radius: ";
	cin >> r;
	cout << endl;

	circle3.setPoint(x, y);
	circle3.setRadius(r);

	cout << "***** Circle 3 *****" << endl;
	circle3.print();
	cout << endl;

	system("pause");
	return 0;
}