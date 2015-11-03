#include <iostream>

using namespace std;

class queue {
private:
    int *pIntQueue;
    int size;
    int first;
    int last;
    int counter;

public:
    // CONSTRUCTOR
    queue(int queSize) {
        size = queSize;
        first = last = counter = 0;
        pIntQueue = new int[size];
    }

    // CONSTRUCTOR With default value 10
    queue(void) {
        size = 10;
        first = last = counter = 0;
        pIntQueue = new int[size];
    }

    // ENEQUE
    void enqueue(int data) {
        counter++;
        pIntQueue[last] = data;
        last = (last + 1) % size;
    }

    // DEQUE
    int deque(void) {
        int temp = pIntQueue[first];
        counter--;
        first = (first + 1) % size;
        return temp;

    }

    // IS FULL
    bool isFull(void) {
        if (counter == size) return true;
        else return false;

    }

    // IS Empty
    bool isEmpty(void) {
        if (counter == 0) return true;
        else return false;
    }

    // GET Counter
    bool getCount(void) {
        return counter;
    }

    // Get Front
    int getFront(void) {
        return pIntQueue[first];

    }

    // CLEAR
    void clear(void) {
        first = last = counter = 0;
    }

};

int main() {

    queue myque(6);

    int input;

    for (input = 1; input <= 4; input++) {
        if (myque.isFull() == false) {
            myque.enqueue(input * input);
        }
    }


    while (myque.isEmpty() == false) {
        cout << myque.deque() << "\t";
    }


    for (input = 10; input <= 20; input++) {
        if (myque.isFull() == false) {
            myque.enqueue(input * input);
        }
    }


    while (myque.isEmpty() == false) {
        cout << myque.deque() << "\t";

    }
    return 0;


}
