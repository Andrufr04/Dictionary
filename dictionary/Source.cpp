#include <iostream>
#include <fstream>
#include <string>
#include <map>
using namespace std;

int main()
{
    setlocale(0, "ru");
    map<string, string> dict;
    dict.insert(make_pair("dog", "собака"));
    dict.insert(make_pair("cat", "кошка"));
    dict.insert(make_pair("parrot", "попугай"));

    int choice;

    do 
    {

    cout << "\033[35m\tМеню: \033[0m" << endl;
    cout << "1. Добавить слово с переводом " << endl;
    cout << "2. Удалить слово" << endl;
    cout << "3. Найти слово" << endl;

    cout << "4. Сохранить словарь в файл" << endl;
    cout << "5. Вывести словарь на консоль" << endl;
    cout << "0. Выход" << endl;
    cout << "\033[90mВаш выбор: \033[0m";

    cin >> choice;

    switch (choice)
    {
    case 1: 
    {
        system("cls");
        string word;
        string translation;
        cout << "Введите слово на английском: ";
        cin >> word;
        cout << "Введите перевод: ";
        cin >> translation;
        dict.insert(make_pair(word, translation));
        system("cls");
        cout << "\033[32mСлово добавлено!\033[0m" << endl;
        cout << endl;
        break;
    }
    case 2:
    {
        system("cls");
        string word;
        cout << "Введите слово для удаления: ";
        cin >> word;
        auto forRemove = dict.find(word);
        system("cls");
        if (forRemove != dict.end())
        {
            dict.erase(forRemove);
            cout << "\033[32mСлово удалено!\033[0m" << endl;
        }
        else 
        {
            cout << "\033[31mСлово не найдено!\033[0m" << endl;
        }
        cout << endl;
        break;
    }
    case 3:
    {
        system("cls");
        string s;
        cout << "Введите слово для поиска ";
        cin >> s;
        auto ptrf = dict.find(s);
        system("cls");
        if (ptrf != dict.end())
        {
            /*system("cls");
            system("color 0B");*/
            cout << "\033[32mНайдено:\033[0m " << ptrf->first << " - " << ptrf->second << endl;
        }
        else
        {
            /*system("cls");*/
            //system("color help");
            /* system("color 0C");*/
            cout << "\033[31mСлово не найдено!\033[0m" << endl;

        }
        cout << endl;
        break;
    }
    case 4:
    {
        system("cls");
        ofstream file("dictionary.txt");
        if (file.is_open())
        {
            for (auto ptr = dict.begin(); ptr != dict.end(); ptr++)
            {
                file << ptr->first << " - " << ptr->second << endl;
            }
            file.close();
            cout << "\033[32mФайл сохранен\n\033[0m";
        }
        else
        {
            cout << "\033[31mНеудалось сохранить файл\033[0m\n";
        }
        cout << endl;
        break;
    }
    case 5:
        system("cls");
        cout << "\033[35m\tCловарь: \033[0m" << endl;
        for (auto ptr = dict.begin(); ptr != dict.end(); ptr++)
        {
            cout << ptr->first << " - " << ptr->second << endl;
        }
        cout << endl;
        break;
    case 0:
        system("cls");
        cout << "\033[35mВыход из программы.\033[0m";
        break;
    default:
        system("cls");
        cout << "\033[31mНеверный выбор, попробуйте снова!\033[0m" << endl;
        break;
    }










    }while (choice != 0);
}
