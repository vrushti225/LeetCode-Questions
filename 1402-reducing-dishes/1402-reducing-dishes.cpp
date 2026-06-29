class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        sort (satisfaction.begin() , satisfaction.end());
        int total = 0;
        int result = 0;
        for(int i =satisfaction.size()-1;i>=0;i--)
        {
            total+=satisfaction[i];
            if ( total > 0)
            result+=total;
            else
            break;
        }
        return result;
    }
};