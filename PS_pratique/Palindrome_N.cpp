#include <iostream>
#include <string>  // Nécessaire pour to_string
using namespace std;

class Solution {
public:
    bool isPalindrome(int entier) {
        string cast = to_string(entier);
        
        // Compare la chaîne avec sa version inversée
        if (cast == string(cast.rbegin(), cast.rend())) {
            return true;   // C'est un palindrome
        } else {
            return false;  // Ce n'est pas un palindrome
        }
    }
};

int main() {
    Solution solution;
    int entier;
    
    cout << "Entrez un entier" << endl;
    cin >> entier;
    
    if (solution.isPalindrome(entier)) {
        cout << "C'est un palindrome!" << endl;
    } else {
        cout << "Ce n'est pas un palindrome!" << endl;
    }
    
    return 0;
}