#include <unordered_map>
#include <vector>
class Solution {
public:
  bool hasDuplicate(std::vector<int> &nums) {
    std::unordered_map<int, int> hashmap;
    for (int i = 0; i < nums.size(); i++) {
      if (hashmap.find(nums[i]) != hashmap.end()) {
        hashmap.insert({nums[i], 1});
      } else {
        return false;
      }
    }
    return true;
  }
};
