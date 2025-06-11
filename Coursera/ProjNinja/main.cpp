#include <iostream>
#include <locale>  // Ajout nécessaire pour setlocale
#include "Ninja.h"
#include "Uchiha.h"
#include "Uzumaki.h"
using namespace std;

int main() {
    // SOLUTION : Configure l'affichage des caractères accentués
    setlocale(LC_ALL, "");
    
    Uchiha sasuke("Sasuke", 100);
    Uchiha itachi("Itachi", 80);
    Uzumaki naruto("Naruto", 1200);      
    
    // Public : accessible partout
    // sasuke.sePresenter();  // OK
    itachi.sePresenter();  // OK
    itachi.utiliserSecretFamilial();  // OK
    naruto.sePresenter();  // OK
    naruto.utiliserSecretSage();  // OK
    
    // Protected : NOT accessible depuis main()
    // cout << sasuke.nom;  // ERREUR !
    
    // Private : NOT accessible nulle part sauf dans Ninja
    // cout << sasuke.journalIntime;  // ERREUR !
    
    return 0;
}