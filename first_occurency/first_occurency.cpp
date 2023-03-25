// Given two strings needle and haystack, return the index of the first
// occurrence of needle in haystack, or -1 if needle is not part of haystack.

#include <iostream>
#include <map>
#include <string>
using std::cout;
using std::string;

class Solution {
public:
  int strStr(string haystack, string needle) {
    if (haystack.length() < needle.length()) {
      return -1;
    }

    if (haystack == needle) {
      return 0;
    }

    int temp(0), i(0);
    for (; i < haystack.length(); i++) {
      if (temp == needle.length()) {
        return i - temp;
      }

      if (haystack[i] == needle[temp]) {
        temp++;
      } else {
        i -= temp;
        temp = 0;
      }
    }

    if (temp == needle.length()) {
      return i - temp;
    }

    return -1;
  }
};

int main() {
  Solution *solution = new Solution();
  cout << solution->strStr("leetcode", "leeto") << "\n";
  cout << solution->strStr("sadbutsad", "sad") << "\n";
}