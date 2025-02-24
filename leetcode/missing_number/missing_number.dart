class Solution {
  int missingNumber(List<int> nums) {
    var n = nums.length;

    var expectedSum = (n * (n + 1)) / 2;
    var actualSum = nums.reduce((acc, curr) => (acc + curr).toInt());

    return (expectedSum - actualSum).toInt();
  }
}
