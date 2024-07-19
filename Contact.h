#pragma once
#include<iostream>
using namespace std;

class Contact
{
public:
	string m_name;
	string m_phoneNumber;
	string m_email;

	Contact() {}

	Contact(string name, string phn, string email)
		:m_name(name), m_phoneNumber(phn), m_email(email) {}

	friend ostream& operator<<(ostream& stream, const Contact& c)
	{
		stream << "Name: " << c.m_name << endl;
		stream << "Phone Number: " << c.m_phoneNumber << endl;
		stream << "Email: " << c.m_email;
		return stream;
	}
};
