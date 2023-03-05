#pragma once
#include <iostream>
#include "patient.h"
using namespace std;

struct QNode {
    
    Patient patient;
    QNode* next;

    QNode(Patient patient);
};

class Queue {

    private:
        QNode *front, *rear;

    public:
        Queue();
    
        void enQueue(Patient patient);
        void deQueue();
        Patient qFront();
        bool isEmpty();
};
