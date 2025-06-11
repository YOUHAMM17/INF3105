#include "Ninja.h"

void Ninja::sePresenter() {
    cout << "Je suis " << nom << " du village de Konoha" << endl;
}

Ninja::Ninja(string n, int c) : nom(n), chakra(c) {
    journalIntime = "Mes pensées secrètes...";
    missionsSecretes = 0;
}