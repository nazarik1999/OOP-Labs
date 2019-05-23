#include <iostream>
#include <string> 
#include <vector>
#include <cstdlib>

#include "string.h"
#include "factory.h"

using namespace std;


int main(void)
{
	//установка  русской кодировки в консоли
	setlocale(0, "Russian");

	Factory factory;
	bool bQuit;
	int item;

	system("cls");// очищаем экран консоли

	bQuit = false;//признак выхода из меню программы

	// цикл работы меню программы
	while (!bQuit)
	{
		// вывод на консоль основного меню программы
		cout << "______________________" << endl;
		cout << "1.Добавить объект" << endl;
		cout << "2.Список всех объектов" << endl;
		cout << "3.Показать значение объекта" << endl;
		cout << "4.Операции с объектами" << endl;
		cout << "5.Удалить объект" << endl;
		cout << "6.Выход из программы" << endl;


		item = factory.SelectItem(6);// запрос выбора пользователя

		switch (item)
		{
		case 1: factory.AddObject(); break;// добавление объекта
		case 2: factory.ListAllObjects(); break;// список всех обектов
		case 3: factory.ShowObject(); break;// показать значение объекта
		case 4: factory.Operations(); break;// операции с объектами
		case 5: factory.DeleteObject(); break;// удалить объект
		case 6: bQuit = true; break;

		}

	}


}
