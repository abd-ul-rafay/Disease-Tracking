#include "admin.h"

Admin::Admin() { // constructor
    name = "Admin";
    password = "ad";
}

void Admin::login() {

    system("cls");
    cout << "W e l c o m e   t o   T h e   S y s t e m " << endl << endl;
        
    // here we will input password with actual password

    string inputPassword;
    cout << "To login, ";

    do {

        cout << "Enter password: ";
        cin >> inputPassword;

        if (inputPassword == this->password) {
            system("cls");
            cout << "Logged in successfully" << endl;
        } else {
            system("cls");
            cout << "Incorrect password, try again" << endl;
        }
        
    } while (inputPassword != this->password);

    menu(); // After logging, show menu to admin
}

void Admin::menu() {

    char ch[1];
    int choice;

    do {

        cout << endl;
        cout << "1. View all Patients" << endl;
        cout << "2. View Patients Fund Application" << endl;
        cout << "3. View Areas and related patients" << endl;
        cout << "4. Search any patient" << endl;
        cout << "5. Sort patients name alphabetically" << endl;
        cout << "0. Exit" << endl;
    
        cout << "Enter your choice: ";
        cin >> ch;

        choice = atoi(ch);

        switch (choice) {
            case 1:
                viewAllPatients();
                break;
            case 2:
                viewPatientsApplication();
                break;
            case 3:
                viewAreas();
                break;
            case 4:
                searchPatient();
                break;
            case 5:
                sortPatients();
                break;
            default:
                system("cls");
                cout << "Invalid key entered" << endl;
                break;
        }

    } while (choice != 0);
}

void Admin::readPatientsToList() {

    if (list.size() > 0) {
        // means list already contains patient
        // don't read now
        return;
    }

    string PATIENTS_FILE_PATH = "Database/Patient.bin";
    fstream file;

    file.open(PATIENTS_FILE_PATH, ios::binary | ios::in);

    if (!file.is_open()) {
        cout << endl << "Patient file not opened!" << endl;
    }

    else { 

        while(file.read(((char *)&(patient)), sizeof(patient))) {
            list.add(patient);
        }

        file.close();
    }
}

void Admin::viewAllPatients() {

    system("cls");

    readPatientsToList();

    cout << "Displaying all Patients" << endl
        << endl;

    if (list.size() == 0) {
        cout << "No Patient in file" << endl;
    } else {
        list.display();
    }
    
    system("pause");
    system("cls");
}

void Admin::viewPatientsApplication() {

    system("cls");

    readPatientsToList(); 

    Queue queue;

    for (int i = 0; i < list.size(); i++) {  
        if (list.getPatientAtIndex(i).getApplicationStatus() == "sent" || list.getPatientAtIndex(i).getApplicationStatus() == "postponed") {
            queue.enQueue(list.getPatientAtIndex(i));
        }
    }
    

    up: // used as goto label
    
    system("cls");
    cout << "Showing first patient in queue" << endl << endl;

    if (queue.isEmpty())
        cout << "No Patient for application" << endl;

    else {

        Patient p = queue.qFront();
        p.display();

        // asking admin for approved, postponed, rejected...
        proceedPatientsApplication(p);
        queue.deQueue();

        if (!queue.isEmpty()) {
            goto up;
        }
    }
}

void Admin::viewAreas() {
    
    // As we have 11 common areas, we will make 11 objects of Area class / Array of objects
    Area areas[11] = {Area("Karachi"), 
                      Area("Lahore"), 
                      Area("Islamabad"), 
                      Area("Multan"), 
                      Area("Peshawar"), 
                      Area("Quetta"), 
                      Area("Faisalabad"), 
                      Area("Gujranwala"), 
                      Area("Rawalpindi"), 
                      Area("Sialkot"), 
                      Area("Others")};

    
    system("cls");

    readPatientsToList();

    for (int i = 0; i < 11; i++) {

        for (int j = 0; j < list.size(); j++) {
            
            if (areas[i].getName() == list.getPatientAtIndex(j).getAreaName()) {
                areas[i].insertPatientInArea(list.getPatientAtIndex(j));
            }
        }
    }

    for (int i = 0; i < 11; i++) {
        if (areas[i].getList().size() > 0) {
            // means if area contain patient, then print
            areas[i].display();
        }
    }

    system("pause");
    system("cls");

}

void Admin::searchPatient() {

    readPatientsToList();

    system("cls");

    string nameToSearch;

    cout << endl;
    cout << "Enter Patient name to search: ";
    cin >> nameToSearch;

    bool isFound = false;

    cout << endl <<  "These are matching patients" << endl << endl;

    // linear search algorithm

    for (int i = 0; i < list.size(); i++) {
        
        if (list.getPatientAtIndex(i).getName().find(nameToSearch) != std::string::npos) { 

            isFound = true;
            list.getPatientAtIndex(i).display();
        }
    }

    if (!isFound) {
        cout << "No patient found" << endl << endl;
    }
    
    system("pause");
    system("cls");
}

void Admin::sortPatients() {

    // using bubble sort algorithm

    for (int i = 0; i < list.size(); i++) {
        
        for (int j = 0; j < (list.size() - 1 - i); j++) {
            
            if (list.getPatientAtIndex(j).getName().compare(list.getPatientAtIndex(j + 1).getName()) > 0) {

                // now swap using list get & set functions
                Patient temp = list.getPatientAtIndex(j);
                list.setPatientAtIndex(j, list.getPatientAtIndex(j + 1));
                list.setPatientAtIndex(j + 1, temp);
            }
        }
    }

    cout << "Patients name sorted alphabetically" << endl;
    
    system("pause");
    system("cls");
}

void proceedPatientsApplication(Patient patient) {

    int choice;
    while (choice != 1 && choice != 2 && choice != 3) {

        // approved, postponed, rejected
        cout << "1. For Approving Application" << endl;
        cout << "2. For postponing Application" << endl;
        cout << "3. For rejecting Application" << endl;
        cout << "Your choice" << endl;

        cin >> choice;

        switch (choice) {
            case 1:
                patient.setApplicationStatus("approved");
                break;
            case 2:
                patient.setApplicationStatus("postponed");
                break;
            case 3:
                patient.setApplicationStatus("rejected");
                break;
            default:
                break;
        }
    }

    system("cls");

    // Now after changing application status, we also have to make changes in file
    modifyPatient(patient);
}
