using namespace std;
#include <iostream>
/* Prints numbers from 1 to n */
void printNos(unsigned int n)
{
  if(n > 0)
  {
    printNos(n-1);
    printf("%d ",  n);
  }
  return;
}

/* Driver program to test printNos */
int main()
{
  printNos(100);
  getchar();
  return 0;
}
