#pragma once

#include<iostream>
#include<vector>
#include<fstream>

#include "Contact.h"

using namespace std;

class Directory
{
private:
	vector<Contact> contacts;
public:
	void m_importContacts()
	{
		ifstream inputFile("contacts.txt");
		if (!inputFile.is_open())
		{
			cerr << "Invalid File" << endl;
			return;
		}
		Contact c;
		while (inputFile >> c.m_name >> c.m_phoneNumber >> c.m_email)
			contacts.push_back(c);
		inputFile.close();
		cout << "Successfully Imported Contacts" << endl;

		ofstream clearFile("contacts.txt", ios::out | ios::trunc);
		clearFile.close();
	}

	void m_newContact()
	{
		Contact newContact = Contact();
		cout << "Enter Name: " << endl;
		cin >> newContact.m_name;

		cout << "Enter Phone Number: " << endl;
		cin >> newContact.m_phoneNumber;

		cout << "Enter Email: " << endl;
		cin >> newContact.m_email;

		contacts.push_back(newContact);
		cout << endl;

		cout << "New contact added!" << endl;
	}

	vector<Contact>::iterator m_searchContact(string name)
	{
		auto it = find_if(contacts.begin(), contacts.end(), [name](const Contact& c) { return c.m_name == name; });
		if (it == contacts.end())
			cerr << "Contact Not found! " << endl;
		else
		{
			cout << "Contact found! " << endl;
			cout << "Name: " << it->m_name << endl;
			cout << "Phone: " << it->m_phoneNumber << endl;
			cout << "Mail " << it->m_email << endl;
		}
		return it;
	}

	void m_editContact()
	{
		string name;
		cout << "Enter Name of Contact to edit: " << endl;
		cin >> name;
		cout << endl;
		auto it = m_searchContact(name);
		if (it != contacts.end())
		{
			cout << endl;
			cout << "Enter new Name: " << endl;
			cin >> it->m_name;
			cout << "Enter new Phone Number: " << endl;
			cin >> it->m_phoneNumber;
			cout << "Enter new Email: " << endl;
			cin >> it->m_email;
			cout << endl;
			cout << "Successfully Edited the selected contact!" << endl;
		}
	}

	void m_deleteContact()
	{
		string name;
		cout << "Enter Name of Contact to be deleted: " << endl;
		cin >> name;
		cout << endl;
		auto it = m_searchContact(name);
		if (it != contacts.end())
		{
			contacts.erase(it);
			cout << endl;
			cout << "Contact Deleted Succesfully! " << endl;
		}
	}

	void m_Display()
	{
		cout << "---------------------------" << endl;
		for (Contact contact : contacts)
		{
			cout << contact << endl;
			cout << "---------------------------" << endl;
		}
	}

	void m_exportContacts()
	{
		ofstream outputFile("contacts.txt");
		if (!outputFile.is_open())
		{
			cerr << "Invalid File" << endl;
			return;
		}
		for (const Contact& contact : contacts)
		{
			outputFile << contact.m_name << " " << contact.m_phoneNumber << " " << contact.m_email << endl;
		}
		outputFile.close();
		cout << "Successfully Exported Contacts" << endl;
	}
};