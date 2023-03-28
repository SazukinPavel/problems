// Given an integer array nums, return true if any value appears at least twice
// in the array, and return false if every element is distinct.

#include "iostream"
#include "map"
#include "vector"
#include <vector>

using namespace std;

class Solution {
public:
  bool containsDuplicate(vector<int> &nums) {
    map<int, bool> existedMap;

    for (int i(0); i < nums.size(); i++) {
      if (existedMap[nums[i]])
        return true;
      existedMap[nums[i]] = true;
    }
    return false;
  }
};

int main() {
  Solution solution;
  vector<int> v1{1, 2, 3, 1};
  vector<int> v2{1, 2, 3, 4};
  vector<int> v3{1, 1, 1, 3, 3, 4, 3, 2, 4, 2};
  cout << " [1,2,3,1] " << (solution.containsDuplicate(v1) ? "true" : "false")
       << "\n";
  cout << " [1,2,3,4] " << (solution.containsDuplicate(v2) ? "true" : "false")
       << "\n";
  cout << " [1,1,1,3,3,4,3,2,4,2] "
       << (solution.containsDuplicate(v3) ? "true" : "false") << "\n";
}