#ifndef MAP_H
#define MAP_H
#include "abstractmap.h"
/**
 * @class Map
 * @brief Erweiterung von AbstractMap, bietet Methoden zum Zeichnen und Verwalten einer Karte.
 */


class Map :public AbstractMap {
public:
	/**
	* @brief F�gt eine Stadt zur Karte hinzu.
	* @param city Zeiger auf die hinzuzuf�gende Stadt.
	* 
	*/
	void addCity(City*)override;
	/**
  * @brief F�gt eine Stra�e zur Karte hinzu.
  * @param street Zeiger auf die hinzuzuf�gende Stra�e.
  * @return true, wenn die Stra�e erfolgreich hinzugef�gt wurde.
  */
	bool addStreet(Street*)override;
	/**
 * @brief Sucht eine Stadt anhand ihres Namens.
 * @param cityName Der Name der gesuchten Stadt.
 * @return Zeiger auf die gefundene Stadt oder nullptr, falls nicht gefunden.
 */
	City* findCity(const QString cityName)const override;
	/**
 * @brief Gibt alle Stra�en zur�ck, die mit der angegebenen Stadt verbunden sind.
 * @param city Zeiger auf die Stadt.
 * @return Liste der zugeh�rigen Stra�en.
 */
	QVector<Street*> getStreetList(const City* city)const override;
	/**
 * @brief Gibt die gegen�berliegende Stadt einer Stra�e zur�ck.
 * @param street Zeiger auf die Stra�e.
 * @param city Zeiger auf eine der beiden St�dte.
 * @return Zeiger auf die gegen�berliegende Stadt oder nullptr.
 */
	City* getOppositeCity(const Street* street, const City* city)const override;
	/**
 * @brief Berechnet die L�nge einer Stra�e.
 * @param street Zeiger auf die Stra�e.
 * @return L�nge der Stra�e als double.
 */
	double getLength(const Street* street)const override;
	/**
 * @brief Zeichnet die gesamte Karte auf die �bergebene Szene.
 * @param scene Zeiger auf die QGraphicsScene, auf die gezeichnet werden soll.
 */
	void draw(QGraphicsScene& scene) const;

	/**
	 * @brief Gibt die Liste aller St�dte zur�ck.
	 * @return QVector mit Zeigern auf alle St�dte.
	 */
	QVector<City*>getCities()const;
	/**
 * @brief Gibt die Liste aller Stra�en zur�ck.
 * @return QVector mit Zeigern auf alle Stra�en.
 */
	QVector<Street*> getStreets() const;

private:
	QVector<City*> cities;/**< Liste aller St�dte */
	QVector<Street*> streets;/**< Liste aller Stra�en */




};
#endif
