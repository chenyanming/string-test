#include "string.h"
#include <iostream>

int main()
{
	String s1("hello");
	String s2(s1);
	String s3 = s1;
	cout << s1 << endl;
	cout << s2 << endl;
	cout << s3 << endl;
}
