#include "Versuch9.h"

#include <QGraphicsScene>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QFormLayout>
#include <QLineEdit>
#include <QDialog>
#include <QDialogButtonBox>
#include <QFileDialog>
#include <QDebug>
#include <qlabel.h>
#include "map.h"
#include "city.h"
#include "mapiofileinput.h"
#include "dijkstra.h"
#include "Motorway.h"
#include "Stateroad.h"
#include "Street.h"
#include "dialogaddstreet.h"
#include "bigtown.h"
#include "smalltown.h"
#include <qmessagebox.h>
#include <qcheckbox.h>
#include <qinputdialog.h>

static Map* globalMap = nullptr;
void Versuch9::testAbstractMap()
{
    Map testMap;
    City* a = new City("a", 0, 0);
    City* b = new City("b", 0, 100);
    City* c = new City("c", 100, 300);
    Street* s = new Street(a, b);
    Street* s2 = new Street(b, c);

    qDebug() << "MapTest: Start Test of the Map";
    {
        qDebug() << "MapTest: adding wrong street";
        bool t1 = testMap.addStreet(s);
        if (t1) {
            qDebug() << "-Error: Street should not be added, if cities have not been added.";
        }
    }

    {
        qDebug() << "MapTest: adding correct street";
        testMap.addCity(a);
        testMap.addCity(b);
        bool t1 = testMap.addStreet(s);
        if (!t1) {
            qDebug() << "-Error: It should be possible to add this street.";
        }
    }

    {
        qDebug() << "MapTest: findCity";
        City* city = testMap.findCity("a");
        if (city != a)
            qDebug() << "-Error: City a could not be found.";

        city = testMap.findCity("b");
        if (city != b)
            qDebug() << "-Error: City b could not be found.";

        city = testMap.findCity("c");
        if (city != nullptr)
            qDebug() << "-Error: If city could not be found 0 should be returned.";
    }

    testMap.addCity(c);
    testMap.addStreet(s2);

    {
        qDebug() << "MapTest: getOppositeCity";
        const City* city = testMap.getOppositeCity(s, a);
        if (city != b)
            qDebug() << "-Error: Opposite city should be b.";

        city = testMap.getOppositeCity(s, c);
        if (city != nullptr)
            qDebug() << "-Error: Opposite city for a city which is not linked by given street should be 0.";
    }

    {
        qDebug() << "MapTest: streetLength";
        double l = testMap.getLength(s2);
        double expectedLength = 223.6;
        if (l < expectedLength * 0.95 || l > expectedLength * 1.05)
            qDebug() << "-Error: Street Length is not equal to the expected.";
    }

    {
        qDebug() << "MapTest: getStreetList";
        QVector<Street*> streetList1 = testMap.getStreetList(a);
        QVector<Street*> streetList2 = testMap.getStreetList(b);
        if (streetList1.size() != 1) {
            qDebug() << "-Error: One street should be found for city a.";
        }
        else if (*streetList1.begin() != s) {
            qDebug() << "-Error: The wrong street has been found for city a.";
        }

        if (streetList2.size() != 2)
            qDebug() << "-Error: Two streets should be found for city b.";
    }

    qDebug() << "MapTest: End Test of the Map.";
}


