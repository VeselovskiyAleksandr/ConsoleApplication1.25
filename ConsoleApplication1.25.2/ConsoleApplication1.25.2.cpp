// ConsoleApplication1.25.2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//Урок 22. Задача 2.Регистратура.

#include <iostream>
#include <map>
#include <string>
#include <locale.h>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");
	map<string, string>registry;
	int action = 0, num=0;
	string key, meaning, next="next";
	cout << "\nВыберите действие: ";
	do {
		cout << "\na) для записи пациентов введите 1";
		cout << "\nb) для вызова в регистратуру введите 2";
		cout << "\nc) для завершения работы введите 0.";
		cin >> action;
		if (action == 1) {
			cout << "\nУкажите количество записываемых пациентов.";
			cin >> num;
			for (int i = 0; i < num; i++) {
				cout << "\nВведите фамилию пациента английскими буквами.";
				cin >> key;
				meaning = key;
				key += to_string(i);
				pair<string, string> assign(key, meaning);
				registry.insert(assign);			
				}
			int count = 1;
                cout << "\nСписок пациентов: ";
				for (map<string, string>::iterator regular = registry.begin(); regular != registry.end(); regular++) {
					cout << "\n"<<count<<") " << regular->second;
					count++;
			}
		}
		else if (action == 2) {
			if (registry.empty()) {
				cout << "\nСоставте список пациентов (пункт a).";
			}
         else {
				cout << next;
				map<string, string>::iterator regular =registry.begin();
				registry.erase(regular);
				for (map<string, string>::iterator regular = registry.begin(); regular != registry.end(); regular++) {
					cout << "\n" << regular->second;
				}
			}
		}
	} while (action != 0);
	return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
