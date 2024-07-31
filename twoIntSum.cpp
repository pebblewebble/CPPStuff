#include <cstdlib>
#include <unordered_map>
#include <vector>
class Solution {
public:
  std::vector<int> twoSum(std::vector<int> &nums, int target) {
    std::unordered_map<int, int> hashmap;
    for (int i = 0; i < nums.size(); i++) {
      int difference=abs(target-nums[i]);
      if(hashmap.find(difference)!=hashmap.end()){
        if(i<hashmap.at(difference)){
          return {i,hashmap.at(difference)};
        }else{
          return {hashmap.at(difference),i};
        }
      }
      if (hashmap.find(nums[i]) == hashmap.end()) {
        hashmap.insert({nums[i], i});
      }
    }
    return {0,0};
  }
};
