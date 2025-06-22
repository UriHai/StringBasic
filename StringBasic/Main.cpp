#include "BasicString.h"

#include <string>
#include <iostream>

using std::cout;
using std::endl;

int main() {
	BasicString a("Hello");
	cout << a.getLength() << endl;
	a.printBasicString();
	BasicString b(" World!");
	a += b;
	a.printBasicString();
	BasicString c("c");
	BasicString d = c * 3;
	d.printBasicString();
	bool isEqual = a == b;
	cout << isEqual << endl;
	isEqual = a == a;
	cout << isEqual << endl;
	a[0] = 'A';
	a.printBasicString();
	cout << a[-2] << endl;
	try {
		cout << a[20] << endl;
	} catch (BasicStringError error) {
		error.getErrorMessage().printBasicString();
	}


	return 0;
}