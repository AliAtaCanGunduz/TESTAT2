#include "map.h"
#include <QGraphicsScene>
#include "Motorway.h"
#include "Stateroad.h"
/**
 * @file map.cpp
 * @brief Automatically documented file.
 *
 */
void Map::addCity(City*city) {
	cities.push_back(city);
}
bool Map::addStreet(Street* street) {
	City* start = street->getStart();
	City* end = street->getEnd();
	if (!cities.contains(start) || !cities.contains(end)) {
		return false;
	}
	streets.push_back(street);
	return true;

}
City* Map::findCity(const QString cityName)const{
	for (QVector<City*>::const_iterator it = cities.begin(); it != cities.end(); ++it) {
		if ((*it)->getname() == cityName) {
			return *it;
		}
	}
	return nullptr;

	
}
QVector<Street*> Map::getStreets() const {
	return streets;
}
QVector<Street*> Map::getStreetList(const City* city)const {
	QVector<Street*> result;
	for (QVector<Street*>::const_iterator it = streets.begin();it != streets.end();++it) {
		if ((*it)->getStart() == city || (*it)->getEnd() == city) {
			result.push_back(*it);
		}
	}
	return result;

}
City* Map::getOppositeCity(const Street* street, const City* city)const {
	if (street->getStart() == city) {
		return street->getEnd();
	}
	else if (street->getEnd() == city) {
		return street->getStart();
	}
	return nullptr;
}
double Map::getLength(const Street* street) const {
	if (const Motorway* m = dynamic_cast<const Motorway*>(street)) {
		return street->getLength() / 130.0;
	}
	if (const Stateroad* s = dynamic_cast<const Stateroad*>(street)) {
		return street->getLength() / 50.0;
	}
	return street->getLength();
}
void Map::draw(QGraphicsScene& scene) const {

	for (Street* s : streets) {
		s->draw(scene);	
	}

	for (City* c : cities) {
		c->draw(scene,this);
	}
}
QVector<City*> Map::getCities() const {
	return cities;  // veya cities.toVector() eðer container farklýysa
}