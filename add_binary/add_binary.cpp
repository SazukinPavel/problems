// Given two binary strings a and b, return their sum as a binary string.

#include <algorithm>
#include <iostream>
#include <map>
#include <math.h>
#include <string>
using std::cout;
using std::string;

class Solution {
public:
  string addBinary(string a, string b) {
    string result("");

    int i = a.length() - 1;
    int j = b.length() - 1;
    bool remainder = 0;

    while (!(i < 0 && j < 0)) {
      int tempA = 0;
      int tempB = 0;
      if (i >= 0) {
        tempA = char_to_int(a[i]);
      }
      if (j >= 0) {
        tempB = char_to_int(b[j]);
      }

      int sum = tempA + tempB + (int)remainder;
      if (sum >= 2) {
        remainder = true;
        sum -= 2;
      } else {
        remainder = false;
      }
      result += sum > 0 ? '1' : '0';
      i--;
      j--;
    }
    if (remainder) {
      result += '1';
    }
    reverse(result.begin(), result.end());

    return result;
  }

private:
  int char_to_int(char c) { return c - '0'; }
};

int main() {
  Solution *solution = new Solution();
  cout << solution->addBinary("0", "0") << "\n";
      cout << solution->addBinary("1010", "1011") << "\n";
}