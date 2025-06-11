#include <iostream>
#include <cmath>
using namespace std;
class Cercle
{
private:
    double rayon;
    double centrex;
    double centrey;
    

public:
    double surface() const {
        return M_PI * pow(rayon, 2);
    };
    bool estinterieur(double x, double y){
        return (pow(x-centrex,2)+pow(y-centrey,2))<=pow(rayon,2);
    };
    double getRayon() const { return rayon; }
    double getCentrex() const { return centrex; }
    double getCentrey() const { return centrey; }
    void setRayon(double x) { rayon = x; }
    void setCentrex(double x) { centrex = x; }
    void setCentrey(double x) { centrey = x; }

};
int main()
{
    Cercle cercle;
    Cercle cercle2;
    cercle.setRayon(5.0);
    cercle.setCentrex(3.0);
    cercle.setCentrey(4.0);
   cout << "Surface : " << cercle.surface() << endl;
    cout << "Est-ce que le point (2,3) est dans le cercle ? " << cercle2.estinterieur(2,3) << endl;
    cout << "Est-ce que le point (6,4) est dans le cercle ? " << cercle2.estinterieur(6,4) << endl;
    
    return 0;
}