#include <iostream>
using namespace std;

//
/* int recursive(int x){
		int count=x;
	 for (size_t i = 0; i < count; i++)
  {
    cout << "x = " << x << endl;
    recursive(x-1);
		
		
	};
	 return x;
} */


int recursive(int x) {
    if (x <= 0) {  // Condition d'arrêt claire
        return x;
    }
    
    cout << "x = " << x << endl;
    return recursive(x - 1);  // Un seul appel récursif
}

int main() {
    
    cout << "matrix..!\n";
    int myMatrix[3][3] = {{1,2,3},    // Ligne 0
                          {4,5,6},    // Ligne 1
                          {7,8,9}};   // Ligne 2
    
    // Accès à un élément spécifique de la matrice
    // myMatrix[ligne][colonne]
    int middle = myMatrix[2][2];  // Élément à la ligne 1, colonne 1 (valeur = 5)
    middle=10;
    // Affichage ligne
    cout << "Ligne 0: " << myMatrix[2][2]  << endl;
    //recursive(3);
    //int a = 0111;
   // a>>=1;
    /* double b = 3.14;
    auto c = 2.5f;
    auto d = "Hello World";
    auto e = 'A';
    auto f = 5; */
    
   //  cout << "a = " << a << endl;
    //cout << "b = " << b << endl;
  
     return 0;
}