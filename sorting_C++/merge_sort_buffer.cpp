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

void MergeSort(It left,It right, It buffer_left, It buffer_right)
{
  int size = distance(left,right);
  if(size > 1)
  {
    It middle = next(left, size/2);
    It buffer_middle = next(buffer_left, size/2);
    MergeSort(left, middle, buffer_left, buffer_middle);
    MergeSort(middle, right, buffer_middle, buffer_right);
    merge(left, middle, middle, right, buffer_left);
    copy(buffer_left, buffer_right, left);
  }
  return;
}

int main(){
  int n {};
  cin >> n;
  vector<int> A(n);
  for(auto& A_i : A){ cin >> A_i; }
  vector<int> B(n);
  MergeSort(A.begin(), A.end(), B.begin(), B.end());
  cout << A;
  return 0;
}