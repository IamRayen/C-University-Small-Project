#include <iostream>
#include "vector"
#include "string"

using namespace std;

int main() {
    cout << "Hello, World!" << endl;

    cout << "Wir sind : " << team [0] << "..." << team [ teamSize ] << endl ;
    vector <string > team = { "Paddy", "Linda" }; // Vektor mit Startwerten
    team . emplace_back ("Steve"); // weiteren Wert zum Vektor hinzufügen
    team . emplace_back ("Flo");
    int teamSize = team . size ();

    return 0;
}
