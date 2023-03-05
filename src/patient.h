#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
using namespace std;

class Patient {
    private:
        char name[20];
        char password[20];
        char gender[10];
        int age;
        char cnic[20];
        char diseaseName[20];
        char areaName[20];
        char financialStatus[20];
        char applicationStatus[10]; // notSend, sent, approved, postponed, rejected
        char dateOfDiseaseStart[20];
    
    public:
        Patient();
        void setData(bool changeAllData);
        void setApplicationStatus(string newStatus); // changes by admin
        string getName();
        string getPassword();
        string getCnic();
        string getAreaName();
        string getApplicationStatus();
        void display();
        void menu();
        void changeYourPresentConditions();
        void applyForFundApplication();

};
