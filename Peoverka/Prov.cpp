#include <iostream>
#include <Windows.h>
#include <string>

using namespace std;

int main() {
    setlocale(LC_ALL, "RUS");

    cout << "Введите строку: ";
    string str;
    getline(cin, str);

    cout << "Введите символы для поиска: ";
    string chars;
    getline(cin, chars);

    HINSTANCE hDll = LoadLibrary(L"DynamicLib.dll");
    typedef bool (*Search)(const char*, const char*);

    Search findCharsInString = (Search)GetProcAddress(hDll, "Search");
    
    bool result = findCharsInString(str.c_str(), chars.c_str());

    if (result) {
        cout << "Все символы найдены в строке. '"<< str<< "' '" << chars << "'" << endl;
    }
    else {
        cout << "Не все символы найдены в строке." << endl;
    }

    FreeLibrary(hDll);

    return 0;
}