#ifndef DIALOGADDSTREET_H
#define DIALOGADDSTREET_H

#include <QDialog>
#include <QComboBox>
#include <QStringList>

/**
 * @brief Der DialogAddStreet erlaubt dem Benutzer,
 * zwei St�dte auszuw�hlen und den Stra�entyp zu bestimmen.
 */
class DialogAddStreet : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief Konstruktor: Erstellt das Dialogfenster
     * @param cityNames Liste aller verf�gbaren St�dtenamen
     * @param parent Qt-Elternelement
     */
    DialogAddStreet(const QStringList& cityNames, QWidget* parent = nullptr);

    /// Gibt den Namen der ausgew�hlten Startstadt zur�ck
    QString getStartCity() const;

    /// Gibt den Namen der ausgew�hlten Zielstadt zur�ck
    QString getEndCity() const;

    /// Gibt den gew�hlten Stra�entyp zur�ck
    QString getStreetType() const;

private:
    QComboBox* comboStart;  ///< Startstadt
    QComboBox* comboEnd;    ///< Zielstadt
    QComboBox* comboType;   ///< Stra�entyp (Street, Motorway, Stateroad)
};

#endif // DIALOGADDSTREET_H
