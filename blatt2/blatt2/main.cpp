#include <iostream>

// TODO Aufgabe 3:
//  Inkludiert die Funktionen aus den `euroCheck.h/cpp`-Dateien.
/*
 ???
 */

using std::string;

// TODO Aufgabe 1:
//  Definiert die Funktion `inputNextSerialNumber()` so, dass sie eine Seriennummer als `string` auf der Konsole einliest und diese zurückgibt.
/*
 ???
 */

// TODO Aufgabe 3:
//  Implementiert die Funktion `checkSerialNumberAndPrintResult(serialNumber)`.
//  Sie soll mithilfe der Funktion `getEuroSerialNumberVersion(serialNumber)` ermitteln, um welche Version einer Euro-Banknote es sich handelt, und die entsprechende Jahreszahl in der Konsole ausgeben.
//  Anschliessend soll in einer Fallunterscheidung (switch) anhand der Jahreszahl die entsprechende Funktion `checkEuroSerialNumber2013/2002(serialNumber)` aufgerufen und das Ergebnis (Gueltig/Ungueltig) auf der Konsole ausgeben werden.
void checkSerialNumberAndPrintResult(string & serialNumber) {
    /*
     ???
     */
}

int main() {
    string serialNumber;
    // TODO Aufgabe 4:
    //  Nutzt eine Kontrollstruktur, sodass nacheinander beliebig viele Seriennummern geprüft werden können.
    /*
     ???
     */

        // TODO Aufgabe 1:
        //  Ruft `inputNextSerialNumber()` auf, um eine Seriennummer einzugeben.
        /*
         ???
         */

        // TODO Aufgabe 4:
        //  Das Programm soll beendet werden, wenn statt einer Seriennummer "fertig" eingegeben wurde.
        /*
         ???
         */

        checkSerialNumberAndPrintResult(serialNumber);
    /*
     ???
     */

    return 0;
}
