# Mini-Projet : Générateur de mots de passe aléatoires

## Niveau : Intermédiaire

### Concepts clés
- Manipulation de chaînes de caractères
- Génération de nombres aléatoires
- Boucles et conditions
- Fonctions (optionnel)

### Description
Ce projet te permettra de créer un générateur de mots de passe aléatoires. L'utilisateur pourra spécifier la longueur du mot de passe et choisir quels types de caractères inclure (majuscules, minuscules, chiffres, caractères spéciaux).

### Compétences préalables
- Variables et types de données
- Conditions (if/else)
- Boucles (for/while)
- Base de la génération de nombres aléatoires

### Étapes à suivre (sans code complet)

1. **Initialisation et configuration de base**
   - Inclure les bibliothèques nécessaires (iostream, cstdlib, ctime, string)
   - Initialiser le générateur de nombres aléatoires avec srand(time(0))

2. **Demander les préférences à l'utilisateur**
   - Longueur du mot de passe (par exemple, entre 8 et 30 caractères)
   - Types de caractères à inclure :
     - Lettres majuscules (A-Z)
     - Lettres minuscules (a-z)
     - Chiffres (0-9)
     - Caractères spéciaux (!@#$%^&*()_+-=[]{}|;:,.<>?/)

3. **Préparer les ensembles de caractères**
   - Définir des chaînes contenant chaque type de caractères
   ```cpp
   string majuscules = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
   string minuscules = "abcdefghijklmnopqrstuvwxyz";
   string chiffres = "0123456789";
   string speciaux = "!@#$%^&*()_+-=[]{}|;:,.<>?/";
   ```

4. **Construire un ensemble de caractères disponibles**
   - Créer une chaîne vide
   - Y ajouter les types de caractères choisis par l'utilisateur
   ```cpp
   string caracteres_disponibles = "";
   // Ajouter selon les choix de l'utilisateur
   if (utiliser_majuscules) {
       caracteres_disponibles += majuscules;
   }
   // Faire de même pour les autres types
   ```

5. **Générer le mot de passe**
   - Créer une chaîne vide pour le mot de passe
   - Utiliser une boucle pour ajouter des caractères aléatoires
   ```cpp
   string mot_de_passe = "";
   // Dans une boucle, sélectionner des caractères aléatoires
   ```

6. **Afficher le mot de passe généré**
   - Présenter le résultat à l'utilisateur

### Conseils

1. Pour sélectionner un caractère aléatoire dans une chaîne:
   ```cpp
   int index_aleatoire = rand() % caracteres_disponibles.length();
   char caractere_aleatoire = caracteres_disponibles[index_aleatoire];
   ```

2. Vérifie que l'utilisateur a choisi au moins un type de caractères avant de générer le mot de passe.

3. Tu peux ajouter une fonctionnalité pour vérifier que le mot de passe généré contient au moins un caractère de chaque type sélectionné.

4. Pour tester ton générateur, essaie de créer plusieurs mots de passe de différentes longueurs et avec différentes combinaisons de types de caractères.

### Extensions possibles
- Ajouter une option pour éviter les caractères ambigus (comme 0 et O, 1 et l, etc.)
- Permettre à l'utilisateur de générer plusieurs mots de passe à la fois
- Ajouter une estimation de la force du mot de passe généré
- Créer une fonction pour copier le mot de passe dans le presse-papier (plus avancé)

