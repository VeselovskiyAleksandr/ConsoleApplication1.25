// ConsoleApplication1.25.3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//Урок 22. Задача 3. Анаграммы.

//#include <iostream>
//#include <map>
//#include <string>
//#include <locale.h>
using namespace std;

//int main()
//{
	//setlocale(LC_ALL, "Rus");
	//map <int, string> word1;
	//map <int, string> word2;	
	//string str1 = "", str2="";
	//bool anagram = true;
	//int count = 0;
	//cout << "\nВведите первое слово: ";
	//cin >> str1;
	//cout << "\nВведите второе слово: ";
	//cin >> str2;
	//if (str2.length() != str1.length()) {
	//	anagram = false;
		//cout << "\nДанные слова анаграммами не являются .";
		//return 1;
	//}
	//for (int i = 0; i < str1.length(); i++) {
		//word1[i] = str1[i];
		//for (int j = 0; j < str2.length(); j++) {
		//	word2[j] = str2[j];
		//	if (str1[i] == str2[j]) {
		//		word1.erase(i);
		//		word2.erase(j);
		//		count++;
		//		break;
		//	}	
	//  }	
//if (count == i) {
			//	anagram = false;
				//break;
			//}
	//}
	//if (anagram) {
	//	cout << "\nДанные слова являются анаграммами.";
	//}
	//else {
	//	cout << "\nДанные слова анаграммами не являются .";
	//}
//	return 0;
//}
#include <iostream>
#include <string>
#include <map>

void getMap(std::string& str, std::map<char, int>& mp)
{
	for (int i = 0; i < str.length(); i++)
	{
		std::map<char, int>::iterator it = mp.find(str[i]);
		if (it != mp.end())
		{
			mp[str[i]]++;
		//	cout << str[i] << " ";
		}
		else
		{
			mp.insert(std::pair<char, int>(str[i], 1));
		}
	}
}

bool isAnagram(std::string& first, std::string& second)
{
	std::map<char, int> firstMap;
	std::map<char, int> secondMap;

	getMap(first, firstMap);
	getMap(second, secondMap);

	return firstMap == secondMap;
}

int main()
{
	std::string first = "anaconda";
	std::string second = "condaana";

	std::cout << std::boolalpha << isAnagram(first, second) << std::endl;
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
