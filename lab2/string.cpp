#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string> 
#include <vector>
#include <cstdlib>

#include "string.h"



using namespace std;

// функция вывода значения объекта-"символьная строка" на консоль
void SymbString::Show(void)
{
	cout << value.c_str() << endl;
}

//оператор сложения символьных строк
SymbString operator+(SymbString &s1, SymbString &s2)
{
	string ns, vs;
	ns = s1.name + s2.name; // формируем новое имя результата
	vs = s1.value + s2.value;// конкатенация строк

	return SymbString(ns, vs);
}

//оператор присваивания
SymbString& SymbString::operator=(SymbString &p)
{
	cout << "DEBUG: operator=()" << endl;

	if (this != &p)
	{// копируем имя и значение
		value = p.value;
		name = p.name;
	}
	return *this;
}

// оператор сложения восьмиричных строк
OctString operator+(OctString &os1, OctString &os2)
{
	OctString os;
	char buffer[MAX_STRING_LEN];
	long int o1, o2, sum;
	//получаем численные значения записей восьмиричных чисел в строках
	o1 = os1.GetDecVal();
	o2 = os2.GetDecVal();

	sum = o1 + o2;// складываем численные значения 
	_ltoa(sum, buffer, 8);// результат обратно преобразуем с строковое представление
	os.value = buffer;
	os.name = os1.GetName() + os2.GetName(); // имя объекта результата

	return os;
}

long int OctString::GetDecVal(void)
{
	long int ival;
	int i, ic, len;
	char c;
	const char *p = value.c_str();

	len = value.length();
	i = 1;
	ival = 0; // переменная для накопления суммы

	while (len > 0)
	{
		c = p[len - 1];
		ic = c - 48;
		ival += ic*i;
		i *= 8;// увеличиваем множитель для следующего разряда
		len--;
	}

	return ival;
}



// проверка значения строки на десятичное число
bool isOctString(string s)
{
	const string digits = "01234567";

	// цикл перебора всех символов в строке
	for (int i = 0; i<s.size(); i++)
	{
		if (digits.find_first_of(s[i]) == -1)// ищем вхождение очередного символа в  алфавит десятичных цифр
			return false;// недопустимый символ
	}
	return true;// все символы в строке - цифры
}

//конструктор по-умолчанию
OctString::OctString() :SymbString(){}

// конструктор с параметром-имя
OctString::OctString(std::string _name) : SymbString(_name)
{}

// конструктор с двумя параметрами: имя и значение
OctString::OctString(std::string _name, std::string _val) : SymbString(_name, _val)
{}


// показ восьмиричного значения
void OctString::Show()
{

	unsigned int uiv;

	uiv = GetDecVal();

	cout.unsetf(ios::dec); // снятие флага вывода в десятичном формате
	cout.setf(ios::oct);  // установка флага вывода в восмеричном формате
	cout << uiv << endl;  // выводим значение в консоль

	cout.unsetf(ios::oct);// снятие флага вывода в восьмеричном формате
	cout.setf(ios::dec); // установка флага вывода в десятичном формате


}
