#include <iostream>
#include<set>
#include<map>
#include<list>


using std::cin;
using std::cout;
using std::endl;
//#define STL_SET
//#define STL_MAP
#define STL_MAP2
#define tab "\t"
void main()
{
	setlocale(LC_ALL, "");

#ifdef STL_SET
	std::set<int>myset = { 50,25,75,16,32,64,80 };
	/*for (int i = 0; i < myset.size(); i++)
	{
		cout << myset[i] << tab;
	}
	cout << endl;*/
	for (std::set<int>::iterator it = myset.begin(); it != myset.end(); ++it)
	{
		cout << *it << tab;
	}
	cout << endl;
	int value;
	cout << "Введите добавляемое значение: "; cin >> value;
	myset.insert(value);
	for (int i : myset)cout << i << tab; cout << endl;
	cout << "Введите удаляемое значение: "; cin >> value;
	myset.erase(value);
	for (int i : myset)cout << i << tab; cout << endl;
	for (std::set<int>::iterator it = myset.lower_bound(25); it != myset.upper_bound(75); ++it)
	{
		cout << *it << tab;
	}
#endif // STL_SET

#ifdef STL_MAP
	std::map<int, std::string>week =
	{
		std::pair<int,std::string>(0,"Sunday"),
		std::pair<int,std::string>(1,"Monday"),
		std::pair<int,std::string>(2,"Tuesday"),
		std::pair<int,std::string>(3,"Wednesday"),
		std::pair<int,std::string>(4,"Thursday"),
		std::pair<int,std::string>(5,"Friday"),
		{6,"Saturday"},
	};
	for (std::map<int, std::string>::iterator it = week.begin(); it != week.end(); ++it)
	{
		cout << it->first << tab << it->second << endl;
	}
#endif // STL_MAP
	std::map<std::string, std::list<std::string>>dictonary
	{
		std::pair < std::string,std::list<std::string>>("splice",{"сращивание","сваривание","свадьба"}),
		{"space",{"космос","пространство","пробел"}},
		{"pencil",{"карандаш"}},
		{"desk",{"рабочий стол","доска"}},
		{"appreciate",{"быть признательным","ценить","быть благодарным"}}
	};
	for (std::map < std::string, std::list<std::string>>::iterator it = dictonary.begin(); it != dictonary.end(); ++it)
	{
		cout << it->first << ":";
		for (std::list<std::string>::iterator jt = it->second.begin(); jt != it->second.end(); ++jt)
		{
			cout << *jt << ",";
		}
		cout << endl;
	}
	cout << "\n--------------------------\n";
	for (std::pair<std::string, std::list<std::string>> i : dictonary)
	{
		cout.width(15);
		cout << std::left;
		cout << i.first + ":";
		for (std::string j : i.second)cout << j << ", ";
		cout << "\b\b;\n";
	}
}