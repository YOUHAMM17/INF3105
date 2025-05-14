#include <iostream>  // pour les entrées (cin) et sorties (cout)
using namespace std; // pour éviter d’écrire std:: devant cin et cout et endl
int addsub(int x,int y){
   
	cout<<"entrez deux numero"<<endl;
	cin>>x>>y;
	
	cout<<x<<"+"<<y<<" is "<<x+y<<"."<<endl;
	cout<<x<< "-" <<y<<" is "<<x-y<<endl;
    

   };

int main() {
   
   addsub(7,5);
    return 0;  // Fin du programme
}
