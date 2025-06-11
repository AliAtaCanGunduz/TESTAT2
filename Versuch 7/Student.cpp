//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXIV
//////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include "Student.h"

/**
 * @brief Konstruktor, der einen neuen Studenten mit allen Werten erstellt
 *
 * @param matNr Matrikelnummer
 * @param name Name
 * @param geburtstag Geburtstag
 * @param adresse Adresse
 */
Student::Student(unsigned int matNr, std::string name, std::string geburtstag, std::string adresse) :
matNr(matNr), name(name), geburtstag(geburtstag), adresse(adresse)
{ }

/**
 * @brief Standardkonstruktor, der einen leeren Studenten erstellt
 */
Student::Student() : matNr(0), name(""), geburtstag(""), adresse("")
{ }

/**
 * @brief Gibt die Matrikelnummer des Studenten zurueck
 *
 * @return Matrikelnummer
 */
unsigned int Student::getMatNr() const
{
    return matNr;
}

/**
 * @brief Gibt den Namen des Studenten zurueck
 *
 * @return Name
 */
std::string Student::getName() const
{
    return name;
}

/**
 * @brief Gibt den Geburtstag des Studenten zurueck
 *
 * @return Geburtstag
 */
std::string Student::getGeburtstag() const
{
    return geburtstag;
}

/**
 * @brief Gibt die Adresse des Studenten zurueck
 *
 * @return Adresse
 */
std::string Student::getAdresse() const
{
    return adresse;
}
/**
 * @brief Overloading << operator fuer ausgabe()
 *
 * @return os
 */

std::ostream& operator<<(std::ostream& os, const Student& s) {
    os << "Name: " << s.getName() << std::endl << "Matrikelnnummer: " << s.getMatNr() << std::endl << "Geburtstag: " << s.getGeburtstag() << std::endl << "Addresse: " << s.getAdresse() << std::endl;
    return os;
}
/**
 * @brief Gibt alle Daten des Studenten in einer Zeile aus
 * @param os wechseln die std::cout
 */
void Student::ausgabe(std::ostream& os)const 

{
    os << *this;
}
/**
 * @brief vergleichen die kleinere Stundent
 * @param other Student 
 */
bool Student::operator<(const Student& other) const {
    return this->matNr < other.matNr;
}
/**
 * @brief vergleichen die grössere Stundent
 * @param other Student
 */
bool Student::operator>(const Student& other) const {
    return this->matNr > other.matNr;
}
/**
 * @brief vergleichen die gleiche Student
 * @param other Student
 */

bool Student::operator==(const Student& other) const {
    return this->matNr == other.matNr;
}
