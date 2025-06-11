#ifndef UZUMAKI_H
#define UZUMAKI_H

#include "Ninja.h"

class Uzumaki : public Ninja {
public:
    Uzumaki(string n, int c);
    void utiliserSecretSage();
};

#endif // UZUMAKI_H