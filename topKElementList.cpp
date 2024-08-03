#include <queue>
#include <unordered_map>
#include <utility>
#include <vector>
using namespace std;
class Solution {
public:
  vector<int> topKFrequent(vector<int> &nums, int k) {
    unordered_map<int, int> hashmap;
    for (int i = 0; i < nums.size(); i++) {
      hashmap[nums[i]]++;
    }
    auto comp = [](pair<int,int>&a, pair<int,int>&b){
      return a.second<b.second;
    };
    priority_queue<pair<int,int>,vector<pair<int,int>>,decltype(comp)>heap(comp);
    for(auto& entry : hashmap){
      heap.push({entry.first,entry.second});
    }
    vector<int> answer;
    while(k-- > 0 ){
      answer.push_back(heap.top().first);
      heap.pop();
    }
    return answer;
  }
};
