#include <iostream>
using namespace std;

void print(int n) {

    if (n <= 100) {
        cout << n << endl;
        print(n + 1);
    }

}

int main() {
    int num;
    cout << "enter the number: ";
    cin >> num;
    print(num);
    return 0;
}
