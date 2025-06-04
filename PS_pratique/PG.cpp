// Exemple d'une classe Rectangle complète
// Ce code illustre les concepts fondamentaux de la POO en C++
#include <iostream>
#include <locale>   // Pour la gestion des paramètres régionaux
#include <string>
#include <codecvt>  // Pour les conversions d'encodage (C++11)

// ========== DÉCLARATION DE LA CLASSE RECTANGLE ==========
class Rectangle {
private:
    // Attributs privés (variables membres)
    // Seules les méthodes de cette classe peuvent y accéder directement
    double hauteur;
    double largeur;

public:
    // Constructeur par défaut
    // Initialise automatiquement les attributs à des valeurs par défaut
    Rectangle() : hauteur(0.0), largeur(0.0) {}
    
    // Constructeur avec paramètres
    // Permet de créer un rectangle avec des dimensions spécifiques
    Rectangle(double h, double l) : hauteur(h), largeur(l) {}
    
    // Méthodes d'accès (getters) - permettent de lire les attributs privés
    double getHauteur() const { return hauteur; }
    double getLargeur() const { return largeur; }
    
    // Méthodes de modification (setters) - permettent de modifier les attributs privés
    void setHauteur(double h) { hauteur = h; }
    void setLargeur(double l) { largeur = l; }
    
    // Méthode de calcul de la surface
    // Le mot-clé 'const' indique que cette méthode ne modifie pas l'objet
    double surface() const
    {
        // Calcul de la surface : hauteur × largeur
        return hauteur * largeur;
    }
    
    // Méthode de calcul du périmètre
    double perimetre() const
    {
        // Calcul du périmètre : 2 × (hauteur + largeur)
        return 2 * (hauteur + largeur);
    }
    
    // Méthode d'affichage des informations du rectangle
    void afficher() const
    {
        std::cout << "Rectangle: " 
                  << hauteur << " x " << largeur 
                  << " (Surface: " << surface() << ")" << std::endl;
    }
};

// ========== IMPLÉMENTATION DE LA MÉTHODE SURFACE (ALTERNATIVE) ==========
// Cette syntaxe montre comment définir une méthode à l'extérieur de la classe
// (Non utilisée ici car déjà définie dans la classe, mais montrée pour illustration)
/*
double Rectangle::surface() const
{
    return hauteur * largeur;
}
*/

// ========== FONCTION PRINCIPALE POUR TESTER LA CLASSE ==========
int main()
{
    std::setlocale(LC_ALL, "fr_CA.UTF-8");
    // Création d'objets Rectangle de différentes façons
    
    // 1. Utilisation du constructeur par défaut
    Rectangle rect1;  // Rectangle de dimensions 0x0
    
    // 2. Utilisation du constructeur avec paramètres
    Rectangle rect2(5.0, 3.0);  // Rectangle de 5x3
    
    // 3. Modification des dimensions du premier rectangle
    rect1.setHauteur(4.0);
    rect1.setLargeur(2.5);
    
    // Affichage des informations des rectangles
    std::cout << "Premier rectangle:" << std::endl;
    rect1.afficher();
    
    std::cout << u8"Deuxième rectangle:" << std::endl;
    rect2.afficher();
    
    // Utilisation directe des méthodes de calcul
    std::cout << "Surface du rectangle 2: " << rect2.surface() << std::endl;
    std::cout << u8"Périmètre du rectangle 2: " << rect2.perimetre() << std::endl;
    
    return 0;
}