#include <string>
#include <unordered_map>
class Solution {
public:
  bool isAnagram(std::string s, std::string t) {
    if (s.length() != t.length()) {
      return false;
    }
    std::unordered_map<char, int> s_hashmap;
    std::unordered_map<char, int> t_hashmap;
    for (int i = 0; i < s.length(); i++) {
      s_hashmap[s[i]]++;
      t_hashmap[t[i]]++;
    }

    if (s_hashmap == t_hashmap) {
      return true;
    } else {
      return false;
    }
  }
};
