#include <iostream>
#include <deque>
using namespace std;

void binaryRep(int a, deque<int>& rep)
{
  int last_bit = a % 2;
  rep.emplace_front(last_bit);
  if(a / 2 > 0)
  {
    binaryRep(a/2, rep);
  }
}

int main()
{
  int a = 22;
  deque<int> rep;
  binaryRep(a, rep);
  for(auto& r:rep)
  {
    cout << r;
  }
  cout << endl;
  return 0;
}