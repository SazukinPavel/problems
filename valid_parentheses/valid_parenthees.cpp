// Given a string s containing just the characters '(', ')', '{', '}', '[' and
// ']', determine if the input string is valid. An input string is valid if:
// Open brackets must be closed by the same type of brackets.
// Open brackets must be closed in the correct order.
// Every close bracket has a corresponding open bracket of the same type.
#include "iostream"
#include <algorithm>
#include <map>
#include <string>

using std::string;

class Solution {
public:
  bool isValid(string s) { return checkParenthees(s); }

private:
  std::map<char, char> parentheesMap{{'{', '}'}, {'(', ')'}, {'[', ']'}};
  bool checkParenthees(string s) {
    string temp = "";
    for (int i(0); i < s.length(); i++) {
      if (temp.length()>0 && s[i] == temp[temp.length()-1]) {
        temp = temp.erase(temp.length() - 1, 1);
      } else {
        temp += parentheesMap[s[i]];
      }
    }
    return temp.empty();
  }
};

int main() {
  Solution *solution = new Solution();

  std::cout << solution->isValid("{[]}") << "\n";
  std::cout << solution->isValid("()[]{}") << "\n";
  std::cout << solution->isValid("]") << "\n";
}