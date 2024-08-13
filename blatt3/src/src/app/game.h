#ifndef BLATT3_GAME_H
#define BLATT3_GAME_H


#include <vector>

#include "Coordinates.h"

#include "PlayerSea.h"
using GameObjects::PlayerSea;


void gameLoop(std::vector<GameObjects::PlayerSea> & playerSeas);
void gameTurn (PlayerSea & currentPlayerSea, PlayerSea & otherPlayerSea);
bool gameFinishCheck (PlayerSea & currentPlayerSea, PlayerSea & otherPlayerSea);


Sea::Coordinates inputMissileTargetCoordinates(GameObjects::PlayerSea const & currentPlayerSea);


#endif //BLATT3_GAME_H
