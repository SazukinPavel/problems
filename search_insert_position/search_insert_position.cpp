// Given a sorted array of distinct integers and a target value, return the
// index if the target is found. If not, return the index where it would be if
// it were inserted in order.
//
// You must write an algorithm with O(log n) runtime complexity.
#include "iostream"
#include "vector"
#include <cmath>
#include <vector>

using namespace std;

class Solution {
public:
  int searchInsert(vector<int> &nums, int target) {
    if (nums.size() == 0 || nums[0] > target) {
      return 0;
    } else if (nums[nums.size() - 1] < target) {
      return nums.size();
    }

    int index = nums.size() / 2;

    while (true) {
      if (nums.size() == index || index == 0 || nums[index] == target ||
          (nums[index] > target && nums[index - 1] < target)) {
        break;
      } else if (target > nums[index]) {
        index += (nums.size() - index) / 2;
      } else {
        index -= ceil((nums.size() - index) / 2);
      }
    }
    return index == nums.size() - 1 && nums[index] < target ? index + 1 : index;
  }
};

int main() {
  Solution solution;
  vector<int> v1{1, 3, 5, 6};
  cout << solution.searchInsert(v1, 5) << "\n";
  cout << solution.searchInsert(v1, 2) << "\n";
  cout << solution.searchInsert(v1, 7) << "\n";
}