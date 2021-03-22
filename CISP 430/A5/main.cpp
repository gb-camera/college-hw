//Michael Dinh - Assignment 5 - CISP 430 - Huang (Spring 2020)
//Driver file for permute class

#include <iostream>
#include <string>
#include "permute.h"
using namespace std;

//According to the instructions, the driver should make an array of eight permute objects,
//and then "use repetition" to call print on each element

int main() {
	Permute* catmen[] = {
		new Permute("", ""),
		new Permute("", "CATMAN"),
		new Permute("C", "ATMAN"),
		new Permute("CA", "TMAN"),
		new Permute("CAT", "MAN"),
		new Permute("CATM", "AN"),
		new Permute("CATMA", "N"),
		new Permute("CATMAN", "")
	};

	for (int i = 0; i < 8; ++i) {
		catmen[i]->print();
		cout << endl << endl;
	}

	system("pause");
}