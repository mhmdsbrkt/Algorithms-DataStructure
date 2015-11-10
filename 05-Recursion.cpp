using namespace std;
#include <iostream>

int factorial (int);

int main (){
int n, res;
cout << "Enter Value Of N";
cin >> n;
res = factorial(n);
cout << "Factorial "<< res << endl;
}

int factorial(int n)
{
    if(n==0) return 1;
    else return n*factorial(n-1);
}
