#include <cstdlib>
#include <unordered_map>
#include <vector>
class Solution {
public:
  std::vector<int> twoSum(std::vector<int> &nums, int target) {
    std::unordered_map<int, int> hashmap;
    for (int i = 0; i < nums.size(); i++) {
      if (hashmap.find(nums[i]) == hashmap.end()) {
        hashmap.insert({nums[i], i});
      }
      int difference=abs(target-nums[i]);
      if(hashmap.find(difference)!=hashmap.end()){
        return {i,hashmap.at(difference)};
      }
    }
    return {0,0};
  }
};
