#ifndef BUCH_H
#define BUCH_H

#include "Medium.h"


class Buch : public Medium {
private:
    std::string autor;

public:
    // Constructor
    /*!
 * @brief Konstruktor für die Klasse Buch.
 *
 * Initialisiert ein Buch mit Titel und Autor.
 *
 * @param initTitel Der Titel des Buches.
 * @param initAutor Der Autor des Buches.
 */
    Buch(std::string initTitel, std::string initAutor);
    /*!
 * @brief Gibt die Informationen des Buches aus.
 *
 * Überschreibt die Ausgabefunktion der Basisklasse Medium,
 * um zusätzlich den Autor des Buches anzuzeigen.
 *
 * @param os Der Ausgabestrom, in den geschrieben wird.
 */

    // Ausgabe override
    void ausgabe(std::ostream& os) const override;
};

#endif

