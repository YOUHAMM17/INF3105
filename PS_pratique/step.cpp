#include <stdio.h>

// Déclaration de la fonction step_function
int step_function(int x) {
    if (x > 0) return 1;
    else if (x == 0) return 0;
    else return -1;
}


int main() {
    int num1 = 42;
    int result1 = step_function(num1);

    int num2 = 0;
    int result2 = step_function(num2);

    int num3 = -32768;
    int result3 = step_function(num3);

    printf("Num1: %d, Step: %d\n", num1, result1);
    printf("Num2: %d, Step: %d\n", num2, result2);
    printf("Num3: %d, Step: %d\n", num3, result3);

    return 0;
}
