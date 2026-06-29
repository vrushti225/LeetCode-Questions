#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int splitArray(vector<int>& nums, int k)
    {
        int left = *max_element(nums.begin(), nums.end()); 
        long long right = 0;                              
        for (int n : nums) right += n;

        int answer = right;
        while (left <= right) {
            int mid = left + (right - left) / 2; 
            int subarrays = 1;
            long long currentSum = 0;
            for (int n : nums) {
                if (currentSum + n > mid) {
                    subarrays++;       
                    currentSum = 0;
                }
                currentSum += n;
            }
            if (subarrays <= k) {
                answer = mid;         
                right = mid - 1;
            } else {
                left = mid + 1;      
            }
        }

        return answer;
    }
};
