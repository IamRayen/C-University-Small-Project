#include "Missile.h"

// TODO Aufgabe 3:
//  Definiert die Funktionen der Klasse `Missile`.

namespace GameObjects{
    Missile::Missile(Sea::Coordinates const & coords): Sea::Coordinates(coords) {
    }
    void Missile::hitSomething(){
        hit = true;
    }

    bool Missile::hasHitSomething() const {
        return hit;
    };
}