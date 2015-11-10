using namespace std;
#include <iostream>

int fibo(int input){

	if ((input == 1) || (input == 2)) { return 1; }
	else { return fibo(input - 1) + fibo(input - 2); }
}
int main()
{
	cout << fibo(10) << endl;
	return 0;

}

