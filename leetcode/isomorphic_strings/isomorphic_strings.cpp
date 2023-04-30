#include <map>
#include <string>

using namespace std;

class Solution {
public:
  bool isIsomorphic(string s, string t) {
    if (s.length() != t.length()) {
      return false;
    }

    map<char, char> translateS;
    map<char, char> translateT;
    
    for (int i=0;i<s.length();i++) {
      if((translateS[s[i]] && translateS[s[i]]!=t[i]) || (translateT[t[i]] && translateT[t[i]]!=s[i])){
        return false;
      }else{
        translateS[s[i]]=t[i];
        translateT[t[i]]=s[i];
      }
    }

    return true;
  }
};