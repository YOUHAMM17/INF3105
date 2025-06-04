CompteBancaire::CompteBancaire(const std::string& nom, double montantInitial) : titulaire(nom), solde(montantInitial) {
  std::cout << "Constructeur de CompteBancaire" << std::endl;
