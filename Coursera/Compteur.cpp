#include <iostream>  // Inclusion de la bibliothèque iostream pour les entrées/sorties
using namespace std; // Utilisation de l'espace de noms standard pour éviter de préfixer cout et cin par std::

class Compteur {     // Définition d'une classe nommée Compteur
public:
    int val;        // Déclaration d'un attribut public de type int nommé val
    
    // Constructeur de la classe Compteur qui initialise l'attribut val avec la valeur passée en paramètre
    Compteur(int v) { 
        val = v; 
    }
    
    // Méthode pour incrémenter la valeur de l'attribut val
    void incrementer() { 
        val++; 
    }
    
    // Méthode pour afficher la valeur de l'attribut val
    void afficher() { 
        cout << val; 
    }
};

// Fonction qui prend un objet Compteur par valeur et incrémente sa valeur
void modifier1(Compteur c) {
    c.incrementer(); // Incrémentation de la valeur de l'objet Compteur passé par valeur
                       // Cette modification n'affecte pas l'objet original dans la fonction main
}

// Fonction qui prend un pointeur vers un objet Compteur et incrémente sa valeur
void modifier2(Compteur* c) {
    c->incrementer(); // Incrémentation de la valeur de l'objet Compteur pointé par c
                      // Cette modification affecte l'objet original dans la fonction main
}

int main() {         // Point d'entrée du programme
    Compteur comp(5); // Création d'un objet Compteur avec une valeur initiale de 5
    
    // Appel de la fonction modifier1 avec l'objet comp
    // Cette fonction ne modifie pas la valeur de comp dans main car elle reçoit une copie de comp
    modifier1(comp);
    
    // Affichage de la valeur de comp après l'appel à modifier1
    // La valeur affichée est 5 car modifier1 a modifié une copie de comp
    comp.afficher();
    cout << endl;    // Saut de ligne pour une meilleure lisibilité de la sortie
    
    // Appel de la fonction modifier2 avec l'adresse de l'objet comp
    // Cette fonction modifie la valeur de comp dans main car elle reçoit un pointeur vers comp
    modifier2(&comp);
    
    // Affichage de la valeur de comp après l'appel à modifier2
    // La valeur affichée est 6 car modifier2 a modifié comp
    comp.afficher();
    cout << endl;    // Saut de ligne pour une meilleure lisibilité de la sortie
    
    return 0;        // Retour de 0 indiquant que le programme s'est terminé sans erreur
}
