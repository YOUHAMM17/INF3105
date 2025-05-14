#include <iostream>
using namespace std;

int main() {
    int row;
    // Première partie: triangle croissant (1 à 5 symboles #)
    for ( row = 1; row <= 5; row++) {
        for (int hashNum = 1; hashNum <= row; hashNum++) {
            cout << "#";
        }
        cout << "\n";
    }
    
    // Deuxième partie: triangle décroissant (4 à 1 symboles #)
    for ( row = 4; row >= 1; row--) {
        for (int hashNum = 1; hashNum <= row; hashNum++) {
            cout << "#";
        }
        cout << "\n";
    }
    for ( row = 1; row <= 6; row++) {
         for (int hashNum = 0; hashNum <= row; hashNum++) {
            cout << "#";
        } 
        cout << "\n";
    }
    
    return 0;
}