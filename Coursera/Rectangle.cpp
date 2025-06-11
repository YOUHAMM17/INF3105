#include <iostream>
using namespace std;
class Rectangle
{
private:
    double largeur;
    double longueur;

public:
    double surface() const
    {
        return largeur * longueur;
    }
    
    double getLongueur() const { return longueur; }
    double getLargeur() const { return largeur; }
    // Setter
    void setLargeur(double x) { largeur = x; }
    void setLongueur(double x) { longueur = x; }
};
int main()
{
    Rectangle rect;
    rect.setLargeur(1.5);
    rect.setLongueur(12.8);
    cout << "Surface : " << rect.surface() << endl;
    return 0;
}