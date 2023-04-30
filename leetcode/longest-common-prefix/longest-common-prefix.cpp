// Write a function to find the longest common prefix string amongst an array of
// strings. If there is no common prefix, return an empty string "".
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  string longestCommonPrefix(vector<string> &strs) {
    if(strs.size()==1){
      return strs[0];
    }
    
    int i = 0;
    string result("");
    bool stop(false);
    while (true) {
      char c=strs[0][i];
      for (auto s : strs) {
        if(stop){
          break;
        }
        stop=s.length()<=i || s[i]!=c;
      }
      if(stop){
        break;
      }
      result+=c;
      i++;
    }
    return result;
  }
};

int main() {
  Solution s;
  
  vector<string> *test1=new vector<string>{"flower","flow","flight"};
  vector<string> *test2=new vector<string>{"dog","racecar","car"};
  vector<string> *test3=new vector<string>{"",""};
  
  std::cout<< s.longestCommonPrefix(*test1)<<"\n";
  std::cout<< s.longestCommonPrefix(*test2)<<"\n";
  std::cout<< s.longestCommonPrefix(*test3)<<"\n";
}