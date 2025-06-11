#include "dialogaddstreet.h"

#include <QFormLayout>
#include <QDialogButtonBox>
#include <QLabel>

/**
 * @brief Konstruktor: Erstellt das Dialogfenster mit Eingabefeldern.
 */
DialogAddStreet::DialogAddStreet(const QStringList& cityNames, QWidget* parent)
    : QDialog(parent)
{
    setWindowTitle("Straße hinzufügen");

    QFormLayout* layout = new QFormLayout(this);

    comboStart = new QComboBox(this);
    comboStart->addItems(cityNames);
    layout->addRow("Startstadt:", comboStart);

    comboEnd = new QComboBox(this);
    comboEnd->addItems(cityNames);
    layout->addRow("Zielstadt:", comboEnd);

    comboType = new QComboBox(this);
    comboType->addItems(QStringList() << "Street" << "Motorway" << "Stateroad");
    layout->addRow("Typ:", comboType);

    QDialogButtonBox* buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel, this);
    layout->addWidget(buttonBox);

    connect(buttonBox, &QDialogButtonBox::accepted, this, &QDialog::accept);
    connect(buttonBox, &QDialogButtonBox::rejected, this, &QDialog::reject);
}

/**
 * @brief Gibt den Namen der gewählten Startstadt zurück.
 */
QString DialogAddStreet::getStartCity() const {
    return comboStart->currentText();
}

/**
 * @brief Gibt den Namen der gewählten Zielstadt zurück.
 */
QString DialogAddStreet::getEndCity() const {
    return comboEnd->currentText();
}

/**
 * @brief Gibt den gewählten Straßentyp zurück.
 */
QString DialogAddStreet::getStreetType() const {
    return comboType->currentText();
}