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

void load(std::map < std::string, std::list<Crime>>& base, const std::string& filename);
void save(const std::map < std::string, std::list<Crime>>base, const std::string& filename);
void print(const std::map < std::string, std::list<Crime>>base);
void add(std::map<std::string, std::list<Crime>>& base);

void main()
{
	//setlocale(LC_ALL, "");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	//ofstream fout("file.txt");

	std::map<std::string, std::list<Crime>> base/* =
	{
		{ "a777km",{Crime(1,"улица Ленина"),Crime(2,"улица Фрунзе")} },
		{ "a557ab",{Crime(5,"улица Космонавтов")}},
		{ "a001а" ,{Crime(4,"перекресток Ленина"),Crime(3,"улица Октябрьская") } },
		{ "a002а" ,{Crime(2,"перекресток Ленина"),Crime(5,"улица Октябрьская") } }
	}*/;
	load(base, "base.txt");
	print(base);
	//save(base, "base.txt");
	//add(base);
	//print(base);

#ifdef DEBUG

	//найти в базе автомобиль

	cout << "Введите номер автомобиля: "; cin >> licence_plate;
	//std::map<std::string, std::list<Crime>>::iterator it = base.find(licence_plate);


	it = base.find(licence_plate);
	if (it != base.end())
	{
		cout << "Номер машины: " << it->first << "  совершил правонарушения: ";

		for (std::list<Crime>::const_iterator jt = it->second.begin(); jt != it->second.end(); ++jt)
		{

			cout << "\t" << *jt << ";\n";
		}
		cout << "\n------------------------------------\n";
	}
	else
		cout << "Номер машины: " << licence_plate << "не найден!" << endl;

	//найти авто в диапаоне(not done)
	std::string licence_plate1;
	std::string licence_plate2;
	cout << "Введите дапазон номеров от: "; cin >> licence_plate; cout << " до " << endl; cin >> licence_plate2;
	it = base.lower_bound(licence_plate);
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
		cout << "Машин не найдено!" << endl;


	//запись в файл
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

#endif // DEBUG

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
void add(std::map<std::string, std::list<Crime>>& base)
{
	std::string licence_plate;
	int id;
	std::string place;
	cout << "Введите номер автомобиля: "; cin >> licence_plate;
	cout << "Введите правонарушение(номер статьи): "; cin >> id;
	cout << "Введите место происшествия: ";
	cin.clear();
	cin.ignore();
	std::getline(std::cin, place);
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
}
void save(const std::map < std::string, std::list<Crime>>base, const std::string& filename)
{
	std::ofstream fout(filename);
	for (std::pair<std::string, std::list<Crime>>i : base)
	{
		fout << i.first << ":\t";
		for (Crime j : i.second)
		{
			fout << j << ", ";
		}
		fout.seekp(-2,ios::cur);//сдвигаем курсор на 2 позиции влево
		fout << ";\n";
	}
	fout.close();
	std::string command = std::string("start notepad ") + filename;
	system(command.c_str());
}
void load(std::map < std::string, std::list<Crime>>& base,  const std::string& filename)
{
	std::ifstream fin(filename);
	if (fin.is_open())
	{
		while (!fin.eof())
		{
			std::string licence_plate;
			int id;
			std::string place;
			std::string crimes;
			std::getline(fin, licence_plate,':');//читаем гос номер
			std::getline(fin, crimes);//все правнарушения
			if (crimes.empty())continue;//если пустая строка продолжаем 
			if (crimes.find(',') != std::string::npos)//если больше 1 правонарушение. находим заяпятые в строке и выделяем подстроку
			{
				for (int start = 0, end = crimes.find(','); end != std::string::npos; start = end)
				{
					end = crimes.find(',', start + 1);//позиция запятой
					place = crimes.substr(start + 1, end);//читаем часть строки до зап
					place.erase(0, place.find_first_not_of(' '));// проверить//удаляем пробелы
					id = std::stoi(place.substr(0, place.find_first_of(' ')));//читаем статью номер правонаруш
					place.erase(0, place.find_first_of(' ') + 1);//удаляем номер прав из адреса
					base[licence_plate].push_back(Crime(id, place));//добавляем правонаруш в базу
				}
			}
			else
			{
				id = std::stoi(crimes.substr(0, crimes.find_first_of(' ')));//запятой нет номер правонаруш
				crimes.erase(0, crimes.find_first_of(' '));//удаляем из строки
				base[licence_plate].push_back(Crime(id, crimes));//добавляем в базу
			}

		}
		fin.close();
	}
	else
	{
		std::cerr << "Error:file not found" << endl;
	}

}