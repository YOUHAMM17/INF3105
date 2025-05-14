

#include <iostream>
using namespace std;

int main() {
    double tempCelsius;
    double tempFahrenheit;
    int option =0;
    double temperature=0;
    cout << "Bienvenue dans votre convertisseur de temperature!" << endl;
    cout << "veuillez choisir l'une des options suivante" << endl;
    cout << "Pour convertir apartir de Fahrenheit, entez 1 " << endl;
    cout << "Pour convertir apartir de Celsius, entez 2 " << endl;
    cin >>option ;
   cout << "Veuillez entrez la temperature " << endl;
   cin >>temperature ;
    
    if (option==1){
        tempCelsius = (temperature - 32) * 5/9;
    cout << "La temperature en Celsius est : " <<tempCelsius<< endl;
}
else if (option==2){
    tempFahrenheit = temperature * 9/5 + 32;
    cout << "La temperature en Fahrenheit est : " <<tempFahrenheit<< endl;
}
else{
    cout << "Erreur de saisie, veuillez ressayer! " << endl;
}
return 0;
}









