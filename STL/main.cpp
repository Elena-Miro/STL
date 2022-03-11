#include<iostream>
#include<array>
#include<vector>
#include<deque>
#include<list>
#include <forward_list>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

#define tab "\t"
//#define STL_ARRAY
//#define STL_VACTOR
//#define STL_DEQUE
//#define STL_LIST
#define STL_FORWARD_LIST
#define delimiter "\n------------------------------\n"
void main()
{
	setlocale(LC_ALL, "");
#ifdef STL_ARRAY
	std::array<int,5> arr = { 3,5,8,13,21 };
	for (int i = 0; i < arr.size(); i++)
	{
		cout << arr[i] << tab;
	}
	cout << endl;
#endif // STL_ARRAY
#ifdef STL_VACTOR
	std::vector<int> vec = { 0,1,1,2,3,5,8,13,21,34 };
	for (int i = 0; i < vec.size(); i++)
	{
		cout << vec[i] << tab;
	}
	cout << endl;
	cout << "Size: "<<vec.size() << endl;
	cout << "MaxSize: " << vec.max_size() << endl;
	cout << "Capacity: " << vec.capacity() << endl;
	cout << delimiter<< endl;

	
	//vec.shrink_to_fit();//уменьшает до фактического размера век
	vec.reserve(25);//изменяет фактический рзмер вектора

	try
	{
		//throw "My exaption";
		throw 4;
		for (int i = 0; i < vec.capacity(); i++)
		{
			//cout << vec[i] << tab;
			cout << vec.at(i) << tab;//работает как квадратные скобки, разница в обработке исключений
		}
		cout << endl;
	}
	catch (const std::exception& e)//сообщение об ошибке
	{
		//EHa
		std::cerr << e.what() << endl;
	}
	catch (int e)
	{
		std::cerr << "Error e" << endl;
	}
	catch (const char* e)
	{
		std::cerr << e << endl;
	}
	catch (...)
	{
		cout << "Somsing happend!" << endl;
	}


	cout << "Нулевой элемент вектора: " << vec.front() << endl;
	cout << "Последний элемент вектора: " << vec.back() << endl;
	vec.assign({ 1,2,4,8,16,32 });
	for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
	{
		cout << *it << tab;
	}
	int index;
	int value;
	int count;
	cout << "Введите индекс добавляемого элемента: "; cin >> index;
	cout << "Введите значение добавляемого элемента: "; cin >> value;
	cout << "Сколько раз добавить значение: "; cin >> count;

	//std::vector<int>::const_iterator position = vec.begin() + index;
	vec.insert(vec.begin()+index,count, value);
	for (int i : vec)cout << i << tab; cout << tab;
	vec.insert(vec.begin() + index, { 3,5,8,13,21 });
	for (int i : vec)cout << i << tab; cout << endl;
#endif // STL_VACTOR
#ifdef STL_DEQUE

	std::vector<int> vec;
	std::deque <int>deque = { 3,5,13,21 };
	deque.push_back(34);
	deque.push_back(55);
	deque.push_back(89);
	for (int i = 0; i < deque.size(); i++)
	{
		cout << deque[i] << tab;
	}
	cout << endl;
#endif // STL_DEQUE
	
#ifdef STL_LIST
	std::list<int>::iterator it;
	int index;
	int value;
	std::list<int> mylist = { 3,5,13,21 };
	for (it = mylist.begin(); it != mylist.end(); ++it)
		cout << *it << tab; cout << endl;
	cout << "Введите индекс добавляемого элемента: "; cin >> index;
	cout << "Введите значение добавляемого элемента: "; cin >> value;

	it = mylist.begin();
	for (int i = 0; i < index; ++i)++it;

	mylist.insert(it, value);

	for (it = mylist.begin(); it != mylist.end(); ++it)cout << *it << tab; cout << tab;

#endif // STL_LIST
	std::forward_list<int>::iterator it;
	int index;
	int value;
	std::forward_list<int> mylist = { 3,5,13,21,55,77,88 };
	for (it = mylist.begin(); it != mylist.end(); ++it)
		cout << *it << tab; cout << endl;
	cout << "Введите индекс добавляемого элемента: "; cin >> index;
	cout << "Введите значение добавляемого элемента: "; cin >> value;

	it = mylist.before_begin();
	for (int i = 0; i < index; ++i)++it;

	mylist.insert_after(it, value);

	for (it = mylist.begin(); it != mylist.end(); ++it)cout << *it << tab; cout << tab;

}
