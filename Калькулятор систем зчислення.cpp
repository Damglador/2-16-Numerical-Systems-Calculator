#include <iostream>
#include <Windows.h>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;
#pragma execution_character_set("utf-8")
namespace Color {
    const string Reset = "\033[0m";
    const string Red = "\033[31m";
    const string Green = "\033[32m";
    const string Blue = "\033[34m";
    const string Yellow = "\033[33m";
    const string White = "\033[37m";
    const string YellowG = "\x1B[93m";
    const string Purple = "\x1B[35m";
    const string something = "\033[3;100;30m";
}
using namespace Color;
void error(string s) {
    cout << Color::Red << s << Color::Reset << endl;
}
const int arsize = 40;
void reset(int* arr) {
    for (int i = 0; i < arsize; i++) {
        arr[i] = 0;
    }
}
void tonumarr(const string number, int* ar2, int base) {
    reset(ar2);
    int numberLength = number.length();
    int index = arsize - number.length();

    if (base < 2 || base > 16) {
        cout << Red << "Invalid base. Supported bases are between 2 and 16." << Reset << std::endl;
        return;
    }

    for (int i = 0; i < numberLength; ++i) {
        char currentChar = number[i];
        int digit;

        if (currentChar >= '0' && currentChar <= '9') {
            digit = currentChar - '0';
        }
        else if ((currentChar >= 'A' && currentChar <= 'F') || (currentChar >= 'a' && currentChar <= 'f')) {
            digit = (currentChar >= 'a') ? (currentChar - 'a' + 10) : (currentChar - 'A' + 10);
        }
        else {
            cout << Red << "Invalid input character: " << currentChar << Reset << endl;
            return;
        }

        if (digit >= base) {
            cout << Red << "Invalid digit for the specified base." << Reset << endl;
            return;
        }
        ar2[index] = digit;
        index++;
    }
}
void decto(long long unsigned int num, int* ar2, int base) {
    reset(ar2);
    int i = arsize - 1;
    while (num > 0) {
        ar2[i] = num % base;
        num = num / base;
        i--;
    }
}
long long unsigned int todec(int ar[], int base) {
    long long unsigned int dec = 0;
    int p;
    for (int i = arsize - 1; i >= 0; i--) {
        p = i - arsize + 1;
        dec += ar[i] * pow(base, abs(p));
    }
    return dec;
}
void coutarr(int ar[], bool end) {
    bool yep = false;
    for (int i = 0; i < arsize; i++) {
        if (ar[i] != 0 || yep == true) {
            if (ar[i] < 10)
                cout << ar[i];
            else if (ar[i] >= 10) {
                switch (ar[i]) {
                case 10: cout << "A";
                    break;
                case 11: cout << "B";
                    break;
                case 12: cout << "C";
                    break;
                case 13: cout << "D";
                    break;
                case 14: cout << "E";
                    break;
                case 15: cout << "F";
                    break;
                default: error("Error");
                }
                    
            }
            yep = true;
        }
    }
    if (end)
        cout << endl;
}
void coutbin(int ar[], bool end) {
    bool yep = false;
    for (int i = 0; i < arsize; i++) {
        if (ar[i] != 0 || yep == true) {
            if (i % 4 == 0 && i != 0 && yep)
                cout << " ";
            cout << ar[i];
            yep = true;
        }
    }
    if (end)
        cout << endl;
}
void add(int ar1[], int ar2[], int* res, int base) {
    reset(res);
    decto(todec(ar1, base) + todec(ar2, base), res, base);
}
void multiply(int* ar1, int* ar2, int* res, int base) {
    reset(res);
    decto(todec(ar1, base) * todec(ar2, base), res, base);
}
int main() {
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
    const int arsize = 40;
    int ar1[arsize] = {};
    int ar2[arsize] = {};
    int res[arsize] = {};
    reset(ar1);
    reset(ar2);
    //==========================================
    cout << Purple << "=================== Завдання #1 ===================" << Reset << endl;
    cout << Green << "Base 10\t\t\tBase 2" << Reset << endl;
    decto(430, ar2, 2);
    cout << "430" << "\t\t\t";  coutbin(ar2, true);
    decto(3004, ar2, 2);
    cout << "3004" << "\t\t\t";  coutbin(ar2, true);
    cout << Green << "Base 10\t\t\tBase 8" << Reset << endl;
    decto(480, ar2, 8);
    cout << "480" << "\t\t\t";  coutarr(ar2, true);
    decto(8004, ar2, 8);
    cout << "8004" << "\t\t\t";  coutarr(ar2, true);
    cout << Green << "Base 10\t\t\tBase 16" << Reset << endl;
    decto(4160, ar2, 16);
    cout << "4160" << "\t\t\t";  coutarr(ar2, true);
    decto(16004, ar2, 16);
    cout << "16004" << "\t\t\t";  coutarr(ar2, true);
    cout << Green << "Base 10\t\t\tBase 3" << Reset << endl;
    decto(3004, ar2, 3);
    cout << "3004" << "\t\t\t";  coutarr(ar2, true);
    cout << Green << "Base 10\t\t\tBase 7" << Reset << endl;
    decto(7004, ar2, 7);
    cout << "7004" << "\t\t\t";  coutarr(ar2, true);
    cout << Green << "Base 2\t\t\tBase 10" << Reset << endl;
    tonumarr("0010001101001010", ar2, 2);
    coutarr(ar2, false); cout << "\t\t" << todec(ar2, 2) << endl;
    tonumarr("100001001010", ar2, 2);
    coutarr(ar2, false); cout << "\t\t" << todec(ar2, 2) << endl;
    cout << Green << "Base 2\t\t\tBase 8" << Reset << endl;
    tonumarr("10001111", ar2, 2);
    decto(todec(ar2, 2), ar2, 8);
    cout << "10001111" << "\t\t"; coutarr(ar2, true);
    tonumarr("000110000010", ar2, 2);
    decto(todec(ar2, 2), ar2, 8);
    cout << "000110000010" << "\t\t"; coutarr(ar2, true);
    cout << Green << "Base 2\t\t\tBase 16" << Reset << endl;
    tonumarr("001001001111", ar2, 2);
    decto(todec(ar2, 2), ar2, 16);
    cout << "001001001111" << "\t\t"; coutarr(ar2, true);
    tonumarr("111101000010", ar2, 2);
    decto(todec(ar2, 2), ar2, 16);
    cout << "111101000010" << "\t\t"; coutarr(ar2, true);
    cout << Green << "Base 8\t\t\tBase 2" << Reset << endl;
    tonumarr("472", ar2, 8);
    decto(todec(ar2, 8), ar2, 2);
    cout << "472" << "\t\t\t"; coutbin(ar2, true);
    tonumarr("7204", ar2, 8);
    decto(todec(ar2, 8), ar2, 2);
    cout << "7204" << "\t\t\t"; coutbin(ar2, true);
    cout << Green << "Base 8\t\t\tBase 10" << Reset << endl;
    tonumarr("4710", ar2, 8);
    cout << "4710" << "\t\t\t" << todec(ar2, 8) << endl;
    tonumarr("71004", ar2, 8);
    cout << "71004" << "\t\t\t" << todec(ar2, 8) << endl;
    cout << Green << "Base 8\t\t\tBase 16" << Reset << endl;
    tonumarr("4716", ar2, 8);
    decto(todec(ar2, 8), ar2, 16);
    cout << "4716" << "\t\t\t";  coutarr(ar2, true);
    tonumarr("71604", ar2, 8);
    decto(todec(ar2, 8), ar2, 16);
    cout << "71604" << "\t\t\t";  coutarr(ar2, true);
    cout << Green << "Base 16\t\t\tBase 2" << Reset << endl;
    tonumarr("4F2", ar2, 16);
    decto(todec(ar2, 16), ar2, 2);
    cout << "4F2" << "\t\t\t";  coutarr(ar2, true);
    tonumarr("F204", ar2, 16);
    decto(todec(ar2, 16), ar2, 2);
    cout << "F204" << "\t\t\t";  coutarr(ar2, true);
    cout << Green << "Base 16\t\t\tBase 8" << Reset << endl;
    tonumarr("4F8", ar2, 16);
    decto(todec(ar2, 16), ar2, 8);
    cout << "4F8" << "\t\t\t";  coutarr(ar2, true);
    tonumarr("F804", ar2, 16);
    decto(todec(ar2, 16), ar2, 8);
    cout << "F804" << "\t\t\t";  coutarr(ar2, true);
    cout << Green << "Base 16\t\t\tBase 10" << Reset << endl;
    tonumarr("4F10", ar2, 16);
    cout << "4F10" << "\t\t\t" << todec(ar2, 16) << endl;
    tonumarr("F1004", ar2, 16);
    cout << "F1004" << "\t\t\t" << todec(ar2, 16) << endl;
    cout << Purple << "=================== Завдання #2 ===================" << Reset << endl;
    cout << Green << "Base: 2" << Reset << endl;
    tonumarr("10011100111001001110", ar1, 2);
    tonumarr("1100101011101011111", ar2, 2);
    add(ar1, ar2, res, 2);
    coutbin(res, true);
    tonumarr("110111011001101", ar1, 2);
    tonumarr("1101111110", ar2, 2);
    multiply(ar1, ar2, res, 2);
    coutbin(res, true);
    tonumarr("10111110111001101110", ar1, 2);
    tonumarr("1011011110", ar2, 2);
    multiply(ar1, ar2, res, 2);
    coutbin(res, true);
    cout << Green << "Base: 8" << Reset << endl;
    tonumarr("765432101234567004", ar1, 8);
    tonumarr("47415263036251470", ar2, 8);
    add(ar1, ar2, res, 8);
    coutarr(res, true);
    tonumarr("765432104", ar1, 8);
    tonumarr("4514701", ar2, 8);
    multiply(ar1, ar2, res, 8);
    coutarr(res, true);
    tonumarr("765432104", ar1, 8);
    tonumarr("43625147", ar2, 8);
    multiply(ar1, ar2, res, 8);
    coutarr(res, true);
    cout << Green << "Base: 16" << Reset << endl;
    tonumarr("FEDCBA09876504", ar1, 16);
    tonumarr("4074185296301", ar2, 16);
    add(ar1, ar2, res, 16);
    coutarr(res, true);
    tonumarr("FDCA04", ar1, 16);
    tonumarr("4F98", ar2, 16);
    multiply(ar1, ar2, res, 16);
    coutarr(res, true);
    tonumarr("EB7604", ar1, 16);
    tonumarr("4F85", ar2, 16);
    multiply(ar1, ar2, res, 16);
    coutarr(res, true);
    system("pause");
}
