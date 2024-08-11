#include "euroCheck.h"
#include <iostream>
#include "string"

using std::string;

bool isLetter(char c);
bool isNumber(char c);
int toNumber(char c);

// TODO Aufgabe 2:
//  Implementiert die Funktion `getEuroSerialNumberVersion(serialNumber)`.
//  Sie soll je nach Version der Banknote das entsprechende Jahr (2013 oder 2002) als `int` zurückgeben, und 0 für ungültige Seriennummern.
//  Seriennummern vor 2013 haben *einen* Buchstaben am Anfang. Seit 2013 sind es *zwei*.
int getEuroSerialNumberVersion(string & serialNumber) {
    if(isLetter(serialNumber[0]) && isLetter(serialNumber[1])){
        return 2013;
    }else if(isLetter(serialNumber[0]) && isNumber(serialNumber[1])){
        return 2002;
    }
    return 0;
}

// TODO Aufgabe 3+5:
//  Definiert die Funktion `checkEuroSerialNumber2002(serialNumber)`.
//  Format: L NNNNNNNNNN N
//  (Leerzeichen im Format werden vom Nutzer nicht mit eingegeben, sondern helfen hier nur beim Zählen)
//  Tipp: `x / 10` liefert die Zehnerstelle und `x % 10` die Einerstelle einer zweistelligen Zahl x.

bool checkEuroSerialNumber2002(string &serialNumber) {
    if (serialNumber.length() != 12) return false;

    int letterValue = serialNumber[0] - 'A' + 1;
    int sum = letterValue;

    for (int i = 1; i < 11; i++) {
        if (!isdigit(serialNumber[i])) return false;
        sum += serialNumber[i] - '0';
    }

    int remainder = sum % 9;
    int checkDigit = 8 - remainder;
    if (checkDigit == 0) checkDigit = 9;

    return checkDigit == (serialNumber[11] - '0');
}


// TODO Aufgabe 3+6:
//  Definiert die Funktion `checkEuroSerialNumber2013(serialNumber)`.
//  Format: LL NNNNNNNNN N
bool checkEuroSerialNumber2013(string &serialNumber) {
    if (serialNumber.length() != 12) return false;

    int letterValue1 = serialNumber[0] - 'A' + 1;
    int letterValue2 = serialNumber[1] - 'A' + 1;
    int sum = letterValue1 + letterValue2;

    for (int i = 2; i < 11; i++) {
        if (!isdigit(serialNumber[i])) return false;
        sum += serialNumber[i] - '0';
    }

    int remainder = sum % 9;
    int checkDigit = 7 - remainder;

    if (checkDigit == 0) checkDigit = 9;
    else if (checkDigit == -1) checkDigit = 8;

    return checkDigit == (serialNumber[11] - '0');
}


// L
bool isLetter(char c) {
    return 'A' <= c && c <= 'Z';
}
// N
bool isNumber(char c) {
    return '0' <= c && c <= '9';
}
int toNumber(char c) {
    if (isNumber(c)) {
        return c - '0';
    }
    if (isLetter(c)) {
        return c - 'A' + 1;
    }
    std::cout << "Error: toNumber(char): " << c << std::endl;
    return 0;
}
