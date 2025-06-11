#include <iostream>
using namespace std;

class Score {
public:
    int points;
    Score(int p) { points = p; }
    void ajouter(int x) { points += x; }
    void afficher() { cout << points; }
};

void methodeA(Score s) {        // Passage par valeur
    s.ajouter(10);
}

void methodeB(Score* s) {       // Passage par pointeur
    s->ajouter(20);
}

int main() {
    Score joueur(100);
    
    joueur.afficher();          // État initial
    methodeA(joueur);           // Passage par valeur
    joueur.afficher();          // Après méthodeA
    methodeB(&joueur);          // Passage par pointeur
    joueur.afficher();          // Après méthodeB
    
    return 0;
}