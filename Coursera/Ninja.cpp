#include <iostream>
#include <locale>  // Ajout nécessaire pour setlocale
using namespace std;

class Ninja {
public:        // Accessible partout
    void sePresenter() {
        cout << "Je suis " << nom << " du village de Konoha" << endl;
    }
    
protected:     // Accessible aux classes filles uniquement
    string nom;
    int chakra;
    string techniqueFamiliale;  // Secret de famille
    
private:       // Accessible seulement dans cette classe
    string journalIntime;       // Secret personnel
    int missionsSecretes;
    
public:
    Ninja(string n, int c) : nom(n), chakra(c) {
        journalIntime = "Mes pensées secrètes...";
        missionsSecretes = 0;
    }
};

class Uchiha : public Ninja {
public:
    Uchiha(string n, int c) : Ninja(n, c) {
        // Je peux accéder aux membres protected :
        techniqueFamiliale = "Katon : Boule de Feu";
        techniqueFamiliale = "Mangekyou sharingan : ";
        techniqueFamiliale="Amaterasu";
        cout << nom << " connaît " << techniqueFamiliale << endl;
        
        // ERREUR ! Je ne peux PAS accéder aux membres private :
        // journalIntime = "Nouveau journal";  // INTERDIT !
    }
    
    void utiliserSecretFamilial() {
        cout << nom << " utilise : " << techniqueFamiliale << endl;
        // Ceci fonctionne car techniqueFamiliale est protected
    }
};

class Uzumaki : public Ninja {  
    // Uzumaki hérite de Ninja et a accès aux mêmes membres publics et protecteds 
    public:
        Uzumaki(string n, int c) : Ninja(n, c) {
            // Je peux accéder aux membres protected :
            techniqueFamiliale = "Razengan, Boule de lune";
          cout << nom << " connaît " << techniqueFamiliale << endl;
}
void utiliserSecretSage() {
        cout << nom << " utilise : " << techniqueFamiliale << endl;
        // Ceci fonctionne car techniqueFamiliale est protected
    }
};
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