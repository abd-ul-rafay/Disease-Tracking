#pragma once
#include <iostream>
#include "list.h"
using namespace std;

// to show all areas and related details

class Area {
    private:
        string name;
        List patientInArea; // in this area
        int noOfAffecties;

    public:
        Area(string name);
        void insertPatientInArea(Patient patient);
        string getName();
        List getList();
        void display();
    
};
