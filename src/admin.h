#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include "user.h"
#include "patient.h"
#include "list.h"
#include "queue.h"
#include "area.h"
using namespace std;

class Admin {
    private:
        string name;
        string password;
        Patient patient;
        List list;
    
    public:
        Admin();
        void login();
        void menu();
        void readPatientsToList();
        void viewAllPatients();
        void viewPatientsApplication();
        void viewAreas();
        void searchPatient();
        void sortPatients();
};

void proceedPatientsApplication(Patient p);
