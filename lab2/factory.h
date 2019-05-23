#include <iostream>
#include <string> 
#include <vector>
#include <cstdlib>

using namespace std;

//  класс для организации работы меню пользовател¤
class Factory
{
	// хранилище указателей на объекты базового класса
	std::vector <StringObj*> pObjects; // вектор указателей на объекты строк потомков StringObj
public:
	Factory(){}
	void AddObject(void);
	void Operations();
	void DeleteObject(void);
	void ListAllObjects();
	void ShowObject(void);
	int SelectItem(int n);
};

