// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "..\StaticLib1\StaticLib1.h"
// #include "..\StaticLib1\StaticLib1.cpp"
#include "iostream"
using namespace std;
using namespace NsString;

int main() {

	{
		String s1;	cout << s1 << s1.size() << endl;

		String s2("hello world");	cout << s2 << s2.size() << endl;
		String *p = new String("abc");	cout << *p << p->size() << endl;

		String s3(s2);	cout << s3 << s3.size() << endl;

		cout << "s3 " << s3 << s3.size() << endl;
		String s4(move(s3));
		cout << "s4 " << s4 << s4.size() << endl;
		cout << "s3 " << s3 << s3.size() << endl;
	}

	{
		{String s1("abc");	String s2("abc");	cout << s1.compare(s2) << endl; }
		{String s1("abc");	String s2("ABC");	cout << s1.compare(s2) << endl; }
		{String s1("ABC");	String s2("abc");	cout << s1.compare(s2) << endl; }

		{String s1("abc");	String s2("abcd");	cout << s1.compare(s2) << endl; }
		{String s1("abcd");	String s2("abc");	cout << s1.compare(s2) << endl; }
	}

	return 0;
}
