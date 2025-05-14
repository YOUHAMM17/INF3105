#include <iostream>
#include <memory>

using namespace std;

int main() {
   // Créer un titre pour notre démonstration
   cout << "\n=== DEMONSTRATION DES SMART POINTERS EN C++ ===\n\n";
   
   // 1. Création d'un shared_ptr
   cout << "1. CREATION D'UN SHARED_PTR\n";
   cout << "   shared_ptr<int> shared_int_1(new int(5));\n";
   shared_ptr<int> shared_int_1(new int(5));
   
   // Vérifier la valeur et le compteur de références
   cout << "   Valeur: " << *shared_int_1 << "\n";
   cout << "   Use count: " << shared_int_1.use_count() << "\n\n";
   /* 
   // 2. Création d'un deuxième shared_ptr pointant vers le même objet
   cout << "2. COPIE DU SHARED_PTR\n";
   cout << "   shared_ptr<int> shared_int_2 = shared_int_1;\n";
   shared_ptr<int> shared_int_2 = shared_int_1;
   
   cout << "   Use count de shared_int_1: " << shared_int_1.use_count() << "\n";
   cout << "   Use count de shared_int_2: " << shared_int_2.use_count() << "\n\n";
   
   // 3. Vérifier que les deux pointeurs pointent vers la même adresse
   cout << "3. VÉRIFICATION DE L'ADRESSE MÉMOIRE\n";
   cout << "   Adresse de shared_int_1: " << shared_int_1.get() << "\n";
   cout << "   Adresse de shared_int_2: " << shared_int_2.get() << "\n";
   cout << "   Pointent-ils vers la même adresse? " 
        << (shared_int_1.get() == shared_int_2.get() ? "OUI" : "NON") << "\n\n";
   
   // 4. Création d'un weak_ptr
   cout << "4. CREATION D'UN WEAK_PTR\n";
   cout << "   weak_ptr<int> weak_int = shared_int_1;\n";
   weak_ptr<int> weak_int = shared_int_1;
   
   cout << "   Use count après création du weak_ptr: " << weak_int.use_count() << "\n";
   cout << "   Le weak_ptr est-il expiré? " << (weak_int.expired() ? "OUI" : "NON") << "\n\n";
   
   // 5. Conversion du weak_ptr en shared_ptr
   cout << "5. CONVERSION WEAK_PTR → SHARED_PTR\n";
   cout << "   auto shared_int_3 = weak_int.lock();\n";
   auto shared_int_3 = weak_int.lock();
   
   cout << "   Use count après lock(): " << shared_int_3.use_count() << "\n";
   cout << "   La conversion a-t-elle réussi? " << (shared_int_3 ? "OUI" : "NON") << "\n\n";
   
   // 6. Libération des shared_ptr originaux
   cout << "6. LIBÉRATION DES SHARED_PTR\n";
   cout << "   shared_int_1.reset();\n";
   shared_int_1.reset();
   cout << "   Use count après reset() de shared_int_1: " << shared_int_3.use_count() << "\n";
   
   cout << "   shared_int_2.reset();\n";
   shared_int_2.reset();
   cout << "   Use count après reset() de shared_int_2: " << shared_int_3.use_count() << "\n\n";
   
   // 7. Vérification de l'unicité
   cout << "7. VÉRIFICATION DE L'UNICITÉ\n";
   cout << "   Use count de shared_int_3: " << shared_int_3.use_count() << "\n";
   cout << "   shared_int_3 est-il unique? " << (shared_int_3.unique() ? "OUI" : "NON") << "\n\n";
   
   // 8. Démonstration supplémentaire - expired() sur weak_ptr
   cout << "8. TEST DU WEAK_PTR APRÈS LIBÉRATION\n";
   shared_int_3.reset(); // Libère le dernier shared_ptr
   cout << "   shared_int_3.reset(); // Libère le dernier shared_ptr\n";
   cout << "   Le weak_ptr est-il expiré? " << (weak_int.expired() ? "OUI" : "NON") << "\n";
   cout << "   Use count du weak_ptr: " << weak_int.use_count() << "\n\n";
   
   // 9. Tentative de lock() sur un weak_ptr expiré
   cout << "9. TENTATIVE DE LOCK() SUR UN WEAK_PTR EXPIRÉ\n";
   auto failed_lock = weak_int.lock();
   cout << "   auto failed_lock = weak_int.lock();\n";
   cout << "   La conversion a-t-elle réussi? " << (failed_lock ? "OUI" : "NON") << "\n\n";
   
   // 10. Démonstration finale avec unique_ptr pour comparaison
   cout << "10. BONUS: COMPARAISON AVEC UNIQUE_PTR\n";
   cout << "   unique_ptr<int> unique_int(new int(100));\n";
   unique_ptr<int> unique_int(new int(100));
   cout << "   Valeur: " << *unique_int << "\n";
   cout << "   Les unique_ptr ne peuvent pas être copiés, seulement déplacés\n";
   
   // unique_ptr<int> unique_int_2 = unique_int; // ERREUR!
   unique_ptr<int> unique_int_2 = std::move(unique_int);
   cout << "   unique_ptr<int> unique_int_2 = std::move(unique_int);\n";
   cout << "   unique_int après move est-il vide? " << (!unique_int ? "OUI" : "NON") << "\n";
   cout << "   unique_int_2 a la valeur: " << *unique_int_2 << "\n\n";
   
   cout << "=== FIN DE LA DÉMONSTRATION ===\n\n";
 */   
   return 0;
}