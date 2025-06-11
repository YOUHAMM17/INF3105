#ifndef UCHIHA_H
#define UCHIHA_H

#include "Ninja.h"

class Uchiha : public Ninja {
public:
    Uchiha(string n, int c);
    void utiliserSecretFamilial();
};

#endif // UCHIHA_H