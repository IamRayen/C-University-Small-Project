cmake_minimum_required(VERSION 3.17)
project(blatt3)

set(CMAKE_CXX_STANDARD 17)

if(MSVC)
    add_compile_options(/W4 /EHs)
else()
    add_compile_options(-Wall -Wextra -pedantic)
endif()

# TODO Aufgabe 1:
#  Vervollständigt diese und die weiteren CMakeLists-Dateien, sodass eine sinnvolle Projektstruktur entsteht.
#  Entfernt dazu die folgenden Befehle und startet die neue Struktur damit, das Unterverzeichnis `src` hinzuzufügen.
#add_executable(Battleship
#                src/app/main.cpp src/app/init.cpp src/app/init.h src/app/game.cpp src/app/game.h src/app/test.cpp src/app/test.h
#                src/libGameObjects/Constants.h src/libGameObjects/PlayerSea.cpp src/libGameObjects/PlayerSea.h src/libGameObjects/Ship.cpp src/libGameObjects/Ship.h src/libGameObjects/Missile.cpp src/libGameObjects/Missile.h
#                src/libSea/Coordinates.cpp src/libSea/Coordinates.h src/libSea/Object.cpp src/libSea/Object.h)

add_subdirectory(src)
#
# ???
#
