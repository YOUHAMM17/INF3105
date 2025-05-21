#include <iostream>
using namespace std;

// Fonction qui retourne le siècle d'une année
int centuryFromYear(int year) {
    // Si l'année est divisible par 100, le siècle est year / 100
    // Sinon, on ajoute 1
    int century = (year + 99) / 100;

    cout << year << " is in the " << century << "th century" << endl;
    return century;
}

int main() {
    int year;
    cout << "Enter a year: ";
    cin >> year;

    centuryFromYear(year);

    return 0;
}
