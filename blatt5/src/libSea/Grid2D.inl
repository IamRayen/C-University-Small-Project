
// Siehe Hinweis in 'game.inl'

#include <exception>
#include "Grid2D.h"



// TODO Aufgabe 3:
//  Implementiert den Konstruktor von Grid2D.
//  Stellt mithilfe von Exceptions sicher, dass kein Grid2D mit einer ungültigen Größe (< 1x1) erstellt werden kann.
//  Tipp: Zur Initialisierung stellt `std::vector` einen entsprechenden Konstruktor zur Verfügung: `std::vector<ElementTyp>(Anzahl, initElement)`
//        Dieser wurde auch schon für `gridOwnSea` in 'PlayerSea.h' verwendet.

class Grid2DInvalidSizeException : public std::exception {
private:
const char * what() const noexcept override { return "sizeX and sizeY must both be > 0"; }
};

template<class T>
Sea::Grid2D<T>::Grid2D(unsigned int sizeX, unsigned int sizeY, T const & initElement)
        : grid(sizeY, std::vector<T>(sizeX, initElement))
{
    if (sizeX == 0 || sizeY == 0) {
        throw Grid2DInvalidSizeException();
    }
}



// TODO Aufgabe 3:
//  Implementiert `sizeX()` und `sizeY()`.
//  Erinnerung: die Größe in X-Richtung entspricht dabei der Anzahl der Elemente (vom Typ `T`) in den "inneren" Vektoren.
//                           Y-Richtung ist die Größe des "außeren" Vektors `grid`.
template<class T>
unsigned int Sea::Grid2D<T>::sizeX() const{
    return static_cast<unsigned int>(grid[0].size());
}

template<class T>
unsigned int Sea::Grid2D<T>::sizeY() const{
    return static_cast<unsigned int>(grid.size());
}
//static_cast: Used for safe and explicit type conversions in C++.
//In the Code: Converts size_t (returned by vector::size()) to
// unsigned int to match the function's return type.


// TODO Aufgabe 3:
//  Implementiert die 4 Operator-Überladungen.
//  Stellt sicher, dass Exceptions geworfen werden, wenn ungültige Koordinaten übergeben wurden.

template<class T>
T const & Sea::Grid2D<T>::operator[](Sea::Coordinates const & coords) const
{
    return grid.at(coords.getY()).at(coords.getX());
}

template<class T>
T & Sea::Grid2D<T>::operator[](Sea::Coordinates const & coords)
{
    return grid.at(coords.getY()).at(coords.getX());
}

template<class T>
T const & Sea::Grid2D<T>::operator()(unsigned int x, unsigned int y) const
{
    return grid.at(y).at(x);
}

template<class T>
T & Sea::Grid2D<T>::operator()(unsigned int x, unsigned int y)
{
    return grid.at(y).at(x);
}
//.at() is a member function provided by C++ Standard Library container classes
// like std::vector, std::array, std::map, etc.
// It is used to access elements in these containers at a specific index or key.
// Unlike the subscript operator ([]), .at() performs bounds checking,
// meaning it ensures that the index or key is within the valid range of the container.
// If the index is out of bounds, .at() throws an exception, specifically std::out_of_range.