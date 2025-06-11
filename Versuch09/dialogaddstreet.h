#ifndef DIALOGADDSTREET_H
#define DIALOGADDSTREET_H

#include <QDialog>
#include <QComboBox>
#include <QStringList>

/**
 * @brief Der DialogAddStreet erlaubt dem Benutzer,
 * zwei Städte auszuwählen und den Straßentyp zu bestimmen.
 */
class DialogAddStreet : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief Konstruktor: Erstellt das Dialogfenster
     * @param cityNames Liste aller verfügbaren Städtenamen
     * @param parent Qt-Elternelement
     */
    DialogAddStreet(const QStringList& cityNames, QWidget* parent = nullptr);

    /// Gibt den Namen der ausgewählten Startstadt zurück
    QString getStartCity() const;

    /// Gibt den Namen der ausgewählten Zielstadt zurück
    QString getEndCity() const;

    /// Gibt den gewählten Straßentyp zurück
    QString getStreetType() const;

private:
    QComboBox* comboStart;  ///< Startstadt
    QComboBox* comboEnd;    ///< Zielstadt
    QComboBox* comboType;   ///< Straßentyp (Street, Motorway, Stateroad)
};

#endif // DIALOGADDSTREET_H
