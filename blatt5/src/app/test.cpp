// TODO:
//  Entfernt die Kommentar-Zeichen (//) für Aufgaben, die erledigt sind und getestet werden sollen:


#define TEST_AUFGABE_1 // TODO Aufgabe 1
//#define TEST_AUFGABE_3 // TODO Aufgabe 3


#include "test.h"

#include <iostream>
using std::cout;
using std::endl;
#include <string>
using std::string;
#include <sstream>
using std::stringstream;
#include <algorithm>
using std::count;

#include "Coordinates.h"
using Sea::Coordinates;

#ifdef TEST_AUFGABE_3
#include "Grid2D.h"
using Sea::Grid2D;
#endif

#include "PlayerSea.h"
using GameObjects::PlayerSea;
#include "Constants.h"
using GameObjects::Constants;

#include "utils.h"
using Utils::n_endl;


bool testPassed()
{
    bool testResult =
            testOperator() &&
            testGrid2D();

    if (testResult) {
        cout << "Test OK." << n_endl(2);
        return true;
    }
    cout << "Test fehlgeschlagen." << n_endl(2);
    return false;
}

bool testOperator()
{
#ifdef TEST_AUFGABE_1
    stringstream stream;
    stream << PlayerSea("Testspieler");

    auto str = stream.str();
    return
        str.find("Testspieler") != string::npos &&
                (unsigned int)(count(str.begin(), str.end(), '~')) == (2 * Constants::seaSizeX * Constants::seaSizeY);
#else
    return true;
#endif
}

bool testGrid2D()
{
#ifdef TEST_AUFGABE_3
    Grid2D<int> grid1(2, 2, 123'456);
    Coordinates c1(0, 1);
    Coordinates c2(1, 0);

    grid1(1, 0) = 7;
    grid1[c1] = 8;
    grid1[{1, 1}] = 9;

    bool testInt =
            grid1(0, 0) == 123'456 &&
            grid1(0, 1) == grid1[c1] &&
            grid1[c2] == 7 &&
            grid1[{0, 1}] == 8;


    Grid2D<Coordinates> grid2(3, 3, Coordinates(123, 456));
    grid2(2, 2) = Coordinates(76, 54);
    bool testExceptions = false;
    try {
        grid2(3, 3) = Coordinates(32, 10);
    }
    catch (...) {
        testExceptions = true;
    }

    bool testCoordinates =
            grid2(1, 1).getX() == 123 &&
            grid2(2, 2).getY() == 54;


    return testInt && testExceptions && testCoordinates;
#else
    return true;
#endif
}
