#include <iostream>
#include <fstream>
#include <string>
#include <map>
using namespace std;

int main()
{
    setlocale(0, "ru");
    map<string, string> dict;
    dict.insert(make_pair("dog", "������"));
    dict.insert(make_pair("cat", "�����"));
    dict.insert(make_pair("parrot", "�������"));

    int choice;

    do 
    {

    cout << "\033[35m\t����: \033[0m" << endl;
    cout << "1. �������� ����� � ��������� " << endl;
    cout << "2. ������� �����" << endl;
    cout << "3. ����� �����" << endl;

    cout << "4. ��������� ������� � ����" << endl;
    cout << "5. ������� ������� �� �������" << endl;
    cout << "0. �����" << endl;
    cout << "\033[90m��� �����: \033[0m";

    cin >> choice;

    switch (choice)
    {
    case 1: 
    {
        system("cls");
        string word;
        string translation;
        cout << "������� ����� �� ����������: ";
        cin >> word;
        cout << "������� �������: ";
        cin >> translation;
        dict.insert(make_pair(word, translation));
        system("cls");
        cout << "\033[32m����� ���������!\033[0m" << endl;
        cout << endl;
        break;
    }
    case 2:
    {
        system("cls");
        string word;
        cout << "������� ����� ��� ��������: ";
        cin >> word;
        auto forRemove = dict.find(word);
        system("cls");
        if (forRemove != dict.end())
        {
            dict.erase(forRemove);
            cout << "\033[32m����� �������!\033[0m" << endl;
        }
        else 
        {
            cout << "\033[31m����� �� �������!\033[0m" << endl;
        }
        cout << endl;
        break;
    }
    case 3:
    {
        system("cls");
        string s;
        cout << "������� ����� ��� ������ ";
        cin >> s;
        auto ptrf = dict.find(s);
        system("cls");
        if (ptrf != dict.end())
        {
            /*system("cls");
            system("color 0B");*/
            cout << "\033[32m�������:\033[0m " << ptrf->first << " - " << ptrf->second << endl;
        }
        else
        {
            /*system("cls");*/
            //system("color help");
            /* system("color 0C");*/
            cout << "\033[31m����� �� �������!\033[0m" << endl;

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
            cout << "\033[32m���� ��������\n\033[0m";
        }
        else
        {
            cout << "\033[31m��������� ��������� ����\033[0m\n";
        }
        cout << endl;
        break;
    }
    case 5:
        system("cls");
        cout << "\033[35m\tC������: \033[0m" << endl;
        for (auto ptr = dict.begin(); ptr != dict.end(); ptr++)
        {
            cout << ptr->first << " - " << ptr->second << endl;
        }
        cout << endl;
        break;
    case 0:
        system("cls");
        cout << "\033[35m����� �� ���������.\033[0m";
        break;
    default:
        system("cls");
        cout << "\033[31m�������� �����, ���������� �����!\033[0m" << endl;
        break;
    }










    }while (choice != 0);
}
