
// https://leetcode.com/problems/check-if-one-string-swap-can-make-strings-equal/description/?envType=daily-question&envId=2025-02-05
class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int n = s1.size();
        vector<int> diff; // Stores indices of differing characters

        for (int i = 0; i < n; ++i) 
        {
            if (s1[i] != s2[i]) 
            {
                diff.push_back(i);
            }
        }

        if (diff.size() == 0) {
            return true; 
        }

        if (diff.size() != 2) {
            return false; 
        }

        // Check if swapping the two differing characters makes the strings equal
        swap(s1[diff[0]], s1[diff[1]]);
        return s1 == s2;
    }
};
