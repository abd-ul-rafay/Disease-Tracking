#include "queue.h"

QNode::QNode(Patient patient) {
    this->patient = patient;
    next = NULL;
}

Queue::Queue() { front = rear = NULL; }
 
void Queue::enQueue(Patient patient) {

    QNode* temp = new QNode(patient);

    if (rear == NULL) {
        front = rear = temp;
        return;
    }

    rear->next = temp;
    rear = temp;
}
 
void Queue::deQueue() {
    // If queue is empty, return NULL.
    if (isEmpty()) {
        return;
    }

    QNode* temp = front;
    front = front->next;

    if (front == NULL) {
        rear = NULL;
    }

    delete (temp);
}

Patient Queue::qFront() {
    return front->patient;
}

bool Queue::isEmpty() {
    if (front == NULL)
        return true;
    return false;
}
