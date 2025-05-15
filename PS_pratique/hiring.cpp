#include <iostream>
using namespace std;

int main() {
    bool piston;
    bool permis;
    int age;

    cout << "Vous etes un candidat pour un poste de chauffeur de taxi" << endl;
    cout << "Verification du piston" << endl;
    cout << "Si vous etes pistoner, entrez 1, sinon 0" << endl;
    cin >> piston;

    if (piston) {
        cout << "Felicitations! vous etes admis!" << endl;
        return 0;  // Exit the program immediately after displaying the message
    }

    cout << "Veuillez entrer 1 si vous avez le permis, sinon 0 " << endl;
    cin >> permis;

    if (!permis) {
        cout << "Desole, vous n'etes pas admis!" << endl;
        return 0;  // Exit the program immediately after displaying the message
    }

    cout << "Veuillez entrer votre age " << endl;
    cin >> age;

    if (age >= 21) {
        cout << "Felicitations! admission conditionnelle!" << endl;
    } else {
        cout << "Desole, vous n'etes pas admis!" << endl;
    }


    return 0;  // Fin du programme
}
