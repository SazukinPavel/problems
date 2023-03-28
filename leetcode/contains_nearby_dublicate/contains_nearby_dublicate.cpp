
// Given an integer array nums and an integer k, return true if there are two
// distinct indices i and j in the array such that nums[i] == nums[j] and abs(i
// - j) <= k.

// Why not just say something along the lines of "Find 2 numbers in the array
// that are equal and are at most k apart from each other."?

#include "iostream"
#include "map"
#include "vector"

using namespace std;

class Solution {
public:
  bool containsNearbyDuplicate(vector<int> &nums, int k) {
    map<int, int> existedMap;

    for (int i(0); i < nums.size(); i++) {
      if ((existedMap[nums[i]]) && i-(existedMap[nums[i]]-1)<=k)
        return true;
      existedMap[nums[i]] = i+1;
    }
    return false;
  }
};

int main() {
  Solution solution;
  vector<int> v1{1, 2, 3, 1};
  vector<int> v2{1, 0, 1, 1};
  vector<int> v3{1, 2, 3, 1, 2, 3};
  cout << " [1,2,3,1] k=3 "
       << (solution.containsNearbyDuplicate(v1, 3) ? "true" : "false") << "\n";
  cout << " [1, 0, 1, 1] k=1 "
       << (solution.containsNearbyDuplicate(v2, 1) ? "true" : "false") << "\n";
  cout << " [1, 2, 3, 1, 2, 3] k=2 "
       << (solution.containsNearbyDuplicate(v3, 2) ? "true" : "false") << "\n";
}