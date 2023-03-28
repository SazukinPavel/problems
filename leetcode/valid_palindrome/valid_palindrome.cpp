#include "iostream"
#include <map>
using namespace std;

class Solution {
public:
  bool isPalindrome(string s) {
    int i(0), j(s.length() - 1);
    while (i < s.length() && j >= 0) {

      if (!isLetter(s[i]) || !isLetter(s[j])) {
        j -= !isLetter(s[j]) ? 1 : 0;
        i += !isLetter(s[i]) ? 1 : 0;
        continue;
      }

      if (tolower(s[i]) != tolower(s[j])) {
        return false;
      }
      j--;
      i++;
    }
    return true;
  }

private:
  bool isLetter(char c) {
    int code = (int)c;
    return (code >= 65 && code < 91) || (code >= 97 && code <= 122) ||
           (code >= 48 && code <= 57);
  }
};

int main() {
  Solution solution;
  cout << solution.isPalindrome("A man, a plan, a canal: Panama") << "\n";
  cout << solution.isPalindrome("race a car") << "\n";
  cout << solution.isPalindrome(
              "Marge, let's \"[went].\" I await {news} telegram.")
       << "\n";
}