#include "Uzumaki.h"

Uzumaki::Uzumaki(string n, int c) : Ninja(n, c) {
    // Je peux accéder aux membres protected :
    techniqueFamiliale = "Razengan, Boule de lune";
    cout << nom << " connaît " << techniqueFamiliale << endl;
}

void Uzumaki::utiliserSecretSage() {
    cout << nom << " utilise : " << techniqueFamiliale << endl;
    // Ceci fonctionne car techniqueFamiliale est protected
}