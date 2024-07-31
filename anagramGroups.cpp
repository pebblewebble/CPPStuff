#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>

class Solution {
public:
  std::vector<std::vector<std::string>>
  groupAnagrams(std::vector<std::string> &strs) {
    std::unordered_map<std::string, std::vector<std::string>> hashmap;
    for (int i = 0; i < strs.size(); i++) {
      std::string sortedWord = strs[i];
      std::sort(sortedWord.begin(), sortedWord.end());
      if (hashmap.find(sortedWord) == hashmap.end()) {
        std::vector<std::string> wordsToBeStored;
        wordsToBeStored.insert(wordsToBeStored.end(), strs[i]);
        hashmap[sortedWord] = wordsToBeStored;
      } else {
        hashmap[sortedWord].push_back(strs[i]);
      }
    }
    std::vector<std::vector<std::string>> answer;
    for (const auto &[key, value] : hashmap) {
      answer.insert(answer.begin(), value);
    }
    return answer;
  }
};
