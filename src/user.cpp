#include "user.h"

void User::menu() {

    char ch[1];
    int choice;
    
    do {

        system("cls");

        cout << "W e l c o m e   t o   T h e   S y s t e m " << endl << endl;

        cout << "1. Login as patient" << endl;
        cout << "2. Add yourself as a Patient or disease affected" << endl;
        cout << "0. Exit" << endl;
        
        cout << "Enter your choice: ";
        cin >> ch;
        choice = atoi(ch);

        switch (choice) {
            case 1: 
                {
                    bool returnFromLogin = false;
                    Patient p = login(returnFromLogin);

                    if (!returnFromLogin) {
                        p.menu();
                        modifyPatient(p);
                    }
                    break;
                }

            case 2: 
                {
                    Patient p = addYourselfAsPatient();
                    p.menu();
                    modifyPatient(p);
                    break;
                }

            case 3: 
                break;

            case 0:
                break;
                
            default: 
                system("cls");
                cout << "Invalid Key" << endl;
                break;
        }

    } while (choice != 0);
    
}

Patient User::login(bool &returnFromLogin) {

    system("cls");
    cout << "W e l c o m e   t o   T h e   S y s t e m " << endl << endl;

    Patient patient;
    string name = "", password = "";
    bool found = false; // if we found similar name & password, will make it true

    do {

        cin.ignore();

        cout << "Enter your name (-1 to exit): ";
        getline(cin, name);

        if (name == "-1") {
            returnFromLogin = true;
            return patient;
        }

        /* else */

        cout << "Enter your password: ";
        getline(cin, password);

        
        string PATIENTS_FILE_PATH = "Database/Patient.bin";
        fstream file;

        file.open(PATIENTS_FILE_PATH, ios::binary | ios::in);

        if (!file.is_open()) {
            cout << endl << "Patient file not opened!" << endl;
            system("pause");
            returnFromLogin = true;
            return patient;
        }

        else {

            while(file.read(((char *)&(patient)), sizeof(patient))) {
                if (name == patient.getName() && password == patient.getPassword()) {
                    found = true;
                    break;
                }
            }

            file.close();
        }

        if (found) {
            cout << "Logged in successfully" << endl << endl;
        } 
        else {
            cout << "Invalid username or password" << endl;
            cout << "Try Again" << endl;
        }

    } while (!found);

    return patient;
}

Patient User::addYourselfAsPatient() {
    
    system("cls");
    cout << "W e l c o m e   t o   T h e   S y s t e m " << endl << endl;

    cout << "Now you have to give us details as a patient" << endl;
    
    Patient patient;
    patient.setData(true);

    insertInFile(patient);
    return patient;
}

void User::insertInFile(Patient patient) {

    string PATIENTS_FILE_PATH = "Database/Patient.bin";

    fstream file;
    file.open(PATIENTS_FILE_PATH, ios::binary | ios::out | ios::app);

    if (!file.is_open()) {
        file.open(PATIENTS_FILE_PATH, ios::binary | ios::out | ios::trunc);

        if (!file.is_open()) {
            cout << endl << "Patient file not opened!" << endl;
        }
    }

    else {
        file.write(((char *) &(patient)), sizeof(patient));

        system("cls");
        cout << "Added successfully" << endl;

        file.close();
    }
}


void modifyPatient(Patient patient) {

    string PATIENTS_FILE_PATH = "Database/Patient.bin";
    fstream file;

    file.open(PATIENTS_FILE_PATH, ios::binary | ios::in | ios::out);

    if (!file.is_open()) {
        cout << "Patient file not opened!" << endl;
    }

    else {

        Patient p;

        while (file.read((char *)&(p), sizeof(p))) {
            if(p.getCnic() == patient.getCnic()) {
            
                file.seekp(int(file.tellg()) - sizeof(patient), ios::beg);
                file.write((char *)&(patient), sizeof(patient));

                break;
            }
        }

        file.close();
    }

}

