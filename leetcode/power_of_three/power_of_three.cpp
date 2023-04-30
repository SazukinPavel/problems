class Solution {
public:
  bool isPowerOfThree(int n, long temp = 1) {
    if (temp == n) {
      return true;
    } else if (temp > n) {
      return false;
    }

    return isPowerOfThree(n, temp * 3);
  }
};