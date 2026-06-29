class Solution {
public:
    int minMovesToMakePalindrome(string s) {
        int moves = 0;
        int l = 0, r = s.size() - 1;

        while (l < r) {
            if (s[l] == s[r]) {
                l++;
                r--;
            } else {
                int k = r;
                // Find matching character for s[l]
                while (k > l && s[k] != s[l]) {
                    k--;
                }

                if (k == l) {
                    // s[l] is the middle character
                    swap(s[l], s[l + 1]);
                    moves++;
                } else {
                    // Bring matching character to position r
                    while (k < r) {
                        swap(s[k], s[k + 1]);
                        moves++;
                        k++;
                    }
                    l++;
                    r--;
                }
            }
        }

        return moves;
    }
};