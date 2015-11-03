using namespace std;

#include <iostream>

/***************  Queue  ********************/
// First In Fist Out    FIFO
// Last In Last Out	LOLO

// enqueue , dequeue , isfull , isempty , create , get_count , get_front , clear,

class queue {
    int *ptrQueue;
    int size;
    int first;
    int last;
    int counter;
public:
    // Constructor
    queue(int queueSize) {
        size = queueSize;
        first = last = counter = 0;
        ptrQueue = new int[size];
    }
    // Constructor with default size 10
    queue(void) {
        size = 10;
        first = last = counter = 0;
        ptrQueue = new int[size];
    }

    // ENQUEUE Function: Insert Data into the Queue
    void enqueue(int data) {
        counter++;
        ptrQueue[last] = data;
        last = (last + 1) % size;
    }
    // Dequeue Function: Get Data From the Queue
    int dequeue(void) {
        int temp;
        temp = ptrQueue[first];
        counter--;
        first = (first + 1) % size;
        return temp;
    }

    bool isfull(void) {
        if (counter == size) return true;
        else return false;
    }

    bool isempty(void) {
        if (counter == 0) return true;
        else return false;
    }

    int get_count(void) {
        return counter;
    }

    int get_front(void) {
        return ptrQueue[first];
    }

    void clear(void) {
        first = last = counter = 0;
    }

    void double_size() {
        int *ptrDoubledQueue;
        ptrDoubledQueue = new int[size * 2];
        int nFirst = first;
        for (int index = 0; index < size; index++){
            ptrDoubledQueue[index] = ptrQueue[nFirst];
            nFirst=(nFirst+1)%size;
        }

        ptrQueue= ptrDoubledQueue;
        first=0;
        last=counter;
        size = size * 2;
    }

    int get_size(void) {
        return size;
    }
};

int main() {
    queue myque(6);

    int input;

    for (input = 1; input <= 4; input++) {
        if (myque.isfull() == false) {
            myque.enqueue(input * input);
        }
    }


    while (myque.isempty() == false) {
        cout << myque.dequeue() << "\t";
    }

    cout << endl;
    for (input = 10; input <= 20; input++) {
        if (myque.isfull() == true) myque.double_size();
            myque.enqueue(input * input);

    }


    while (myque.isempty() == false) {
        cout << myque.dequeue() << "\t";

    }
    return 0;
}
