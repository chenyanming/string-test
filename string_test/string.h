#ifndef __MYSTRING__
#define __MYSTRING__

#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

class String
{
private:
	char* m_data; //Data is a pointer to a string
public:
	//Big three
	String(const char* cstr = 0);
	String(const String& str);
	String& operator = (const String& str);
	~String();
	char* get_c_str() const { return m_data; }

};

#include <cstring>

inline
String::String(const char* cstr)
{
	if (cstr) {
		m_data = new char[strlen(cstr) + 1];//array new
		strcpy(m_data, cstr);
	}
	else {
		m_data = new char[1];//array new
		*m_data = '\0';
	}

}

inline
String::~String()
{
	delete[] m_data;//array delete

}

inline
String::String(const String& str)
{
	m_data = new char[strlen(str.m_data) + 1];
	strcpy(m_data, str.m_data);
}

inline
String& String::operator = (const String& str)
{
	if (this == &str)
		return *this;

	delete[] m_data;
	m_data = new char[strlen(str.m_data) + 1];
	strcpy(m_data, str.m_data);
	return *this;

}

#include <iostream>
using namespace std;
ostream& operator<<(ostream& os, const String& str)
{
	os << str.get_c_str();
	return os;
}

#endif

