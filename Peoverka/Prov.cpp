#include <iostream>
#include <Windows.h>
#include <string>

using namespace std;

int main() {
    setlocale(LC_ALL, "RUS");

    cout << "������� ������: ";
    string str;
    getline(cin, str);

    cout << "������� ������� ��� ������: ";
    string chars;
    getline(cin, chars);

    HINSTANCE hDll = LoadLibrary(L"DynamicLib.dll");
    typedef bool (*Search)(const char*, const char*);

    Search findCharsInString = (Search)GetProcAddress(hDll, "Search");
    
    bool result = findCharsInString(str.c_str(), chars.c_str());

    if (result) {
        cout << "��� ������� ������� � ������. '"<< str<< "' '" << chars << "'" << endl;
    }
    else {
        cout << "�� ��� ������� ������� � ������." << endl;
    }

    FreeLibrary(hDll);

    return 0;
}