using namespace std;
#include <iostream>

int factorial (int);

int main (){
    int input, result;
    cout << "Enter Value Of N ";
    cin >> input;
    result = factorial(input);
    cout << "Factorial of " << input << " = " << result << endl;
    return 0;
}

int factorial(int input){
    if(input == 0) return 1;
    else return input * factorial(input - 1);

}
