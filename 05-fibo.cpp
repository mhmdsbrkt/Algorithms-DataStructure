using namespace std;
#include <iostream>

int fibonacci(int input) {

    if ((input == 1) || (input == 2)) {
        return 1;
    }
    else {
        return fibonacci(input - 1) + fibonacci(input - 2);
    }
}

int main() {
    cout << fibonacci(10) << endl;
    return 0;

}
