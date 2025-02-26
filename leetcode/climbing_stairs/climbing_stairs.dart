class Solution {
  int climbStairs(int n) {
    if (n == 1) {
      return 1;
    }
    var n1 = 1;
    var n2 = 2;

    for (var i = 3; i < n + 1; i++) {
      var temp = n2;
      n2 = n1 + n2;
      n1 = temp;
    }

    return n2;
  }
}
