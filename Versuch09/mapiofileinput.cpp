///////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXV
// Versuch 9
//////////////////////////////////////////////////////////////////////////////

#include "mapiofileinput.h"

#include <QDebug>
#include <QFile>
#include <QIODevice>
#include <QTextStream>
#include <QRegularExpression>

#define CITY_EXTENSION
#define STREET_EXTENSION

#ifdef CITY_EXTENSION
#include "bigtown.h"
#include "smalltown.h"
#endif
#ifdef STREET_EXTENSION
#include "motorway.h"
#include "stateroad.h"
#endif

MapIoFileinput::MapIoFileinput(QString pathToCityFile, QString pathToStreetFile) :
    pathToCityFile(pathToCityFile),
    pathToStreetFile(pathToStreetFile)
{
}

MapIoFileinput::~MapIoFileinput()
{
}

void MapIoFileinput::fillMap(AbstractMap& map)
{
    QFile cityFile(pathToCityFile);
    QFile streetFile(pathToStreetFile);

    if (!cityFile.open(QIODevice::ReadOnly)) {
        qDebug() << "Fehler beim ÷ffnen der Stadtdatei: " << pathToCityFile;
        return;
    }

    if (!streetFile.open(QIODevice::ReadOnly)) {
        qDebug() << "Fehler beim ÷ffnen der Straﬂendatei: " << pathToStreetFile;
        return;
    }

    QTextStream input(&cityFile);
    QString line;

    // Einlesen der Stadtdatei
    while (!input.atEnd()) {
        line = input.readLine().trimmed();
        QStringList parts = line.split(QRegularExpression("\\s+"), Qt::SkipEmptyParts);

        if (parts.size() < 3) {
            qDebug() << "Ung¸ltige Stadtzeile, wird ¸bersprungen:" << line;
            continue;
        }

        QString name = parts[0];
        int x = parts[1].toInt();
        int y = parts[2].toInt();

        City* city = nullptr;

#ifdef CITY_EXTENSION
        if (parts.size() >= 4) {
            QString cityTyp = parts[3];
            if (cityTyp == "BigTown")
                city = new BigTown(name, x, y);
            else if (cityTyp == "SmallTown")
                city = new SmallTown(name, x, y);
        }
#endif

        if (!city)
            city = new City(name, x, y);

        map.addCity(city);
    }

    QTextStream inputStreet(&streetFile);

    // Einlesen der Straﬂendatei
    while (!inputStreet.atEnd()) {
        line = inputStreet.readLine().trimmed();
        QStringList parts = line.split(QRegularExpression("\\s+"), Qt::SkipEmptyParts);

        if (parts.size() < 2) {
            qDebug() << "Ung¸ltige Zeile in der Straﬂendatei, wird ¸bersprungen:" << line;
            continue;
        }

        QString firstCityName = parts[0];
        QString secondCityName = parts[1];
        QString streetTyp = (parts.size() >= 3) ? parts[2] : "Street";

        City* city1 = map.findCity(firstCityName);
        City* city2 = map.findCity(secondCityName);

        if (!city1 || !city2) {
            qDebug() << "Stadt nicht gefunden, Zeile wird ¸bersprungen:" << line;
            continue;
        }

        Street* street = nullptr;

        if (streetTyp == "Motorway")
            street = new Motorway(city1, city2);
        else if (streetTyp == "StateRoad" || streetTyp == "Stateroad")
            street = new Stateroad(city1, city2);
        else
            street = new Street(city1, city2);

        if (!map.addStreet(street)) {
            qDebug() << "Straﬂe konnte nicht hinzugef¸gt werden (St‰dte fehlen mˆglicherweise):" << line;
            delete street;
        }
    }

    streetFile.close();
    cityFile.close();
}