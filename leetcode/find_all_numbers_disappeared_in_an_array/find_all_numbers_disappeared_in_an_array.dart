class Solution {
  List<int> findDisappearedNumbers(List<int> nums) {
    var missed = List<int>.empty(growable: true);

    var i = 0;
    while (i < nums.length) {
      var position = nums[i] - 1;

      if (nums[i] != nums[position]) {
        var temp = nums[i];
        nums[i] = nums[position];
        nums[position] = temp;
      } else {
        i++;
      }
    }

    for (var i = 0; i < nums.length; i++) {
      if (nums[i] != i + 1) {
        missed.add(i + 1);
      }
    }

    return missed;
  }
}
