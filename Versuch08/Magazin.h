	#ifndef MAGAZIN_H
	#define MAGAZIN_H
	#include "Medium.h"
	#include "Datum.h"
	class Magazin :public Medium {
	private:
		Datum ausgabeDatum;
		std::string sparte;
	public:
		/*!
	* @brief Konstruktor für die Klasse DVD.
	 *
	* Initialisiert eine DVD mit Titel, Altersfreigabe und Genre.
	*
	* @param initTitel Der Titel der DVD.
	* @param initAltersfreigabe Das Mindestalter für die Ausleihe.
	 * @param initGenre Das Genre der DVD.
	 */

		Magazin(std::string initTitel, Datum initAusgabeDatum, std::string initSparte);
		/*!
	* @brief Konstruktor für die Klasse DVD.
	 *
	 * Initialisiert eine DVD mit Titel, Altersfreigabe und Genre.
	*
	* @param initTitel Der Titel der DVD.
	* @param initAltersfreigabe Das Mindestalter für die Ausleihe.
	* @param initGenre Das Genre der DVD.
	*/

		void ausgabe(std::ostream& os) const override;
		/*!
	* @brief Versucht, die DVD auszuleihen.
	 *
	* Die DVD kann nur ausgeliehen werden, wenn die Person alt genug ist.
	*
	 * @param person Die Person, die die DVD ausleihen möchte.
	* @param ausleihdatum Das aktuelle Datum.
	* @return true, wenn die Altersfreigabe erfüllt ist, sonst false.
	*/

	
		bool ausleihen(Person person, Datum datum) override;

		
			

	


	};













	#endif
