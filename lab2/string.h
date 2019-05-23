#include <iostream>
#include <string> 
#include <vector>
#include <cstdlib>

using namespace std;

#define MAX_STRING_LEN 100 // максимальная длина строк в символах

// Базовый  абстрактный класс
class StringObj
{
public:
	virtual const std::string& GetName() = 0;
	virtual const std::string& GetVal() = 0;
	virtual int GetSize() = 0;
	virtual void Show(void) = 0;
};

// класс Символьная строка (произвольная строка данных)
class SymbString : public StringObj
{
protected:
	std::string name; // имя объекта
	std::string value;// значение(данные) объекта
public:
	//конструктор по-умолчанию
	SymbString(){}
	SymbString(std::string _name) :name(_name){}// конструктор с параметром: имя объекта
	SymbString(std::string _name, std::string _val) :name(_name), value(_val){}// конструктор с двумя параметрами: имя и значение
	~SymbString(){} // деструктор
	SymbString& operator=(SymbString &p);

	virtual const std::string& GetName(){ return name; }
	virtual const std::string& GetVal(){ return value; }
	virtual int GetSize() { return value.size(); }
	virtual void Show(void);

	friend SymbString operator+(SymbString &s1, SymbString &s2);
};


// Класс Восьмеричная строка (изображение восьмеричного числа)
// наследник от класса Символьной строки
class OctString : public SymbString
{
protected:
	long int GetDecVal(void);
public:
	OctString();// конструктор
	OctString(std::string _name);// конструктор
	OctString(std::string _name, std::string _val);// конструктор
	virtual void Show(void);
	friend OctString operator+(OctString &os1, OctString &os2);
	
};

SymbString operator+(SymbString &s1, SymbString &s2);
OctString operator+(OctString &os1, OctString &os2);
bool isOctString(string s);
