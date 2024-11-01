// https://leetcode.com/problems/delete-characters-to-make-fancy-string/description/?envType=daily-question&envId=2024-11-01

class Solution {
public:
    string makeFancyString(string s) {
        int n = s.size();
        string ans;
        int count = 1;  

        ans.push_back(s[0]);  // Add the first character to `ans`

        for (int i = 1; i < n; ++i) 
        {
            if (s[i] == s[i - 1]) 
            {
                count++;  // Increment count for consecutive characters
            } 
            else 
            {
                count = 1;  // Reset count if characters are different
            }

            // Add character if the count is less than or equal to 2
            if (count <= 2) 
            {
                ans.push_back(s[i]);
            }
        }

        return ans;
    }
};
