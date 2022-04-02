#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

ostream& operator<< (ostream& out, vector<int> const& v)
{
    for(auto x : v){ out << x << " "; } 
    out << "\n";   
    return out;
}

void SelectionSort(vector<int>& A){
  for(auto it {A.begin()}; it != A.end(); ++it){
    swap(*it, *min_element(it, A.end()));
  }
  return;
}

int main(){
  int n {};
  cin >> n;
  vector<int> A(n);
  for(auto& A_i : A){ cin >> A_i; }
  SelectionSort(A);
  cout << A;
}