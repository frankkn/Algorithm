#include <iostream>
#include <vector>
using namespace std;

ostream& operator<< (ostream& out, vector<int> const& v)
{
    for(auto x : v){ out << x << " "; } 
    out << "\n";   
    return out;
}

void InsertionSort(vector<int>& A){
  for(auto it {next(A.begin())}; it != A.end(); ++it){
    for(auto rit {it}; rit != A.begin() && *rit < *prev(rit); --rit){
      swap(*rit, *prev(rit));
    }
  }
  return;
}

int main(){
  int n {};
  cin >> n;
  vector<int> A(n);
  for(auto& A_i : A){ cin >> A_i; }
  InsertionSort(A);
  cout << A;
}