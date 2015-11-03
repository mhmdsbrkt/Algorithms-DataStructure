#include <iostream>

using namespace std;

class stack {
private:
    int *arr;
    int size;
    int top;

public:
    // Constructor
    stack() { }

    //Declare CREATE Function
    int create(int cSize) {
        size = cSize;
        top = 0;
        arr = new int(size);
    }

// CREATE Overloading to set default Value 3
    int create(void) {
        size = 3;
        top = 0;
        arr = new int[size];
    }

// Increase Stack size
    void doubleSize() {
        int *arr2;
        arr2 = new int[size * 2];
        for (int k = 0; k < size; k++) {
            arr2[k] = arr[k];
        }
        arr2 = arr;
        size = size * 2;
    }

// Declare PUSH function
    void push(int data) {
        arr[top] = data;
        top++;
    }

// Declare POP function
    int pop() {
        top--;
        return arr[top];

    }

// Declare IS FULL function
    bool isFull() {
        // Check if Top = Size Stack is Full
        if (top >= size) {
            return true;
        } else {
            return false;
        }

    }

// Declare IS EMPTY function
    bool isEmpty() {
        // Check if Top = 0 so Stack is Empty
        if (top <= 0) {
            return true;
        } else {
            return false;
        }

    }

// Declare GET TOP Function
    int getTop() {
        return top;
    }

// Declare Peak Function
    int peak() {
        return arr[top];
    }

//Declare CLEAR Function
    void clear() {
        top = 0;
    }

    int getSize() {
        return size;
    }

};

int main() {

    int input;
    int counter = 0;

    // Create new object with default constructor
    stack positive;
    stack negative;

    positive.create(3);
    negative.create(3);

    // Get data form the user accept any numbers EXCEPT ZERO
    do {

        cout << "Enter " << ++counter << " Number" << endl;
        cin >> input;

        // Check if input is POSITIVE
        if (input > 0) {
            // Check if stack IS FULL ???
            if (positive.isFull() == false) {
                // PUSH data to Positive stack
                positive.push(input);
            }
            else {
                // Increase stack Size then push data
                positive.doubleSize();
                positive.push(input);
            }
        }
            // Check if input is NEGATIVE
        else if (input < 0) {
            // Check if stack IS FULL ???
            if (negative.isFull() == false) {
                // PUSH data to negative Stack
                negative.push(input);
            }
            else {
                // Increase stack Size then push data
                negative.doubleSize();
                negative.push(input);
            }
        }

    } while (input != 0);

    // Print Positive Numbers
    cout << "\nNegative Numbers are " << positive.getTop() << endl;
    cout << "The Size of Positive Stack " << positive.getSize() << endl;
    while (positive.isEmpty() == false) {

        cout << positive.pop() << "\t";
    }

    // Print Negative Numbers
    cout << "\nNegative Numbers are " << negative.getTop() << endl;
    cout << "The Size of Negative Stack " << negative.getSize() << endl;

    while (negative.isEmpty() == false) {
        cout << negative.pop() << "\t";
    }


    return 0;
}
