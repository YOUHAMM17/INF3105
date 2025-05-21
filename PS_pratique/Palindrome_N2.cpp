#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool isPalindrome(int entier) {
        // Convertir l'entier en chaîne de caractères
        string nombre = to_string(entier);
        
        // Obtenir la longueur de la chaîne
        int longueur = nombre.length();
        
        // Parcourir la chaîne en comparant les caractères des deux extrémités
        for (int i = 0; i < longueur / 2; i++) {
            // Comparer le caractère à l'indice i avec celui à l'indice (longueur-1-i)
            if (nombre[i] != nombre[longueur - 1 - i]) {
                return false;  // Si différents, ce n'est pas un palindrome
            }
        }
        
        // Si toutes les comparaisons ont réussi, c'est un palindrome
        return true;
    }
};

int main() {
    Solution solution;
    int entier;
    
    cout << "Entrez un entier" << endl;
    cin >> entier;
    
    if (solution.isPalindrome(entier)) {
        cout << "C'est un palindrome!" << endl;
    } else {
        cout << "Ce n'est pas un palindrome!" << endl;
    }
    
    return 0;
}