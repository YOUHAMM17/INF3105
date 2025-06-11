#include "Uchiha.h"

Uchiha::Uchiha(string n, int c) : Ninja(n, c) {
    // Je peux accéder aux membres protected :
    techniqueFamiliale = "Katon : Boule de Feu";
    techniqueFamiliale = "Mangekyou sharingan : ";
    techniqueFamiliale = "Amaterasu";
    cout << nom << " connaît " << techniqueFamiliale << endl;
    
    // ERREUR ! Je ne peux PAS accéder aux membres private :
    // journalIntime = "Nouveau journal";  // INTERDIT !
}

void Uchiha::utiliserSecretFamilial() {
    cout << nom << " utilise : " << techniqueFamiliale << endl;
    // Ceci fonctionne car techniqueFamiliale est protected
}