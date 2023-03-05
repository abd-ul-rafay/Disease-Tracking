#include "patient.h"

Patient::Patient() {
    strcpy(name, "");
    strcpy(gender, "");
    age = 0;
    strcpy(cnic, "");
    strcpy(diseaseName, "");
    strcpy(areaName, "");
    strcpy(financialStatus, "");
    strcpy(applicationStatus, ""); 
    strcpy(dateOfDiseaseStart, "");
}

void Patient::setData(bool changeAllData) {

    // the data inside will only change once

    if (changeAllData) {

        cin.ignore();

        cout << "Enter your name: ";                           cin.get(name, 20);                 cin.ignore();
        cout << "Enter your password: ";                       cin.get(password, 20);             cin.ignore();
        cout << "Enter your gender: ";                         cin.get(gender, 10);               cin.ignore();
        cout << "Enter your age: ";                            cin >> age;                        cin.ignore();
        cout << "Enter your CNIC: ";                           cin.get(cnic, 20);                 cin.ignore();
    }

    // if we have to update data, we will only update below data

    cout << "Here are some Diseases" << endl;
    cout << "1. Allergies | 2. Colds and Flu | 3. Conjunctivitis | 4. Diarrhea | 5. Headaches | 6. Mononucleosis | 7. Stomach Aches | 8. Others" << endl;
    int diseaseNo;
    cout << "Enter your disease no.: ";                     cin >> diseaseNo;                 cin.ignore();
    switch (diseaseNo) {
        case 1: strcpy(diseaseName, "Allergies"); break;
        case 2: strcpy(diseaseName, "Colds and Flu"); break;
        case 3: strcpy(diseaseName, "Conjunctivitis"); break;
        case 4: strcpy(diseaseName, "Diarrhea"); break;
        case 5: strcpy(diseaseName, "Headaches"); break;
        case 6: strcpy(diseaseName, "Mononucleosis"); break;
        case 7: strcpy(diseaseName, "Stomach Aches"); break;
        case 8: strcpy(diseaseName, "Others"); break;
    }

    cout << "Here are some Areas" << endl;
    cout << "1. Karachi | 2. Lahore | 3. Islamabad | 4. Multan | 5. Peshawar | 6. Quetta | 7. Faisalabad | 8. Gujranwala | 9. Rawalpindi | 10. Sialkot | 11. Others" << endl;
    int areaNo;
    cout << "Enter your area no.: ";                        cin >> areaNo;                    cin.ignore();
    switch (areaNo) {
        case 1: strcpy(areaName, "Karachi"); break;
        case 2: strcpy(areaName, "Lahore"); break;
        case 3: strcpy(areaName, "Islamabad"); break;
        case 4: strcpy(areaName, "Multan"); break;
        case 5: strcpy(areaName, "Peshawar"); break;
        case 6: strcpy(areaName, "Quetta"); break;
        case 7: strcpy(areaName, "Faisalabad"); break;
        case 8: strcpy(areaName, "Gujranwala"); break;
        case 9: strcpy(areaName, "Rawalpindi"); break;
        case 10: strcpy(areaName, "Sialkot"); break;
        default: strcpy(areaName, "Others"); break;
    }
    
    cout << "1. Rich | 2. Middle class | 3. Lower class | 4. Poor | 5. Worst than poor" << endl;
    int statusId;
    cout << "What are you: ";                        cin >> statusId;                    cin.ignore();
    switch (statusId) {
        case 1: strcpy(financialStatus, "Rich"); break;
        case 2: strcpy(financialStatus, "Middle class"); break;
        case 3: strcpy(financialStatus, "Lower class"); break;
        case 4: strcpy(financialStatus, "Poor"); break;
        case 5: strcpy(financialStatus, "Worst than poor"); break;
        default: strcpy(financialStatus, "Not mentioned"); break;
    }

    cout << "Enter date [dd/mm/yyyy] when Disease Started: ";         cin.get(dateOfDiseaseStart, 20);   cin.ignore();
}

void Patient::setApplicationStatus(string newStatus) {
    strcpy(applicationStatus, newStatus.c_str());
}

string Patient::getName() {
    return this->name;
}

string Patient::getPassword() {
    return this->password;
}

string Patient::getCnic() {
    return this->cnic;
}

string Patient::getAreaName() {
    return this->areaName;
}

string Patient::getApplicationStatus() {
    return this->applicationStatus;
}

void Patient::display() {
    
    cout << "Name: " << this->name << " -- ";
    cout << "CNIC: " << this->cnic << endl;
    cout << "Age: " << this->age << " -- ";
    cout << "Gender: " << this->gender << endl;
    cout << "Disease: " << this->diseaseName << " -- ";
    cout << "Area: " << this->areaName << endl;
    cout << "Financial status: " << this->financialStatus << endl;
    cout << "Data when disease started: " << this->dateOfDiseaseStart << endl;
    cout << endl;
}

void Patient::menu() {
    
    int choice;

    do {

        system("cls");
        
        display(); // first display patient's data

        cout << "1. Change your details" << endl;
        cout << "2. Apply for application" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";

        cin >> choice;

        switch (choice) {
            case 1:
                changeYourPresentConditions();
                break;
            case 2:
                applyForFundApplication();
                break;
            default:
                break;

        }

    } while (choice != 0);

}

void Patient::changeYourPresentConditions() {
    this->setData(false);
}

void Patient::applyForFundApplication() {

    cout << endl;
    
    if (strcmp(applicationStatus, "sent") == 0) {
        cout << "You already sent an application" << endl;
        cout << "Wait for response!" << endl;

    } else if (strcmp(applicationStatus, "approved") == 0) {
        cout << "Congratulations!" << endl;
        cout << "Your application is approved!" << endl;

    } else if (strcmp(applicationStatus, "postponed") == 0) {
        cout << "Your application is postponed" << endl;
        cout << "You have to wait!" << endl;

    } else if (strcmp(applicationStatus, "rejected") == 0) {
        cout << "Your application is rejected" << endl;
        cout << "We are sorry!" << endl;

    } else {
        strcpy(applicationStatus, "sent");
        cout << "Your application has been sent" << endl;
        cout << "Wait for process!" << endl;

    }
     
    system("pause");
    system("cls");
}
