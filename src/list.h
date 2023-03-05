#pragma once
#include <iostream>
#include "patient.h"
using namespace std;

class Node {
     public:
        Patient patient;
        Node* next;

        Node(Patient patient);
};


class List {
    private:
        Node* head;
        Node* current;

    public:
        List();
        void add(Patient patient);
        void display();
        Patient getPatientAtIndex(int index); // return patient at that index
        void setPatientAtIndex(int index, Patient patientToSet); // return patient at that index
        int size();
};
