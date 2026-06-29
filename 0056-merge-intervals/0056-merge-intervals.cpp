#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // If no intervals, return empty
        if (intervals.empty()) return {};

        // Step 1: Sort intervals by start time
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> result;

        // Step 2: Start with the first interval
        result.push_back(intervals[0]);

        // Step 3: Compare remaining intervals
        for (int i = 1; i < intervals.size(); i++) {
            // Get the last merged interval
            vector<int>& last = result.back();

            // If overlapping or touching
            if (intervals[i][0] <= last[1]) {
                // Merge by extending the end
                last[1] = max(last[1], intervals[i][1]);
            } else {
                // No overlap, add new interval
                result.push_back(intervals[i]);
            }
        }

        return result;
    }
};
