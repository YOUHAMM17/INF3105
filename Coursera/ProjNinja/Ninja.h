#ifndef NINJA_H
#define NINJA_H

#include <iostream>
#include <string>
using namespace std;

class Ninja {
public:        // Accessible partout
    void sePresenter();
    
    // Constructeur
    Ninja(string n, int c);
    
protected:     // Accessible aux classes filles uniquement
    string nom;
    int chakra;
    string techniqueFamiliale;  // Secret de famille
    
private:       // Accessible seulement dans cette classe
    string journalIntime;       // Secret personnel
    int missionsSecretes;
};

#endif // NINJA_H