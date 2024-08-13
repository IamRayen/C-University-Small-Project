# TODO Aufgabe 1:
#  Fügt dem Projekt die Anwendung `Battleship` hinzu, mit den Dateien im Verzeichnis src/app/ und der Bibliothek `GameObjects`.
#
# ???
#
add_executable(Battleship main.cpp init.cpp init.h game.cpp game.h test.cpp test.h)

target_link_libraries(Battleship GameObjects)
