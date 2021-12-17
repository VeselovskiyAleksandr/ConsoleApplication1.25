// ConsoleApplication1.25.2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//Урок 22. Задача 2.Регистратура.

#include <iostream>
#include <map>
#include <string>
using namespace std;

int main()
{
	map<string, int> registry;
	map<string, int>::iterator reg = registry.begin();
	string name = "";
	int count = 0;
	do {
		cin >> name;
		if (name == "next"&& registry.begin()!= registry.end()) {
			map<string, int>::iterator reg = registry.begin();
			registry.erase(reg);
}
		else {
			name += to_string(count);

			pair<string, int> reg(name, count);
			registry.insert(reg);
		}
					count++;
		for (map<string, int>::iterator reg = registry.begin(); reg != registry.end(); reg++) {
						cout << "\n" << reg->first<<" "<<reg->second;
					}
	} while (!registry.empty());	
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
