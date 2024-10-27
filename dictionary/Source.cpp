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
        cout << "\033[35m\tMenu: \033[0m" << endl;
        cout << "1. Add a word with translation" << endl;
        cout << "2. Delete a word" << endl;
        cout << "3. Find a word" << endl;
        cout << "4. Save dictionary to file" << endl;
        cout << "5. Print dictionary to console" << endl;
        cout << "0. Exit" << endl;
        cout << "\033[90mYour choice: \033[0m";

        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            system("cls");
            string word;
            string translation;
            cout << "Enter a word in English: ";
            cin >> word;
            cout << "Enter the translation: ";
            cin >> translation;
            dict.insert(make_pair(word, translation));
            system("cls");
            cout << "\033[32mWord added!\033[0m" << endl;
            cout << endl;
            break;
        }
        case 2:
        {
            system("cls");
            string word;
            cout << "Enter the word to delete: ";
            cin >> word;
            auto forRemove = dict.find(word);
            system("cls");
            if (forRemove != dict.end())
            {
                dict.erase(forRemove);
                cout << "\033[32mWord deleted!\033[0m" << endl;
            }
            else
            {
                cout << "\033[31mWord not found!\033[0m" << endl;
            }
            cout << endl;
            break;
        }
        case 3:
        {
            system("cls");
            string s;
            cout << "Enter the word to search for: ";
            cin >> s;
            auto ptrf = dict.find(s);
            system("cls");
            if (ptrf != dict.end())
            {
                cout << "\033[32mFound:\033[0m " << ptrf->first << " - " << ptrf->second << endl;
            }
            else
            {
                cout << "\033[31mWord not found!\033[0m" << endl;
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
                cout << "\033[32mFile saved\n\033[0m";
            }
            else
            {
                cout << "\033[31mFailed to save file\033[0m\n";
            }
            cout << endl;
            break;
        }
        case 5:
            system("cls");
            cout << "\033[35m\tDictionary: \033[0m" << endl;
            for (auto ptr = dict.begin(); ptr != dict.end(); ptr++)
            {
                cout << ptr->first << " - " << ptr->second << endl;
            }
            cout << endl;
            break;
        case 0:
            system("cls");
            cout << "\033[35mExiting the program.\033[0m";
            break;
        default:
            system("cls");
            cout << "\033[31mInvalid choice, try again!\033[0m" << endl;
            break;
        }
    } while (choice != 0);
}
