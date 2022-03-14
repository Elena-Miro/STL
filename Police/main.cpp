#include <iostream>
#include<map>
#include<list>
#include<string>
#include<Windows.h>
#include "Crime.h"
#include<fstream>

using namespace std;
using std::cin;
using std::cout;
using std::endl;

void print(const std::map < std::string, std::list<Crime>>base);
void main()
{
	//setlocale(LC_ALL, "");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	ofstream fout("file.txt");

	std::map<std::string, std::list<Crime>> base =
	{
		{ "a777km",{Crime(1,"����� ������"),Crime(2,"����� ������")} },
		{ "a557ab",{Crime(5,"����� �����������")}},
		{ "a001�" ,{Crime(4,"����������� ������"),Crime(3,"����� �����������") } },
		{ "a002�" ,{Crime(2,"����������� ������"),Crime(5,"����� �����������") } }
	};
	print(base);
	std::string licence_plate;
	int id;
	std::string place;
	cout << "������� ����� ����������: "; cin >> licence_plate;
	cout << "������� ��������������(����� ������): "; cin >> id;
	cout << "������� ����� ������������: "; 
	cin.clear();
	cin.ignore();
	std::getline(cin, place);
	//base[licence_plate].push_back(Crime(id, place));

	std::map<std::string, std::list<Crime>>::iterator it = base.find(licence_plate);
	if (it != base.end())
	{
		it->second.push_back(Crime(id, place));
	}
	else
	{
		base.insert(std::pair<std::string, std::list<Crime>>(licence_plate, { Crime(id, place) }));
	}
	print(base);


	//����� � ���� ����������

	cout << "������� ����� ����������: "; cin >> licence_plate;
	//std::map<std::string, std::list<Crime>>::iterator it = base.find(licence_plate);
	

	it = base.find(licence_plate);
	if (it != base.end())
	{
		cout << "����� ������: " << it->first << "  �������� ��������������: ";
	
		for (std::list<Crime>::const_iterator jt = it->second.begin(); jt != it->second.end(); ++jt)
		{

			cout << "\t" << *jt << ";\n";
		}
		cout << "\n------------------------------------\n";
	}
	else
		cout << "����� ������: " << licence_plate << "�� ������!" << endl;
	
	//����� ���� � ��������(not done)
	std::string licence_plate1;
	std::string licence_plate2;
	cout << "������� ������� ������� ��: "; cin >> licence_plate; cout <<" �� "<< endl; cin >> licence_plate2;
	it=base.lower_bound(licence_plate);
	it = base.upper_bound(licence_plate2);
	
	if (it != base.end())
	{
		for (std::map<string, std::list<Crime>>::const_iterator itlow = base.begin(); itup != base.end(); ++it)
		{

			//cout << std::left;
			cout << it->first + ":\n";

			for (std::list<Crime>::const_iterator jt = it->second.begin(); jt != it->second.end(); ++jt)
			{

				cout << "\t" << *jt << ";\n";
			}
			cout << "\n------------------------------------\n";
		}
	}
	else
		cout << "����� �� �������!" << endl;

	
	//������ � ����
		for (std::map<string, std::list<Crime>>::const_iterator it = base.begin(); it != base.end(); ++it)
		{

			//cout << std::left;
			fout << it->first + ":\n";

			for (std::list<Crime>::const_iterator jt = it->second.begin(); jt != it->second.end(); ++jt)
			{

				fout << "\t" << *jt << ";\n";
			}
			fout << "\n------------------------------------\n";
		}
	
	
	fout.close();
	system("notepad file.txt");
	
}
	void print(const std::map < std::string, std::list<Crime>>base)
	{
		for (std::map<string, std::list<Crime>>::const_iterator it = base.begin(); it != base.end(); ++it)
		{

			//cout << std::left;
			cout << it->first + ":\n";

			for (std::list<Crime>::const_iterator jt = it->second.begin(); jt != it->second.end(); ++jt)
			{

				cout << "\t" << *jt << ";\n";
			}
			cout << "\n------------------------------------\n";
		}
	}
