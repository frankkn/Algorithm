#include <iostream>
using namespace std;

int gcd(int a, int b)
{
  if(b == 0)  return a;
  else
  {
    return gcd(b, a % b);
  }
}

int main()
{
  int a = 14, b = 28;
  cout << gcd(a, b) << endl;
  return 0;
}