#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int partition(vector<int>& nums, int p, int r){
    int pivot = nums[r];
    int i = p-1, j = p;
    while(j < r){
      if(nums[j] < pivot){
        i++;
        swap(nums[i], nums[j]);
      }
      j++;
    }
    swap(nums[i+1], nums[r]);
    return i+1;
  }

  void quick_sort(vector<int>& nums, int p, int r){
    if(p < r){
      int q = partition(nums, p, r);
      quick_sort(nums, p, q-1);
      quick_sort(nums, q+1, r);
    }
  }

  vector<int> sortArray(vector<int>& nums) {
    quick_sort(nums, 0, nums.size()-1);
    return nums;
  }
};