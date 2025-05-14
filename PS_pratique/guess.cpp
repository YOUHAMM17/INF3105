#include <iostream>
#include <cstdlib>   // Pour la fonction rand()
#include <ctime>     // Pour la fonction time()
using namespace std;

int main() {
    
	
	// Initialise le générateur de nombres aléatoires
srand(time(0));  // Utilise l'heure actuelle comme graine

// Génère un nombre entre 1 et 100
int nb_mystere = rand() % 100 + 1;
//revele le nombre mystere pour verifier si le programme fonctionne
//cout<<nb_mystere<<endl;
//message de bienvenue et instructions
	cout << "Bienvenue dans le mini-jeux devinette!"<< endl;
	cout << "Vous devrais essayer de deviner le nombre mystere.. "<< endl;


//choix d'utilisateur
int nb_choisi;
cout << "Veuillez choisir un numero entre 1-100"<< endl;
cin>>nb_choisi;
	cout<<"Vous avez choisi le numero: "<<nb_choisi<<endl;
    bool trouve=nb_mystere==nb_choisi;
	//boucle pour verifier si le nombre choisi est correct
    	int c=1;
	while(!trouve){
	
	
	 
				if(nb_choisi>nb_mystere){
			cout<<"Votre numero est plus grand que le nombre mystere, veuillez deviner un numero plus bas!\n";
		}
		else{
			cout<<"Votre numero est plus petit que le nombre mystere, veuillez deviner un numero plus haut!\n";
		}
		cout << "Veuillez choisir un numero entre 1-100 a nouveau!"<< endl;
cin>>nb_choisi;
		trouve = nb_mystere == nb_choisi;
		//compte le nombre de tentative
        c++;
	}
cout<<"Bravo, vous avez reussi a deviner le nombre secret! "<<nb_mystere<<endl;
cout<<"Vous avez fait "<<c<<" tentatives"<<endl;
return 0;
}