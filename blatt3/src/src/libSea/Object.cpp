#include "Object.h"

namespace Sea {

    Object::Object(Coordinates const & newCoordinates, unsigned int newSize, Sea::Orientation newOrientation)
    : Coordinates(newCoordinates), size(newSize), orientation(newOrientation)
    {
    }

    bool Object::atCoordinates(Coordinates const & coordinates) const
    {
        // TODO Aufgabe 2:
        //  Nutzt die Funktionalität von `Coordinates`, um zu bestimmen, ob ein Teil dieses Objekts auf den übergebenen Koordinaten (`coordinates`) liegt.
        int x = this->getX();
        int y = this->getY();

        if(orientation == Orientation::Y){
            for(unsigned int i=0; i < size ; ++i){
                if(coordinates.samePositionAs(x,y + i)){
                    return true;
                };
            }
        }else if(orientation == Orientation::X){
            for(unsigned int i=0; i < size ; ++i){
                if(coordinates.samePositionAs(x + i,y)){
                    return true;
                };
            }
        }
        return false;
    }

    bool Object::intersectsWith(Object const & otherObject) const {
        // TODO Aufgabe 2:
        //  Nutzt die Funktion `atCoordinates(..)`, um zu bestimmen, ob sich dieses und das übergebene Objekt (`otherObject`) überschneiden.
        for(unsigned int i = 0; i < otherObject.size; ++i){
            Coordinates otherCoord = (otherObject.orientation == Orientation::X) ?
                    Coordinates(otherObject.getX()+i,otherObject.getY()):
                    Coordinates(otherObject.getX(),otherObject.getY()+i);
            if (this->atCoordinates(otherCoord)){
                return true;
            }
        }
        return false;
    }
}
