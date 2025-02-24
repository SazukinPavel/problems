class Solution {
  bool containsDuplicate(List<int> nums) {
    var existed = Map<int, bool>();

    for (var num in nums) {
      if (existed.containsKey(num)) {
        return true;
      }

      existed[num] = true;
    }

    return false;
  }
}
