# TODO Aufgabe 1:
#  Fügt dem Projekt die Bibliothek `GameObjects` hinzu, mit den Dateien im Verzeichnis src/libGameObjects/ und der Bibliothek `Sea`.
#
# ???
#
add_library(GameObjects Missile.cpp PlayerSea.cpp Ship.cpp Missile.h PlayerSea.h Ship.h)

target_include_directories(GameObjects PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(GameObjects Sea)
