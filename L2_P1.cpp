#include <iostream>
#include <string>
#include <cmath>

using namespace std;

// Funcție pentru a converti un caracter într-un număr întreg
int charToInt(char c) {
    if (c >= '0' && c <= '9')
        return c - '0';
    else if (c >= 'a' && c <= 'z')
        return c - 'a' + 10;
    else if (c >= 'A' && c <= 'Z')
        return c - 'A' + 10;
    return -1; // Caracter nevalid
}

// Funcție pentru a converti un număr întreg în caracter corespunzător
char intToChar(int num) {
    if (num >= 0 && num <= 9)
        return num + '0';
    else if (num >= 10 && num <= 35)
        return num - 10 + 'a';
    return '\0'; // Număr nevalid
}

// Funcție pentru a converti un număr în bază specificată
string convertFromBaseToBase(string num, int b1, int b2) {
    int decimal = 0;
    // Convertirea din b1 în decimal
    for (int i = num.length() - 1; i >= 0; --i) {
        int digit = charToInt(num[i]);
        decimal += digit * pow(b1, num.length() - 1 - i);
    }
    // Convertirea din decimal în b2
    string result = "";
    while (decimal > 0) {
        int remainder = decimal % b2;
        result = intToChar(remainder) + result;
        decimal /= b2;
    }
    return result;
}

int main() {
    string num;
    int b1, b2;
    
    cout << "Introduceți numărul: ";
    cin >> num;
    cout << "Introduceți baza numărului: ";
    cin >> b1;
    cout << "Introduceți baza în care să fie convertit: ";
    cin >> b2;

    if (b1 < 2 || b1 > 26 || b2 < 2 || b2 > 26) {
        cout << "Baze invalide! Bazele trebuie să fie între 2 și 26." << endl;
        return 1;
    }

    string result = convertFromBaseToBase(num, b1, b2);
    cout << "Rezultatul conversiei: " << result << endl;

    return 0;
}
