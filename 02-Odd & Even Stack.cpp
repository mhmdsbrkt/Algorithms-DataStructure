using namespace std;
#include <iostream>

// Class START HERE
class stack {

private:
    int *arr;
    int size;
    int top;
    
public:
    //Declare CONSTRICTOR Function with Parameter
     stack (int cSize) {
        size = cSize;
        top = 0;
        arr = new int(size);
    }
    // CONSTRICTOR Overloading to set default Value
    stack (void) {
        size = 10;
        top = 0;
        arr = new int[size];
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
};
// Class END HERE

// Main Function STARTED HERE
int main() {

    //create stack for even number with size = 6
    stack even(6);
    // create stack for odd number with default CONSTRICTOR
    stack odd;
    // create input variable to get data
    int input;

    // For loop STARTED HERE
    for (int counter = 0; counter <= 9; counter++)
    {
        // Get The Numbers from the users
        cout << "Enter " << counter + 1 << " number from 10 numbers: ";
        cin >> input;

        //Check if input is EVEN
        if (input % 2 == 0)	 {
            //Check Even Stack Is full ??
            if (even.isFull() == false)	even.push(input);
            else				cout << "Even stack is full\n";
        }
            
        //Check if input is ODD
        else			{
            //Check Odd Stack Is full ??
            if (odd.isFull() == false)	odd.push(input);
            else				cout << "Odd stack is full\n";
        }
    } 
    // FOR LOOP END HERE

    // Print Even Stack data
    cout << "Even numbers are " << even.getTop() << " numbers: \n";
    while (even.isEmpty() == false)    cout << even.pop() << "\t";

    // Print Odd Stack data
    cout << "\nOdd numbers are " << odd.getTop() << " numbers: \n";
    while (odd.isEmpty() == false)    cout << odd.pop() << "\t";

    return 0;
}
