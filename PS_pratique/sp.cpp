#include <iostream>

int main() {    



int a = 10;
int *p = &a;
int &r = a;
int &s=r;
r = 20;
s=30;
*p = *p + 5;
std::cout << a;}