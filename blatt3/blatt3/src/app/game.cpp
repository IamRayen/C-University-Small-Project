#include "game.h"

// TODO Aufgabe 7:
//  Bringe die `include`- und `using`-Anweisungen in eine sinnvolle Ordnung.
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <vector>
using std::vector;

#include "Coordinates.h"
using Sea::Coordinates;

#include "PlayerSea.h"
using GameObjects::PlayerSea;

#include "Constants.h"
using GameObjects::Constants;

#include "init.h"


// TODO Aufgabe 7:
//  Zerlege die Funktion `gameLoop(..)` in sinnvolle, kürzere Teilfunktionen.
void gameLoop(vector<PlayerSea> & playerSeas)
{
    cout << endl << "Los geht's!" << endl;
    for (unsigned int round = 0;; ++round) {
        PlayerSea & currentPlayerSea = playerSeas[round % 2];
        PlayerSea & otherPlayerSea = playerSeas[(round + 1) % 2];

        gameTurn(currentPlayerSea,otherPlayerSea);

        if(gameFinishCheck(currentPlayerSea,otherPlayerSea)){
            break;
        }
    }
}

void gameTurn (PlayerSea & currentPlayerSea, PlayerSea & otherPlayerSea){
    cout << GameObjects::PlayerSea::printSeaArea() << endl;
    cout << "THis is my sea" << endl;
    currentPlayerSea.printSea();

    Coordinates targetCoordinates = inputMissileTargetCoordinates(currentPlayerSea);
    bool hit = currentPlayerSea.sendMissileTo(otherPlayerSea, targetCoordinates);
    if (hit) {
        cout << "Treffer!" << endl;
    }
    else {
        cout << "Daneben!" << endl;
    }
}

bool gameFinishCheck (PlayerSea & currentPlayerSea, PlayerSea & otherPlayerSea){
    bool gameFinished = false;
    if (otherPlayerSea.allShipsDestroyed()) {
        cout << "Das letzte Schiff von " << otherPlayerSea.getPlayerName() << " ist versenkt. "
             << currentPlayerSea.getPlayerName() << " hat gewonnen." << endl;
        gameFinished = true;
    }
    return gameFinished;
}

Coordinates inputMissileTargetCoordinates(PlayerSea const & currentPlayerSea)
{
    while (true) {
        cout << endl << currentPlayerSea.getPlayerName() << " zielt auf" << endl;
        Coordinates targetCoordinates = inputCoordinates();

        if (currentPlayerSea.missileAlreadySentTo(targetCoordinates)) {
            cout << "Diese Koordinaten hast du schon probiert." << endl;
            continue;
        }
        return targetCoordinates;
    }
}
