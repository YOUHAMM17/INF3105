#include <iostream>  // Pour inclure la bibliothèque d'entrée/sortie
#include <time.h>    // Pour inclure la bibliothèque de gestion du temps
using namespace std; // Pour éviter d'écrire std:: devant cin, cout et endl

// Début de la fonction principale du programme
int main() {
   // Message de bienvenue pour l'utilisateur
   cout << "Bienvenue dans l'application de génération de mot de passe!" << endl;
   // Initialise le générateur de nombres aléatoires avec le temps actuel
   srand(static_cast<unsigned int>(time(0)));
   // Déclaration de la variable pour la longueur du mot de passe choisi par l'utilisateur
   int length;
   // Déclaration de la variable pour stocker le mot de passe généré
   string mot_de_passe = "";
   // Déclaration des chaînes de caractères contenant les majuscules, minuscules, chiffres et caractères spéciaux
   string majuscules = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
   string minuscules = "abcdefghijklmnopqrstuvwxyz";
   string chiffres = "0123456789";
   string char_speciaux = "!@#$%^&*()_+-=[]{}|;:,.<>?/";
   // Déclaration d'une chaîne de caractères qui contiendra tous les caractères disponibles pour la génération du mot de passe
   string caracteres_disponibles;
   // Déclaration de variables booléennes pour vérifier si l'utilisateur veut inclure des majuscules, minuscules, chiffres ou caractères spéciaux
   bool utiliser_majuscules;
   bool utiliser_miniscules;
   bool utiliser_chiffres;
   bool utiliser_char_speciaux;

   // Demande à l'utilisateur de choisir la longueur du mot de passe
   cout << "Veuillez entrer la longueur du mot de passe souhaite!" << endl;
   cin >> length; // Lecture de la longueur entrée par l'utilisateur
   // Affichage de la longueur choisie par l'utilisateur
   cout << "Vous avez choisi une longueur de " << length << " caracteres" << endl;

   // Demande à l'utilisateur s'il veut inclure des majuscules
   cout << "Est-ce que vous voulez inclure des caracteres MAJ? Si oui, tapez 1 sinon 0" << endl;
   cin >> utiliser_majuscules; // Lecture de la réponse de l'utilisateur
   // Si l'utilisateur veut inclure des majuscules, on les ajoute à la chaîne de caractères disponibles
   if (utiliser_majuscules) {
       caracteres_disponibles += majuscules;
   }

   // Demande à l'utilisateur s'il veut inclure des minuscules
   cout << "Est-ce que vous voulez inclure des caracteres min? Si oui, tapez 1 sinon 0" << endl;
   cin >> utiliser_miniscules; // Lecture de la réponse de l'utilisateur
   // Si l'utilisateur veut inclure des minuscules, on les ajoute à la chaîne de caractères disponibles
   if (utiliser_miniscules) {
       caracteres_disponibles += minuscules;
   }

   // Demande à l'utilisateur s'il veut inclure des chiffres
   cout << "Est-ce que vous voulez inclure des chiffres? Si oui, tapez 1 sinon 0" << endl;
   cin >> utiliser_chiffres; // Lecture de la réponse de l'utilisateur
   // Si l'utilisateur veut inclure des chiffres, on les ajoute à la chaîne de caractères disponibles
   if (utiliser_chiffres) {
       caracteres_disponibles += chiffres;
   }

   // Demande à l'utilisateur s'il veut inclure des caractères spéciaux
   cout << "Est-ce que vous voulez inclure des caracteres speciaux? Si oui, tapez 1 sinon 0" << endl;
   cin >> utiliser_char_speciaux; // Lecture de la réponse de l'utilisateur
   // Si l'utilisateur veut inclure des caractères spéciaux, on les ajoute à la chaîne de caractères disponibles
   if (utiliser_char_speciaux) {
       caracteres_disponibles += char_speciaux;
   }

   // Vérifie si aucuns caractères n'ont été sélectionnés
   if (caracteres_disponibles.empty()) {
       // Affiche un message informatif pour l'utilisateur
       cout << "Aucun caractere selectionne, le mot de passe sera vide." << endl;
       return 1; // Termine le programme avec un code d'erreur
   }


   // Boucle pour générer chaque caractère du mot de passe
   for (int i = 0; i < length; i++) {
       // Génère un index aléatoire dans la chaîne de caractères disponibles
       int index = rand() % caracteres_disponibles.length();
       // Ajoute le caractère correspondant à l'index choisi au mot de passe généré
       mot_de_passe += caracteres_disponibles[index];
   }

   // Affiche le mot de passe généré
   cout << "Voici votre mot de passe: " << mot_de_passe << endl;

   return 0;  // Fin du programme sans erreur
}
