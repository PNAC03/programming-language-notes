// StaticLib1.cpp : Defines the entry point for the console application.
//

#include "StaticLib1.h"
#include <stdexcept>

#include "iostream"
#include "algorithm"
using namespace std;

namespace NsString {

	String::String() {
		_len = 0;
	}
	String::String(char const* s) {
		if (_buf) {
			delete[]_buf;
		}

		_len = strlen(s) + 1;
		_buf = new char[_len];
		strncpy_s(_buf, _len, s, _len - 1);
	}
	String::String(String const& s) {
		if (_buf) {
			delete[]_buf;
		}
		_len = s._len;
		_buf = new char[_len];
		strncpy_s(_buf, _len, s._buf, _len);
	}
	String::String(String && s) {
		_len = s._len;
		s._len = 0;

		_buf = s._buf;
		s._buf = NULL;
	}
	String::~String() {
		if (_buf) {
			delete[]_buf;
		}
	}


	size_t String::size() {
		return _len;
	}


	int _compare(const char* p, const char* q, size_t n) {
		while (n--) {
			if (*p != *q) {
				return (*p - *q);
				// return (*p < *q) ? -1 : 1;
			}
			++p;
			++q;
		}
		return 0;
	}
	int String::compare(String const& q) {
		int diff = _compare(_buf, q._buf, min(_len - 1, q._len - 1));
		if (diff == 0) {
			if (_len < q._len) {
				// cout << "EQUAL, BUT LENS NOT EQUAL - <" << endl;
				return -1;
			}
			else if (_len > q._len) {
				// cout << "EQUAL, BUT LENS NOT EQUAL - >" << endl;
				return 1;
			}
		}
		return diff;
	}

	std::ostream& operator<<(std::ostream& os, const String& obj) {
		if (obj._buf) {
			os << obj._buf;
		}
		return os;
	}

	double String::Add(double a, double b) {
		return a + b;
	}
}