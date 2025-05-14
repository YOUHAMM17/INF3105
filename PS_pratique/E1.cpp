#include <iostream>
int absolute_value(int x) {
    // Pas besoin de demander la valeur ici, juste calculer la valeur absolue
    if (x < 0) {
        return -x;
    }
    else {
        return x;
    }
}

int main() {
    int x;
    std::cout << "enter une valeur: ";
    std::cin >> x;
    printf("The absolute value of %d is %d.\n", x, absolute_value(x));
}