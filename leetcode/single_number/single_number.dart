class Solution {
  int singleNumber(List<int> nums) {
    var mask = 0;

    for (var num in nums) {
      print('$mask $num ${mask ^ num}');
      mask = mask ^ num;
    }

    return mask;
  }
}

void main(List<String> args) {
  print(Solution().singleNumber([4, 1, 2, 1, 2]));
}
