using namespace std;

#include <iostream>

// ########### Simulate a queue using linked list  ##################
// enque , deque , get_front , is_empty , get_size 

struct person {
    int id;
    struct person *next;
};

class Linked_queue {
private:
    person *front, *rear;
    int counter;

public:
    Linked_queue() {
        front = NULL;
        rear = NULL;
        counter = 0;
    }

    void enque(int num) {
        person *temp;
        temp = new person;
        temp->id = num;
        if (rear == NULL) {
            rear = temp;
            front = temp;
        }
        else {
            rear->next = temp;
            rear = rear->next;
        }
        temp->next = NULL;
        counter++;
    }

    int deque(void) {
        int num;
        person *temp;
        temp = front;
        num = front->id;
        front = front->next;
        delete temp;
        counter--;
        return num;
    }

    int get_size(void) {
        return counter;
    }

    bool is_empty(void) {
        if (counter == 0) return true;
        else return false;
    }

    int get_front(void) {
        return front->id;
    }
};

int main(void) {
    int k;
    Linked_queue odd, even;
    for (k = 1; k <= 10; k++)
        if (k % 2 == 0) even.enque(k);
        else odd.enque(k);

    cout << "front of even " << even.get_front() << endl;

    cout << "Odd numbers: ";
    while (odd.is_empty() == false) cout << odd.deque() << "\t";

    cout << "\n Even numbers: ";
    while (even.is_empty() == false) cout << even.deque() << "\t";
}
