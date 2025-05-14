/*
    INF3105 - Structures de données et algorithmes
    UQAM | Faculté des sciences | Département d'informatique
    Professeur: Florent Avellaneda 
    Auteure: SIDAHMED SEBIHI (SEBS27048802)

*/

#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <tuple>
#include <string>
#include <fstream>
#include <cstdlib>
#include <climits>
#include <algorithm>

class Univers {
    int N;
    int C;
    std::vector<std::vector<int> > grille;

    struct Etat {
        int x, y, couleur, cost, heurestique;
        Etat(int x, int y, int couleur, int cost, int heurestique) : x(x), y(y), couleur(couleur), cost(cost), heurestique(heurestique){}
        bool operator<(const Etat& autre) const {return heurestique > autre.heurestique;}
    };

public:
    Univers() : N(0), C(0) {}

    friend std::istream& operator>>(std::istream& is, Univers& univers) {
        is >> univers.N >> univers.C;
        univers.grille.resize(univers.N, std::vector<int>(univers.N));
        if (univers.N <= 0 || univers.C <= 0) {
            throw std::invalid_argument("Dimensions ou nombre de couleurs invalides.");
        }
        for (int y = 0; y < univers.N; ++y)
            for (int x = 0; x < univers.N; ++x){
                is >> univers.grille[y][x];
            }  
        return is;
    }
   
int heurestique(int nx, int ny, int x_destination, int y_destination){
    return (std::abs(nx - x_destination) + std::abs(ny - y_destination)); 
}

void plusCourtChemin(int x_depart, int y_depart, int couleur_depart,int x_destination, int y_destination) {

    if (x_depart < 0 || x_depart >= N || y_depart < 0 || y_depart >= N ||
            x_destination < 0 || x_destination >= N ||y_destination < 0 || y_destination >= N) {
        std::cerr << "Erreur : coordonnées hors limites." << std::endl;
        return ;
    }

    const std::vector<std::pair<int, int>> directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    const std::vector<char> actions = {'d', 'b', 'g', 'h'};

    std::vector<std::vector<std::vector<std::pair<int, char>>>> data(
        N, std::vector<std::vector<std::pair<int, char>>>(N, std::vector<std::pair<int, char>>(C, {INT_MAX, '-'})));
    std::priority_queue<Etat> pq;


    data[y_depart][x_depart][couleur_depart] = {0, '-'};
    pq.emplace(Etat(x_depart, y_depart, couleur_depart, 0, heurestique(x_depart,y_depart,x_destination,y_destination)+0));
    
    while (!pq.empty()) {
        int x =pq.top().x;
        int y =pq.top().y;
        int couleur =pq.top().couleur;
        int cost =pq.top().cost;
        pq.pop();

        if (x == x_destination && y == y_destination) {
            construire_chemin(x_depart, y_depart, couleur_depart, x_destination, y_destination, data, cost);
            return;
        }

        int new_couleur = grille[y][x];
        int new_cost = cost + 10;
        // changement de couleur
        if ((new_couleur != couleur) && (new_cost < data[y][x][new_couleur].first)) {
            data[y][x][new_couleur] = {new_cost, 'c'};
            pq.emplace(Etat(x, y, new_couleur, new_cost, heurestique(x,y,x_destination,y_destination)+new_cost));    
        }
        
        for (size_t i = 0; i < directions.size(); ++i) {
            int nx = x + directions[i].first;
            int ny = y + directions[i].second;
            
            if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
                int couleur_voisin = grille[ny][nx];
                int new_cost = cost + 1;
                // sans changement de couleur
                if ((couleur_voisin != couleur) && (new_cost < data[ny][nx][couleur].first)) {
                    data[ny][nx][couleur] = {new_cost, actions[i]};
                    pq.emplace(Etat(nx, ny, couleur, new_cost,heurestique(nx,ny,x_destination,y_destination)+new_cost )); 
                }   
            }
        }
    }
    std::cerr << "Erreur : Aucun chemin trouvé entre les points donnés." << std::endl;
}
 
void construire_chemin(int x_depart, int y_depart, int couleur_depart, int x_destination, int y_destination,
                       const std::vector<std::vector<std::vector<std::pair<int, char>>>> &data, int &cost) {
    std::string chemin = "";
    int x = x_destination, y = y_destination;

    // Chercher la meilleure couleur à la destination
    int best_couleur = 0;
    int min_cost = INT_MAX;
    for (int c = 0; c < C; ++c) {
        if (data[y][x][c].first < min_cost) {
            min_cost = data[y][x][c].first;
            best_couleur = c;
        }
    }
    int couleur = best_couleur;

    while (x != x_depart || y != y_depart) {
        char action = data[y][x][couleur].second;
        if (action == '-') {
            std::cerr << "Erreur : chemin non valide." << std::endl;
            return;
        }
        chemin = action + std::string(" ") + chemin;

        switch (action) {
            case 'd': x--; break; // Revenir à gauche
            case 'b': y--; break; // Revenir en haut
            case 'g': x++; break; // Revenir à droite
            case 'h': y++; break; // Revenir en bas
            case 'c':
                for (int c = 0; c < C; ++c) {
                    if (c != couleur && data[y][x][c].first + 10 == data[y][x][couleur].first) {
                        couleur = c;
                        break;
                    }
                }
            break;
        }
    }
    if (couleur != couleur_depart) {
        chemin = "c " + chemin;
    }
    std::cout << chemin << cost << std::endl;
}

};

int main(int argc, char const* argv[]) {
    if (argc != 7) {
        std::cerr << "Utilisation : " << argv[0] << " univers.txt x_depart y_depart couleur_depart x_destination y_destination" << std::endl;
        return -1;
    }

    std::ifstream entree(argv[1]);
    if (!entree) {
        std::cerr << "Erreur : impossible d'ouvrir le fichier " << argv[1] << std::endl;
        return -1;
    }

    Univers univers;
    entree >> univers;

    unsigned int x_depart = std::atoi(argv[2]);
    unsigned int y_depart = std::atoi(argv[3]);
    unsigned int couleur_depart = std::atoi(argv[4]);
    unsigned int x_destination = std::atoi(argv[5]);
    unsigned int y_destination = std::atoi(argv[6]);
    
    univers.plusCourtChemin(x_depart, y_depart, couleur_depart, x_destination, y_destination);

    return 0;
}
