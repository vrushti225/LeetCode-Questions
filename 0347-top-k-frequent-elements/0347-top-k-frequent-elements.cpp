#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // Step 1: Count frequency of each number
        unordered_map<int, int> freq;
        for (int num : nums) {
            freq[num]++;
        }

        // Step 2: Min-heap to keep top k frequent elements
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> minHeap;

        for (auto& it : freq) {
            minHeap.push({it.second, it.first});
            if (minHeap.size() > k) {
                minHeap.pop(); // remove least frequent
            }
        }

        // Step 3: Extract result
        vector<int> result;
        while (!minHeap.empty()) {
            result.push_back(minHeap.top().second);
            minHeap.pop();
        }

        return result;
    }
};
