#include <iostream>
#include "vector"
#include "string"

using namespace std;

int main() {
    cout << "Hello, World!" << endl;

    vector <string > team = { "Paddy", "Linda" }; // Vektor mit Startwerten
    int teamSize = team.size();
    cout << "Wir sind : " << team [0] << "..." << team [ teamSize - 1 ] << endl;
    team.emplace_back ("Steve"); // weiteren Wert zum Vektor hinzufügen
    team.emplace_back ("Flo");

    return 0;
}
