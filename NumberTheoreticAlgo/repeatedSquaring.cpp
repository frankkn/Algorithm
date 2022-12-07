#include <iostream>
#include <deque>
using namespace std;

// return x ^ a
int RS(int x, int a) {
  int s = 1;

  while(a > 0) {
    if(a % 2) {
      s = s * x;
    }
    x = x * x;
    a = a / 2;
  }
  return s;
}

int main() {
  cout << RS(2,3) << endl;
  return 0;
}