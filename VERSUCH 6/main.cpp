/** @mainpage
 *
 * Praktikum Informatik 1 MMXXIV <BR>
 * Versuch 6: Dynamische Datenstrukturen
 *
 */

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include "Student.h"
int choice;
Student student;
/*
* @brief listesituation checken
* @param liste Student dynamic array
*/
bool listesituation(std::vector<Student> liste){
    if (liste.empty()) {//listeyi kontrol ediyor ez gayet
        return false;

    }
    else {
        return true;
    }
}
/*
* @brief datasichern fuer Diese Funktion ermöglicht es, ein dynamisches Array in eine Datei zu speichern.
* @param liste Studen dynamic array
*/
void datasichern(std::vector<Student> liste) {//datayi yazdiriyom
    std::string frage;
    std::cout << "In welche Datei moechtest du speichern?" << std::endl;
    std::cin >> frage;
    std::ofstream file(frage);//ofstream araciligiyla dosya acilir
    if (!file.is_open()) {//dosya acilip acilamayacigini cek et
        std::cerr << "File is not opened" << std::endl;
        
    }
    for (std::vector<Student>::const_iterator it = liste.begin();it != liste.end();it++) {//iterasyon araciligiyla listeyi kontrol et
        file << it->getMatNr() << std::endl;
        file << it->getName() << std::endl;
        file << it->getGeburtstag() << std::endl;
        file << it->getAdresse() << std::endl;
        //teker teker yazdir liste.begin()'den liste.end()'e kadar
    }


}
/*
* @brief Die Funktion, die das Einlesen der Datei ermöglicht.
* @param &liste dynamic array Referenz
* @param student Student class
*/
void readfile(std::vector<Student> &liste,Student student) {
    
    unsigned int matrikelnnummer=0; int counter = 1;//counter satirlari sayar
    
    std::string frage;
    std::string zeile;//satiri kopyala
    std::string name;//isime bak
    std::string geburtstag;//dogum gunune bak
    std::string adress;//adresse bak
    std::cout << "Aus welcher Datei moechten Sie die Daten einlesen? ";
    std::cin >> frage;
    std::cin.ignore(10, '\n');
    std::ifstream file(frage);
    if (!file.is_open()) {//file acip bakilacak
        std::cout << "File konnte nicht geoeffnet werden!" << std::endl;
        
    }
    else {
        std::cout << "File wird gefunden" << std::endl;//dosya bulundu
    }
    while (std::getline(file, zeile)) {
        if (counter % 4 == 1) {// (mod 1 matrikel) (mod 2 name) (mod 3 geburtstag) (mod 4 addresse)

            std::stringstream ss(zeile);//stringten integra cevirme

            ss >> matrikelnnummer;//stringi std::stringstream araciligiyla parcaliyor ve integer degerini string uzerinden giriyoruz bu yuzden >> kullanildi.



        }
        if (counter % 4 == 2) {
            name = zeile;

        }
        if (counter % 4 == 3) {
            geburtstag = zeile;

        }
        if (counter % 4 == 0) {
            adress = zeile;
            student = Student(matrikelnnummer, name, geburtstag, adress);
            liste.push_back(student); //yeni liste olusturuyorum.
        }
        counter++;

    }

}
int main()
{
    char abfrage;
    
    std::vector<Student> liste;
    readfile(liste, student);
   


    /*
    if (abfrage != 'j')
    {
        student = Student(34567, "Harro Simoneit", "19.06.1971", "Am Markt 1");
        liste.push_back(student);
        student = Student(74567, "Vera Schmitt", "23.07.1982", "Gartenstr. 23");
        liste.push_back(student);
        student = Student(12345, "Siggi Baumeister", "23.04.1983", "Ahornst.55");
        liste.push_back(student);
        student = Student(64567, "Paula Peters", "9.01.1981", "Weidenweg 12");
        liste.push_back(student);
       
        student = Student(23456, "Walter Rodenstock", "15.10.1963", "Wüllnerstr.9");
        liste.push_back(student);
    }*/


    do
    {
        std::cout << "\nMenue:" << std::endl
            << "-----------------------------" << std::endl
            << "(1): Datenelement hinten hinzufuegen" << std::endl
            << "(2): Datenelement hinten entfernen" << std::endl
            << "(3): Datenbank ausgeben" << std::endl << "(8):Ein Element an gewuenschter Position einfuegen" << std::endl << "(7):Ein Element an gewuenschter Position loeschen" << std::endl

            << "(0): Beenden" << std::endl << "(4) : Datenbank rueckwaertsausgeben" << std::endl << "(5):Datenelement vorne loeschen" << std::endl << "(6):Datenelement vorne hinzufuegen" << std::endl << "(R):Daten aus einer Datei einlesen" << std::endl << "(W):Daten in eine Datei sichern" << std::endl;
        std::cin >> abfrage;
        
        

        switch (abfrage)
        {
            // Datenelement hinten hinzufuegen
            case '1':
                {
                    unsigned int matNr = 0;
                    std::string name = "";
                    std::string geburtstag = "";
                    std::string adresse = "";

                    std::cout << "Bitte geben sie die Daten fur den Studenten ein.\nName: ";
                    std::cin >> name;  // ganze Zeile einlesen inklusive aller Leerzeichen

                    std::cout << "Geburtsdatum: ";
                    std::cin >> geburtstag;

                    std::cout << "Adresse: ";
                    std::cin >> adresse;

                    std::cout << "Matrikelnummer: ";
                    std::cin >> matNr;
                    std::cin.ignore(10, '\n');

                    student = Student(matNr, name, geburtstag, adresse);
                    liste.push_back(student);

                   
                }
                break;

            // Datenelement vorne entfernen
            case '2':
                {
                if (listesituation(liste) == true) {
                    liste.erase(liste.end() - 1); //liste.end()-1 son eleman 

                }

                

                }
                break;

            // Datenbank vorwaerts ausgeben
            case '3':
                
                 for (std::vector<Student>::iterator it = liste.begin();it != liste.end();it++) {//iterator liste.begin() baslar liste.end() ile bitecek
                        it->ausgabe(); //it pointeri ile ausgabe() metodu calisiyor
                 }

                
  
               
        
    
                break;
            case '7':
                
                std::cout << "Geben Sie die Position ein, an der das Element   geloescht werden soll: ";
                std::cin >> choice;
                if (choice < 1 || choice > liste.size()) {
                    std::cout << "Ungueltig" << std::endl;
                    return 0;
                }
                else {
                    if (listesituation(liste) == true) {
                        liste.erase(liste.begin() + (choice - 1));//-1 cunku 0. elemanımı çıkarıcam

                    }
                    
                }
                break;

                

            case '4':
                
                  for (std::vector<Student>::reverse_iterator rit = liste.rbegin();rit != liste.rend();rit++) {//reverse_iterator sondan basa gider liste.end() ten liste.begin()
                        rit->ausgabe();
                  }

                
  

                break;
            case '5':
                if (listesituation(liste) == true) {
                    liste.begin()->ausgabe();
                    std::cout << "wid geloescht" << std::endl;
                    liste.erase(liste.begin());

                }




                break;
            case '8':
                
                std::cout << "Geben Sie die Position ein, an der das Element eingefuegt werden soll: ";
                std::cin >> choice;
                if (choice < 1 ||choice>liste.size()+1) {
                    std::cout << "Ungueltig" << std::endl;
                    return 0;
           
                

                }
                else {
                    unsigned int matNr = 0;
                    std::string name = "";
                    std::string geburtstag = "";
                    std::string adresse = "";

                    std::cout << "Bitte geben sie die Daten fur den Studenten ein.\nName: ";
                    std::cin >> name;  // ganze Zeile einlesen inklusive aller Leerzeichen

                    std::cout << "Geburtsdatum: " << std::endl;
                    std::cin >> geburtstag;

                    std::cout << "Adresse: "<<std::endl;
                    std::cin >> adresse;

                    std::cout << "Matrikelnummer: ";
                    std::cin >> matNr;
                    std::cin.ignore(10, '\n');

                    student = Student(matNr, name, geburtstag, adresse);
                    liste.insert(liste.begin()+(choice - 1),student);
                }
                break;

                

                


            case '0':
                std::cout << "Das Programm wird nun beendet";
                break;
            case '6':
            {
                unsigned int matNrt = 0;
                std::string names = "";
                std::string geburtstags = "";
                std::string adresses = "";

                std::cout << "Bitte geben sie die Daten fuer den Studenten ein.\nName: ";
                getline(std::cin, names);    // ganze Zeile einlesen inklusive aller Leerzeichen

                std::cout << "Geburtsdatum: ";
                getline(std::cin, geburtstags);

                std::cout << "Adresse: ";
                getline(std::cin, adresses);

                std::cout << "Matrikelnummer: ";
                std::cin >> matNrt;
                std::cin.ignore(10, '\n');

                student = Student(matNrt, names, geburtstags, adresses);
              
                
            }
            break;
            case 'R':
            {
                liste.clear();
                readfile(liste, student);

            }
             
                break;
            case 'W':
            {
                datasichern(liste);

            }
                
                break;



            default :
                std::cout << "Falsche Eingabe, bitte nochmal";
                break;
        }
    }
    while (abfrage != '0');

    return 0;
}
