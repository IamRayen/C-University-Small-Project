#include <iostream>
#include "string"

// TODO Aufgabe 3:
//  Inkludiert die Funktionen aus den `euroCheck.h/cpp`-Dateien.

#include "euroCheck.h"


using std::string;
using std::cin;
using std::cout;
using std::endl;

// TODO Aufgabe 1:
//  Definiert die Funktion `inputNextSerialNumber()` so, dass sie eine Seriennummer als `string` auf der Konsole einliest und diese zurückgibt.

string inputNextSerialNumber(){
    string serialNumber;
    cout << "Input the Serial Number :";
    cin >> serialNumber;

    return serialNumber;
}

// TODO Aufgabe 3:
//  Implementiert die Funktion `checkSerialNumberAndPrintResult(serialNumber)`.
//  Sie soll mithilfe der Funktion `getEuroSerialNumberVersion(serialNumber)` ermitteln, um welche Version einer Euro-Banknote es sich handelt, und die entsprechende Jahreszahl in der Konsole ausgeben.
//  Anschliessend soll in einer Fallunterscheidung (switch) anhand der Jahreszahl die entsprechende Funktion `checkEuroSerialNumber2013/2002(serialNumber)` aufgerufen und das Ergebnis (Gueltig/Ungueltig) auf der Konsole ausgeben werden.
void checkSerialNumberAndPrintResult(string & serialNumber) {
    int version = getEuroSerialNumberVersion(serialNumber);
    cout <<version<<endl;
    switch(version){
        case 2002:
            if(checkEuroSerialNumber2002(serialNumber)){
                cout << "Gultig" << endl;
            }else{
                cout << "Ungultig" << endl;
            };
            break;
        case 2013:
            if(checkEuroSerialNumber2013(serialNumber)){
                cout << "Gultig" << endl;
            }else{
                cout << "Ungultig" << endl;
            };
            break;
    }
}

int main() {
    string serialNumber;
    // TODO Aufgabe 4:
    //  Nutzt eine Kontrollstruktur, sodass nacheinander beliebig viele Seriennummern geprüft werden können.
    while(true){
        // TODO Aufgabe 1:
        //  Ruft `inputNextSerialNumber()` auf, um eine Seriennummer einzugeben.
        serialNumber = inputNextSerialNumber();

        // TODO Aufgabe 4:
        //  Das Programm soll beendet werden, wenn statt einer Seriennummer "fertig" eingegeben wurde.
        if (serialNumber == "fertig") {
            cout << "Programm beendet." << endl;
            break;
        }

        checkSerialNumberAndPrintResult(serialNumber);
    }
    return 0;
}
