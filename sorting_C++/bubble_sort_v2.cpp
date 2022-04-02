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
  for(auto last {prev(A.end())}; last != A.begin(); --last){
    auto isSwapped {false};
    for(auto it {A.begin()}; it != last; ++it){
      if(*next(it) < *it){
        swap(*next(it), *it);
        isSwapped = true;
      }
    }
    if(!isSwapped){ break; }
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