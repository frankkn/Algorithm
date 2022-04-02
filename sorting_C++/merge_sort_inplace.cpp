#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using It = vector<int>::iterator;

ostream& operator<< (ostream& out, vector<int> const& v)
{
    for(auto x : v){ out << x << " "; } 
    out << "\n";   
    return out;
}

void MergeSort(It left,It right)
{
  int size = distance(left,right);
  if(size > 1)
  {
    It middle = next(left, size/2);
    MergeSort(left, middle);
    MergeSort(middle, right);
    inplace_merge(left, middle, right);
  }
  return;
}

int main(){
  int n {};
  cin >> n;
  vector<int> A(n);
  for(auto& A_i : A){ cin >> A_i; }
  MergeSort(A.begin(), A.end());
  cout << A;
  return 0;
}