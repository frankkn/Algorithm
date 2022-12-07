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
  int len = A.size();
  for(int i = 0; i < len-1; i++){
    int min_index = i;
    for(int j = i+1; j < len; j++){
      if(A[j] <= A[min_index]){
        min_index = j;
      }
    }
    swap(A[i],A[min_index]);
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