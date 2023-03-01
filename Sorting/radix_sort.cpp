#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

// Leetcode 912. Sort an Array

class Solution {
public:
  vector<int> sortArray(vector<int>& nums) {
    int d = 5, n = nums.size();
    vector<vector<int>> bucket(10, vector<int>());
    vector<int> tmp;
    vector<int> neg;
    for(auto& n:nums){
      if(n >= 0){
        tmp.emplace_back(n);
      }else{
        neg.emplace_back(n*(-1));
      }
    }
    // vector<int> tmp = nums;
    for(int i = 0; i < d; ++i){
      // distribute
      for(int j = 0; j < tmp.size(); ++j){
        int cur_bucket = tmp[j] % (int)pow(10, i+1);
        cur_bucket /= pow(10, i);
        bucket[cur_bucket].emplace_back(tmp[j]);
      }
      tmp.clear();
      // merge
      for(int i = 0; i < 10; ++i){
        if(bucket[i].size()!=0){
          for(int j = 0; j < bucket[i].size(); ++j){
            tmp.emplace_back(bucket[i][j]);
          }
        }
      }
      // clear bucket
      bucket.clear();
      bucket.resize(10, vector<int>());
    }

    for(int i = 0; i < d; ++i){
      // distribute
      for(int j = 0; j < neg.size(); ++j){
        int cur_bucket = neg[j] % (int)pow(10, i+1);
        cur_bucket /= pow(10, i);
        bucket[cur_bucket].emplace_back(neg[j]);
      }
      neg.clear();
      // merge
      for(int i = 0; i < 10; ++i){
        if(bucket[i].size()!=0){
          for(int j = 0; j < bucket[i].size(); ++j){
            neg.emplace_back(bucket[i][j]);
          }
        }
      }
      // clear bucket
      bucket.clear();
      bucket.resize(10, vector<int>());
    }
    reverse(neg.begin(), neg.end());
    for(auto& n:neg){
      n *= (-1);
    }
    for(auto& n:tmp){
      neg.emplace_back(n);
    }
    return neg;
  }
};