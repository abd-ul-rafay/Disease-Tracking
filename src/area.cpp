#include "area.h"

Area::Area(string name) {

    this->name = name;

    this->noOfAffecties = 0;
}

void Area::insertPatientInArea(Patient patient) {
    patientInArea.add(patient);
    
}



string Area::getName() {
    return this->name;
}

List Area::getList() {
    return patientInArea;
}

void Area::display() {

    int size = patientInArea.size();

    noOfAffecties = size;

    cout << endl;
    cout << "Name of Area: " << name << endl; 
    cout << "No. of Affecties: " << noOfAffecties << endl;
    
    if (patientInArea.size() > 0) {

        cout << endl << "All Patients: " << endl << endl;
        patientInArea.display();

    }
    
    cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << endl;

}
