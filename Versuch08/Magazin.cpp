#include <iostream>
#include "Magazin.h"
Magazin::Magazin(std::string initTitel, Datum initAusgabeDatum, std::string initSparte) :
	Medium(initTitel), ausgabeDatum(initAusgabeDatum), sparte(initSparte) {

}
void Magazin::ausgabe(std::ostream& os)const {
	Medium::ausgabe(os);
	os << "Ausgabe: " << ausgabeDatum << std::endl;
	os << "Sparte: " << sparte << std::endl;
}
bool Magazin::ausleihen(Person person, Datum datum) {
	if (datum - ausgabeDatum == 0) {
		std::cout << "Dieses Magazin ist die neueste Ausgabe und kann nicht ausgeliehen werden." << std::endl;
		return false;
	}
	return Medium::ausleihen(person, datum);
}