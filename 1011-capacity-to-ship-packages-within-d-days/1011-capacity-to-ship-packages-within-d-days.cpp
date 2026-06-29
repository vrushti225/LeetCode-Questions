class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int left = *max_element(weights.begin(), weights.end()); 
        int right = 0;                                          
        for (int w : weights) right += w;

        int answer = right;

        while (left <= right) 
        {
            int mid = left + (right - left) / 2;
            int neededDays = 1;
            int currentLoad = 0;

            for (int w : weights)
            {
                if (currentLoad + w > mid)
                {
                    neededDays++;
                    currentLoad = 0;
                }
                currentLoad += w;
            }

            if (neededDays <= days) {
                answer = mid;       
                right = mid - 1;
            }
            else
            {
                left = mid + 1;   
            }
        }

        return answer;
    }
};