#include <iostream>
#include <string>

// Classe representant un compte bancaire simple
class CompteBancaire {
private:
    // Attribut prive : seules les methodes de cette classe peuvent y acceder
    double solde;          
    std::string titulaire; 

public:
    // Constructeur : initialise le titulaire et le solde
    CompteBancaire(const std::string& nom, double montantInitial) {
        titulaire = nom;
        if (montantInitial < 0) {
            solde = 0.0; // Si montant initial negatif, on initialise a 0
        } else {
            solde = montantInitial;
        }
    }

    // Getter pour solde : methode publique qui retourne le solde actuel
    double getSolde() const {
        return solde;
    }

    // Setter pour solde : exemple de mutateur avec verification
    void setSolde(double nouveauSolde) {
        if (nouveauSolde >= 0) {
            solde = nouveauSolde;
        } else {
            std::cout << "Erreur : solde ne peut pas etre negatif." << std::endl;
        }
    }

    // Methode publique pour deposer de l'argent
    void deposer(double montant) {
        if (montant > 0) {
            solde += montant;
        } else {
            std::cout << "Montant de depot invalide." << std::endl;
        }
    }

    // Methode publique pour retirer de l'argent
    void retirer(double montant) {
        if (montant > 0 && montant <= solde) {
            solde -= montant;
        } else {
            std::cout << "Retrait impossible : montant invalide ou solde insuffisant." << std::endl;
        }
    }

    // Methode publique pour afficher les details du compte
    void afficherDetails() const {
        std::cout << "Titulaire : " << titulaire << ", Solde : " << solde << " EUR" << std::endl;
    }
};
/* CompteBancaire::CompteBancaire(const std::string& nom, double montantInitial) : titulaire(nom), solde(montantInitial) {
  std::cout << "Constructeur de CompteBancaire" << std::endl;
 */
//}

int fonctionTest() {
    CompteBancaire monCompte("Alice", 100.0);   
    std::cout << "Fonction de test" << std::endl;
    return 0;
}
int main() {
    fonctionTest();

    // On cree un compte avec un solde initial de 100 EUR
    CompteBancaire monCompte("Alice", 100.0);

    // Affichage initial
    monCompte.afficherDetails(); 
    // → Titulaire : Alice, Solde : 100 EUR

    // On tente de definir un solde negatif (via le setter)
    monCompte.setSolde(-50.0); 
    // → Erreur : solde ne peut pas etre negatif.
    std::cout << "Apres tentative de setter avec -50 : " << monCompte.getSolde() << " EUR" << std::endl;
    // → Offre : reste a 100 EUR

    // On depose 30 EUR
    monCompte.deposer(30.0);
    std::cout << "Apres depot de 30 : " << monCompte.getSolde() << " EUR" << std::endl;
    // → 130 EUR

    // On retire 50 EUR
    monCompte.retirer(50.0);
    std::cout << "Apres retrait de 50 : " << monCompte.getSolde() << " EUR" << std::endl;
    // → 80 EUR

    return 0;
}
