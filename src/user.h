#pragma once
#include <iostream>
#include <fstream>
#include "patient.h"
#include "list.h"

using namespace std;

class User {
    public:
        void menu();
        Patient login(bool &returnFromLogin); // return patient if found in file
        Patient addYourselfAsPatient();
        void insertInFile(Patient patient);
};

void modifyPatient(Patient patient);