City* showAddCityDialog(QWidget* parent) {
    QDialog dialog(parent);
    dialog.setWindowTitle("Stadt hinzufügen");

    QFormLayout form(&dialog);
    QLineEdit* nameEdit = new QLineEdit(&dialog);
    QLineEdit* xEdit = new QLineEdit(&dialog);
    QLineEdit* yEdit = new QLineEdit(&dialog);
    form.addRow("Name:", nameEdit);
    form.addRow("X:", xEdit);
    form.addRow("Y:", yEdit);

    QDialogButtonBox buttonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel, Qt::Horizontal, &dialog);
    form.addRow(&buttonBox);

    QObject::connect(&buttonBox, &QDialogButtonBox::accepted, &dialog, &QDialog::accept);
    QObject::connect(&buttonBox, &QDialogButtonBox::rejected, &dialog, &QDialog::reject);

    if (dialog.exec() == QDialog::Accepted) {
        QString name = nameEdit->text();
        bool ok1, ok2;
        int x = xEdit->text().toInt(&ok1);
        int y = yEdit->text().toInt(&ok2);
        if (!name.isEmpty()&& ok1 && ok2) {
            return new City(name, x, y);
        }
        else {
            qDebug()<< "Geçersiz giriş (sayı değil).";
        }
    }
    return nullptr;
}
void Versuch9::updateCityComboBoxes() {
    comboStart->clear();
    comboZiel->clear();

    if (!globalMap) return;

    QStringList names;
    for (City* c : globalMap->getCities()) {
        names << c->getname();
    }

    comboStart->addItems(names);
    comboZiel->addItems(names);

}
Versuch9::Versuch9(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::Versuch9)
{
    ui->setupUi(this);
    QMenu* dateiMenu = menuBar()->addMenu("Datei");
    QAction* actionOpen = dateiMenu->addAction("Öffnen");
    QAction* actionSave = dateiMenu->addAction("Speichern");
    dateiMenu->addSeparator();
    QAction* actionExit = dateiMenu->addAction("Beenden");
    actionExit->setShortcut(QKeySequence("Alt+E"));
    // Menü "Szene" oluştur
    QMenu* szeneMenu = menuBar()->addMenu("Szene");
    // Şehir seçimi için ComboBox'lar
    comboStart = new QComboBox();
    comboZiel = new QComboBox();
    comboStart->setPlaceholderText("Startstadt wählen");
    comboZiel->setPlaceholderText("Zielstadt wählen");

 

    // Menü öğesi: Szene leeren
    QAction* actionSzeneLeeren = szeneMenu->addAction("Szene leeren");
    actionSzeneLeeren->setShortcut(QKeySequence("Alt+S"));
    QMenu* hilfeMenu = menuBar()->addMenu("Hilfe");
    QAction* actionAbout = hilfeMenu->addAction("Über");
    scene = new QGraphicsScene(this);
    scene->setSceneRect(0, 0, 1600, 1200);
    ui->graphicsView->setScene(scene);

    QWidget* central = new QWidget(this);
    QHBoxLayout* mainLayout = new QHBoxLayout(central);

    QVBoxLayout* buttonLayout = new QVBoxLayout();
    QPushButton* btnDrawCity = new QPushButton("Test Draw City");
    QPushButton* btnAddCity = new QPushButton("Add City");
    QPushButton* btnClear = new QPushButton("Clear Scene");
    QPushButton* btnReload = new QPushButton("Reload Map");
    QPushButton* btnPath = new QPushButton("Dijkstra Path Test");
    QPushButton* btnLoadFromFile = new QPushButton("Load Map from File");
    QPushButton* btnAddStreet = new QPushButton("Straße hinzufügen", this);
    QCheckBox* toggleTests = new QCheckBox("Testfunktionen anzeigen");
    QPushButton* btnTestAbstractMap = new QPushButton("Test Abstract Map");
    toggleTests->setChecked(true);
    buttonLayout->addWidget(btnTestAbstractMap);
    buttonLayout->addWidget(toggleTests);
    buttonLayout->addWidget(btnAddStreet);
    buttonLayout->addWidget(btnDrawCity);
    buttonLayout->addWidget(btnAddCity);
    buttonLayout->addWidget(btnClear);
    buttonLayout->addWidget(btnReload);
    buttonLayout->addWidget(btnPath);
    buttonLayout->addWidget(btnLoadFromFile);
    buttonLayout->addStretch();
    buttonLayout->addWidget(new QLabel("Start:"));
    buttonLayout->addWidget(comboStart);
    buttonLayout->addWidget(new QLabel("Ziel:"));
    buttonLayout->addWidget(comboZiel);


    // "Weg suchen" butonu
    QPushButton* btnFindPath = new QPushButton("Weg suchen");
    buttonLayout->addWidget(btnFindPath);

    // Map yüklendiğinde ComboBox'ları güncelle
    updateCityComboBoxes();

    QWidget* buttonPanel = new QWidget(this);
    buttonPanel->setLayout(buttonLayout);

    mainLayout->addWidget(buttonPanel);
    mainLayout->addWidget(ui->graphicsView);

    central->setLayout(mainLayout);
    setCentralWidget(central);

    connect(btnDrawCity, &QPushButton::clicked, this, [=]() {
        if (!globalMap) {
            globalMap = new Map();
        }

        City* test = new City("Teststadt", 500, 500);
        globalMap->addCity(test);
        test->draw(*scene, globalMap);
        updateCityComboBoxes();

    
        });
    static QVector<Street*> previousPath;
    connect(btnFindPath, &QPushButton::clicked, this, [=]() {
        if (!globalMap) return;

        QString start = comboStart->currentText();
        QString ziel = comboZiel->currentText();

        // Geçersiz seçim kontrolü
        if (start.isEmpty() || ziel.isEmpty() || start == ziel) {
            QMessageBox::warning(this, "Ungültige Auswahl", "Bitte wählen Sie zwei verschiedene Städte.");
            return;
        }

        // Eski yolu normale çevir
        for (Street* s : previousPath) {
            s->draw(*scene);  // virtual olmalı!
        }

        // Yeni yol araması
        QVector<Street*> path = Dijkstra::search(*globalMap, start, ziel);

        if (path.isEmpty()) {
            QMessageBox::information(this, "Kein Weg", "Zwischen den Städten wurde kein Weg gefunden.");
            previousPath.clear();
            return;
        }

        // Yeni yolu kırmızı çiz
        for (Street* s : path) {
            s->drawRed(*scene);  
        }

        previousPath = path;  
 
        });
    connect(btnTestAbstractMap, &QPushButton::clicked, this, [=]() {
        testAbstractMap();
        QMessageBox::information(this, "Test", "Test Abstract Map çalıştı!");
        });
    connect(toggleTests, &QCheckBox::toggled, this, [=](bool checked) {
        btnDrawCity->setVisible(checked);
        btnPath->setVisible(checked);
        btnReload->setVisible(checked);
        btnTestAbstractMap->setVisible(checked);
        });
    connect(actionSzeneLeeren, &QAction::triggered, this, [=]() {
        scene->clear();
        if (globalMap) {
            delete globalMap;
            globalMap = nullptr;
        }
        updateCityComboBoxes();
        qDebug() << "Szene wurde geleert.";
        });
    connect(actionExit, &QAction::triggered, this, &QWidget::close);

    connect(actionSave, &QAction::triggered, this, [=]() {
        if (!globalMap) {
            QMessageBox::warning(this, "Warnung", "Keine Karte zum Speichern.");
            return;
        }

        QString cityFile = QFileDialog::getSaveFileName(this, "Städtedatei speichern", "", "Textdateien (*.txt)");
        if (cityFile.isEmpty()) return;

        QString streetFile = QFileDialog::getSaveFileName(this, "Straßendatei speichern", "", "Textdateien (*.txt)");
        if (streetFile.isEmpty()) return;

        QFile cityOut(cityFile);
        QFile streetOut(streetFile);
        if (!cityOut.open(QIODevice::WriteOnly | QIODevice::Text) ||
            !streetOut.open(QIODevice::WriteOnly | QIODevice::Text)) {
            QMessageBox::critical(this, "Fehler", "Dateien konnten nicht geöffnet werden.");
            return;
        }

        QTextStream cityStream(&cityOut);
        for (City* c : globalMap->getCities()) {
            cityStream << c->getname() << " " << c->getX() << " " << c->getY();

            if (dynamic_cast<BigTown*>(c))
                cityStream << " BigTown";
            else if (dynamic_cast<SmallTown*>(c))
                cityStream << " SmallTown";

            cityStream << "\n";  // ← Bu sadece 1 kere çağrılmalı
  
        }

        QTextStream streetStream(&streetOut);
        QVector<Street*> streets = globalMap->getStreets();

        qDebug() << "Speichern: street sayısı =" << streets.size();

        for (Street* s : streets) {
            QString startName = s->getStart()->getname();
            QString endName = s->getEnd()->getname();
            QString typ = "Street";

            if (dynamic_cast<Motorway*>(s)) typ = "Motorway";
            else if (dynamic_cast<Stateroad*>(s)) typ = "Stateroad";

            streetStream << startName << " " << endName << " " << typ << "\n";
        }
        });

    connect(actionAbout, &QAction::triggered, this, [=]() {
        QMessageBox::about(this, "Über dieses Programm",
            "StreetPlanner\nEin einfaches Kartenprogramm mit Dijkstra-Algorithmus.\nErstellt im Rahmen des Praktikums.");
        }); 
    connect(actionOpen, &QAction::triggered, this, [=]() {
        QString cityFile = QFileDialog::getOpenFileName(this, "Städtedatei wählen", "", "Textdateien (*.txt)");
        if (cityFile.isEmpty()) return;
        QString streetFile = QFileDialog::getOpenFileName(this, "Straßendatei wählen", "", "Textdateien (*.txt)");
        if (streetFile.isEmpty()) return;

        loadAndDrawMap(cityFile, streetFile);
        });
    connect(btnAddCity, &QPushButton::clicked, this, [=]() {
        if (!globalMap) {
            globalMap = new Map();
        }

        City* tempCity = showAddCityDialog(this);
        if (tempCity) {
            // Stadt-Typ Auswahl
            QStringList typen = { "City", "Großstadt", "Kleinstadt" };
            bool ok;
            QString auswahl = QInputDialog::getItem(
                this,
                "Stadttyp wählen",
                "Welche Art von Stadt möchten Sie hinzufügen?",
                typen,
                0, // Standardindex
                false, // Editable
                &ok
            );

            if (!ok || auswahl.isEmpty()) {
                delete tempCity;
                return;
            }

            City* c = nullptr;
            if (auswahl == "Großstadt")
                c = new BigTown(tempCity->getname(), tempCity->getX(), tempCity->getY());
            else if (auswahl == "Kleinstadt")
                c = new SmallTown(tempCity->getname(), tempCity->getX(), tempCity->getY());
            else
                c = new City(tempCity->getname(), tempCity->getX(), tempCity->getY());

            delete tempCity;

            globalMap->addCity(c);
            c->draw(*scene, globalMap);
            updateCityComboBoxes();

            qDebug() << "Stadt hinzugefügt:" << c->getname() << c->getX() << c->getY();
        }
        else {
            qDebug() << "Stadt wurde nicht erstellt oder Eingabe abgebrochen.";
        }
        });

    connect(btnClear, &QPushButton::clicked, this, [=]() {
        scene->clear();
        
        if (globalMap) {
            
            delete globalMap;
            globalMap = nullptr;
            
        }
        updateCityComboBoxes();
        
        });

    connect(btnReload, &QPushButton::clicked, this, [=]() {
        loadAndDrawMap("city_file.txt", "street_file.txt");
        });

    connect(btnPath, &QPushButton::clicked, this, [=]() {
        if (!globalMap) return;
        QString start = QStringLiteral("Köln");
        QString ziel = QStringLiteral("Bielefeld");
        QVector<Street*> path = Dijkstra::search(*globalMap, start,ziel);
        for (Street* s : path)
            s->drawRed(*scene);
        });

    connect(btnLoadFromFile, &QPushButton::clicked, this, [=]() {
        QString cityFile = QFileDialog::getOpenFileName(this, "Stadtdatei wählen", "", "Textdateien (*.txt)");
        if (cityFile.isEmpty()) return;
        QString streetFile = QFileDialog::getOpenFileName(this, "Straßendatei wählen", "", "Textdateien (*.txt)");
        if (streetFile.isEmpty()) return;
        loadAndDrawMap(cityFile, streetFile);
        });
    connect(btnAddStreet, &QPushButton::clicked, this, [=]() {
        if (!globalMap) return;

        // Şehir adlarını al
        QStringList cities;
        for (City* c : globalMap->getCities()) {
            cities << c->getname();
        }

        // Diyalog göster
        DialogAddStreet dialog(cities, this);
        if (dialog.exec() == QDialog::Accepted) {
            QString startName = dialog.getStartCity();
            QString endName = dialog.getEndCity();
            QString type = dialog.getStreetType();

            City* a = globalMap->findCity(startName);
            City* b = globalMap->findCity(endName);

            if (!a || !b) return;

            Street* street = nullptr;
            if (type == "Motorway")
                street = new Motorway(a, b);
            else if (type == "Stateroad")
                street = new Stateroad(a, b);
            else
                street = new Street(a, b);

            if (globalMap->addStreet(street)) {
                street->draw(*scene);
            }
            else {
                delete street;  // eklenemezse bellek sızıntısı önlenir
            }
        }
        });
    loadAndDrawMap("city_file.txt", "street_file.txt");
}

Versuch9::~Versuch9()
{
    delete ui;
    if (globalMap) {
        delete globalMap;
        globalMap = nullptr;
    }
}

void Versuch9::loadAndDrawMap(const QString& cityFile, const QString& streetFile)
{
    scene->clear();

    if (globalMap) {
        delete globalMap;
        globalMap = nullptr;
    }

    // Yeni harita oluştur
    globalMap = new Map();

    // Dosyadan verileri yükle
    MapIoFileinput loader(cityFile, streetFile);
    loader.fillMap(*globalMap);

    // Haritayı sahneye çiz
    globalMap->draw(*scene);
    updateCityComboBoxes();


}

