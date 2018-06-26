// StaticLib1.cpp : Defines the entry point for the console application.
//

#include "cstdio"
#include "iostream"
using namespace std;

namespace NsString {

	// template <class charT>	// for unicode & others
	class String {

		char *_buf = NULL;
		size_t _len;
	public:

		String();
		String(char const* s);
		String(String const& s);
		String(String && s);
		~String();

		int compare(String const& q);

		size_t size();


		friend std::ostream& operator<<(std::ostream& os, const String& obj);

		static double Add(double a, double b);
	};
}