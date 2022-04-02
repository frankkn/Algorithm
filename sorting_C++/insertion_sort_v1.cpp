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
  int len = A.size();
  for(int i = 1; i < len; i++){
    int j = i;
    while(j >= 1 && A[j] < A[j-1]){
      swap(A[j], A[j-1]);
      j--;
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