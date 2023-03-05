#include "list.h"

Node::Node(Patient patient) {
    this->patient = patient;
    next = NULL;
}

List::List() {
    head = current = NULL;
}

void List::add(Patient patient) {
    Node* newNode = new Node(patient);

    if (head == NULL) {
        head = newNode;
        current = head;
        return;
    }

    current->next = newNode;
    current = newNode;
}

void List::display() {
    Node* temp = head;

    while(temp != NULL) {
        temp->patient.display();
        temp = temp->next;
    }
}

Patient List::getPatientAtIndex(int index) {

    Node* temp = head;
  
    int count = 0;

    while (temp != NULL) {
        if (count == index)
            return (temp->patient);
            
        count++;
        temp = temp->next;
    }

    return current->patient;
}

void List::setPatientAtIndex(int index, Patient patientToSet) {

    Node* temp = head;
  
    int count = 0;

    while (temp != NULL) {
        if (count == index)
            temp->patient = patientToSet;

        count++;
        temp = temp->next;
    }

}

int List::size() {
    Node* temp = head;
    int _size = 0;

    if (head == NULL) {
        return _size;
    }

    while(temp != NULL) {
        _size += 1;
        temp = temp->next;
    }

    return _size;
}
