#include <iostream>
#include "DVD.h"
DVD::DVD(std::string initTitel, int initAltersfreigabe, std::string initGenre) :
	Medium(initTitel), altersfreigabe(initAltersfreigabe), genre(initGenre) {
};
void DVD::ausgabe(std::ostream& os)const{
	Medium::ausgabe(os);
	os << "FSK: ab " << altersfreigabe << " Jahre" << std::endl;
	os << "Genre: " << genre << std::endl;


}
bool DVD::ausleihen(Person person, Datum ausleihdatum) {
	int age = ausleihdatum.berechneAlterInJahren(person.getGeburtsdatum());
	std::cout << "[DEBUG] DVD::ausleihen() aufgerufen. Alter: " << age<< std::endl;
	if (age<altersfreigabe) {
		std::cout << "Diese DVD darf erst ab " << altersfreigabe << " Jahren ausgeliehen werden!" << std::endl;
		return false;
	}
	return Medium::ausleihen(person, ausleihdatum);
}
