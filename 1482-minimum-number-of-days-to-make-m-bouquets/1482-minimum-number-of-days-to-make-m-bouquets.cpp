class Solution {
public:
   bool canMakeBouquets(vector<int>& bloomDay, int m, int k, int day) {
        int bouquets = 0;
        int flowers = 0;

        for (int i = 0; i < bloomDay.size(); i++) {
            if (bloomDay[i] <= day) {
                flowers++;
                if (flowers == k) {
                    bouquets++;
                    flowers = 0; // reset after making one bouquet
                }
            } else {
                flowers = 0; // break adjacency
            }
        }

        return bouquets >= m;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        long long n = bloomDay.size();
        if (n < (long long)m * k) return -1;

        int low = 1;
        int high = *max_element(bloomDay.begin(), bloomDay.end());
        int answer = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (canMakeBouquets(bloomDay, m, k, mid)) {
                answer = mid;
                high = mid - 1; // try earlier day
            } else {
                low = mid + 1; // need more days
            }
        }

        return answer;
    }
};