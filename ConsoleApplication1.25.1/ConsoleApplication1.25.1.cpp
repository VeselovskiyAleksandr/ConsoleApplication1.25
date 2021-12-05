// ConsoleApplication1.25.1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//Урок 22. Задача 1. Телефонный справочник.

#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <fstream>
#include <locale.h>
using namespace std;

struct note {
	string phoneNumber;
	string family;
	vector <note> listSubscribers;
};


int main()
{
	setlocale(LC_ALL, "Rus");
    cout << "\n                                             Phonebook.";
	map<string, string> phonebook;
	int action = 5;
    string strTel, strName,str="", lineBreak="\n" ;
    char whitespace = ' ';
    vector <string> loadSubscribers;
	do {		
	    cout << "\nВыберите действие: ";
		cout << "\nдля поиска абонента по номеру телефона введите 1";
		cout << "\nдля поиска абонента по имени, фамилии введите 2";
		cout << "\nдля записи абонента в телефонный справочник введите 3";
		cout << "\nдля удаления абонента из телефонного справочника введите 4";
		cout << "\nдля просмотра справочника введите 5";
		cout << "\nдля выхода введите 0";
		cin >> action;
		if (action == 1) {			
			fstream file("C:\\Users\\Александр\\Documents\\text for program\\phonebook.txt");
			if (file.is_open()) {
				cout << "\nThe file is open.";
			}
			else {
				cerr << "\nThe file is not found. ";
				return 1;
			}
			while (!file.eof()) {
				file >> strTel >> strName;
				pair<string, string>addSubscriber(strTel, strName);
				phonebook.insert(addSubscriber);
				strTel = ""; strName = "";
			}
            cout << "\nВведите номер абонента (формат ввода (XXX)XXX-XX-XX):";
			cin >> strTel;
				if(phonebook.count(strTel)) {
					cout << "\nАбонент с указанным номером телефона: ";
					cout<<strTel<<" " << phonebook[strTel];
				}
				else {
					cout << "\nАбонента с указанным номером телефона нет в списке.";
				}
				file.close();
			}		
		else if (action == 2) {
			fstream file("C:\\Users\\Александр\\Documents\\text for program\\phonebook.txt");
			if (file.is_open()) {
				cout << "\nThe file is open.";
			}
			else {
				cerr << "\nThe file is not found. ";
				return 1;
			}
			while (!file.eof()) {
				file >> strTel >> strName;
				pair<string, string>addSubscriber(strTel, strName);
				phonebook.insert(addSubscriber);
				strTel = ""; strName = "";
			}
			map<string, string>::iterator nameSabs = phonebook.find(strName);
			int count = 0;
			cout << "\nВведите имя, фамилию абонента:";
			cin >> strName;		
			for (map< string, string>::iterator nameSabs = phonebook.begin(); nameSabs != phonebook.end(); nameSabs++) {
				if (nameSabs->second == strName) {
	                cout << "\nАбонент с указанным именем: ";
					cout << "\n" << nameSabs->first << " " << nameSabs->second;
					count++;
				}
			}
                if (count==0) {
					cout << "\nАбонент с указанным именем в телефонном справочнике отсутствует.";
				}
				cout << "\n";
				file.close();
		}
		else if (action == 3) {
			note subscriber;
			fstream file("C:\\Users\\Александр\\Documents\\text for program\\phonebook.txt",ios::out|ios::app);
			if (file.is_open()) {
				cout << "\nThe file is open.";
			}
			else {
				cerr << "\nThe file is not found. ";
				return 1;
			}
			file.close();
			ifstream fileR("C:\\Users\\Александр\\Documents\\text for program\\phonebook.txt");	
				while (!fileR.eof()) {		
					fileR>> strTel >> strName;
				pair<string, string>addSubscriber(strTel, strName);
					phonebook.insert(addSubscriber);
					strTel = ""; strName = "";				
				}
				fileR.close();
			int count=0;
			cout << "\nУкажите количество вводимых абонентов.";
			cin >> count;
			for (int i = 0; i < count; i++) {
				cout << "\nВведите телефонный номер (формат ввода (XXX)XXX-XX-XX):";
				cin >> strTel;;
				cout << "\nВведите имя, фамилию абонента:";
				cin >> strName;
				pair<string, string>addSubscriber(strTel, strName);
				phonebook.insert(addSubscriber);
				cout << "\nАбонент ";
				cout << addSubscriber.first << " " << addSubscriber.second;
				cout << " добавлен в телефонную книгу.";
				subscriber.phoneNumber = addSubscriber.first;
				subscriber.family = addSubscriber.second;
				subscriber.listSubscribers.push_back(subscriber);
			}
			fstream fileRc("C:\\Users\\Александр\\Documents\\text for program\\phonebook.txt",ios::out| ios::trunc);
			fileRc.close();
			fstream fileRec("C:\\Users\\Александр\\Documents\\text for program\\phonebook.txt",ios::app);
			map<string, string>::iterator list;
			for (list= phonebook.begin(); list != phonebook.end();list++) {		
				strTel = list->first;
				strName = list->second;
				fileRec << strTel << whitespace << strName << lineBreak;
				strTel = ""; strName = "";
			}
			cout << "\n";
			fileRec.close();
	}
		else if (action == 4) {
		fstream file("C:\\Users\\Александр\\Documents\\text for program\\phonebook.txt");
		if (file.is_open()) {
			cout << "\nThe file is open.";
		}
		else {
			cerr << "\nThe file is not found. ";
			return 1;
		}
		while (!file.eof()) {
			file >> strTel >> strName;
			pair<string, string>addSubscriber(strTel, strName);
			phonebook.insert(addSubscriber);
			strTel = ""; strName = "";
		}
		file.close();
		cout << "\nВведите номер телефона (формат ввода (XXX)XXX-XX-XX):";
		cin >> strTel;
		cout << "\nВведите имя, фамилию абонента:";
		cin >> strName;
		phonebook[strTel] = strName;
		map<string, string>::iterator nameSabs = phonebook.find(strTel);
		phonebook.erase(strTel);
		cout << "\nАбонент ";
		cout << strTel << " " << strName;
		cout << " удалён из телефонного справочника.";
		fstream fileRc("C:\\Users\\Александр\\Documents\\text for program\\phonebook.txt", ios::out | ios::trunc);
		fileRc.close();
		fstream fileRec("C:\\Users\\Александр\\Documents\\text for program\\phonebook.txt", ios::app);
		for (map< string, string>::iterator nameSabs = phonebook.begin(); nameSabs != phonebook.end(); nameSabs++) {			
				strTel= nameSabs->first; strName=nameSabs->second;
				fileRec << strTel << whitespace << strName << lineBreak;
				strTel = ""; strName = "";
		}
		cout << "\n";
		fileRc.close();
          }
		else if (action == 5) {
			ifstream file("C:\\Users\\Александр\\Documents\\text for program\\phonebook.txt");
			cout << lineBreak;
			while (!file.eof()) {
				file >> str;
				loadSubscribers.push_back(str);
				str = "";
			}
			cout << "\n       Список абонентов:\n";
			for (int i = 0; i < loadSubscribers.size(); i++) {
				cout << loadSubscribers[i];
				if (i%2==1) {
					cout << "\n";
				}
				else if ((i % 2 == 0) || (i % 4 == 0)){			
					cout << whitespace;
				}
			}
			file.close();
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
