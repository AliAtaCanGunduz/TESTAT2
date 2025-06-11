#include "Buch.h"
#include <iostream>

Buch::Buch(std::string initTitel,std::string initAutor):
	Medium(initTitel),autor(initAutor){ }
void Buch::ausgabe(std::ostream& os )const {
	Medium::ausgabe(os);
	os << "Autor: " << autor << std::endl;
	

}