using namespace std;

#include <iostream>

// Define Functions 

void read_data(int *, int);

int linear_search(int *, int, int);

int binary_search(int *, int, int);

// Main Functions Started here
int main() {

    // Declare Variables
    int *arrayPtr;
    int size;
    int result;
    int key;

    // Get Array Size from the user
    cout << "Enter Array Size: " << endl;
    cin >> size;

    // Set Array size
    arrayPtr = new int[size];

    //Get Key from the user
    cout << "Enter Key To Search: " << endl;
    cin >> key;

    // Linear search STARTED HERE
    cout << "\tLinear Search STARTED HERE" << endl;
    cout << "Enter Array Data " << endl;
    // Get array Data From the user
    read_data(arrayPtr, size);

    // Linear Search Function
    result = linear_search(arrayPtr, size, key);

    // Check Result
    if (result < 0) {
        cout << "Number not found\n";
    }
    else {
        cout << "Number " << key << " is found at location " << result + 1 << endl;
    }

    cout << "\tLinear Search Ended" << endl;
    // Linear search ENDED HERE

    // Binary Search STARTED HERE
    cout << "Binary Search" << endl;
    cout << "Enter Array Data in SORTED manner" << endl;

    // Get array Data From the user
    read_data(arrayPtr, size);

    // Binary Search STARTED HERE
    result = binary_search(arrayPtr, size, key);

    // Check Result
    if (result < 0) {
        cout << "Number not found"<<endl;
    }
    else {
        cout << "Number " << key << " is found at location " << result + 1 << endl;
    }
    cout << "\tBinary Search Ended" << endl;
    // Binary search ENDED HERE

    return 0;
}
// Main Functions Ended here

void read_data(int *arr, int size) {

    // Get array data from the user
    for (int counter = 0; counter < size; counter++) {
        cout << "Enter number " << counter + 1 << " from " << size << " numbers:";
        cin >> arr[counter];
    }
}

int linear_search(int *arr, int size, int key) {

    for (int counter = 0; counter < size; counter++) {

        if (arr[counter] == key) {
            return counter;
        }
    }
    return -1;

}

int binary_search(int *arr, int size, int key) {

    // Declare Variables
    int first;
    int last;
    int mid;

    // Declare First Value from 0
    first = 0;

    // Declare last Value = size-1
    last = size - 1;


    while (first <= last) {

        // Declare Medium Value = (first + last)/2
        mid = (first + last) / 2;
        // Compare Key by Medium Value if equal return mid "best Scenario"
        if (key == arr[mid]) {
            return mid;
        }
            // if Key > Medium Value set first value as medium value +1
        else if (key > arr[mid]) {
            first = mid + 1;
        }
            // The last case where Key < Medium Value so set last value as medium value -1
        else {
            last = mid - 1;
        }

    }
    return -1;
}
