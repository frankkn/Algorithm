#include <iostream>
#include <vector>
using namespace std;

ostream& operator<< (ostream& out, vector<int> const& v)
{
    for(auto x : v){ out << x << " "; } 
    out << "\n";   
    return out;
}

void BubbleSort(vector<int>& A){
  int len = A.size();
  bool isSwapped = 0;
  for(int i = 0; i < len-1; i++){
    for(int j = 0; j < len-i; j++){
      if(j < len-1 && A[j+1] < A[j]){
        swap(A[j+1], A[j]);
        isSwapped = 1;
      }
    }
    if(!isSwapped){
      return;
    }
  }
  return;
}

int main(){
  int n {};
  cin >> n;
  vector<int> A(n);
  for(auto& A_i : A){ cin >> A_i; }
  BubbleSort(A);
  cout << A;
}