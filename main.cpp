#include<iostream>
#include<vector>
#include<algorithm>
#include<fstream>

#include "Directory.h"

using namespace std;


int main()
{
	Directory D;
	int i;
	do
	{
		cout << "1.New Conact" << endl;
		cout << "2.Edit Contact" << endl;
		cout << "3.Search Contact" << endl;
		cout << "4.Delete Contact" << endl;
		cout << "5.Display All Contacts" << endl;
		cout << "6.Import Contacts" << endl;
		cout << "7.Export Contacts" << endl;
		int ch;
		cin >> ch;
		cout << endl;

		switch (ch)
		{
		case 1:
			D.m_newContact();
			break;
		case 2:
			D.m_editContact();
			break;
		case 3:
		{
			cout << "Enter name to search" << endl;
			string name;
			cin >> name;
			cout << endl;
			D.m_searchContact(name);
			break;
		}
		case 4:
			D.m_deleteContact();
			break;
		case 5:
			D.m_Display();
			break;
		case 6:
			D.m_importContacts();
			break;
		case 7:
			D.m_exportContacts();
			break;
		default:
			cerr << "Invalid Choice" << endl;
		}

		cout << endl;
		cout << "Menu(1)/Exit(0)" << endl;
		cin >> i;
		cout << endl;
	} while (i);

	cin.get();
}