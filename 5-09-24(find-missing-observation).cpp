// https://leetcode.com/problems/find-missing-observations/?envType=daily-question&envId=2024-09-05

class Solution
{
public:
    vector<int> missingRolls(vector<int> &rolls, int mean, int n)
    {
        int m = rolls.size();
        int totalSum = mean * (n + m); //  total sum we need
        int sumOfGivenRolls = accumulate(rolls.begin(), rolls.end(), 0);
        int rhs = totalSum - sumOfGivenRolls; // Remaining sum -> missing value

        // Check if the remaining sum can be distributed across n rolls
        if (rhs < n || rhs > 6 * n)
        {
            return {}; // If not possible, return an empty vector
        }

        vector<int> ans(n, 1); // Start with all values as 1
        rhs -= n; // Adjust the remaining sum by accounting for the 1s

        // Distribute the remaining sum to get each value between 1 and 6
        for (int i = 0; i < n ; ++i)
        {
            int add_value = min(rhs, 5); // We can add up to 5 (to make a value between 1 and 6)
            ans[i] += add_value;
            rhs -= add_value;

            if(rhs < 0)
            break ;
        }

        return ans;
    }
};
