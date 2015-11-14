using namespace std;
#include <iostream>

void printNumbers(int n) {
    if(n > 0) {
        printNumbers(n - 1);
      cout << n<<"\t";
    }
    return;
}

int main() {
    printNumbers(100);
    return 0;
}
