// https://leetcode.com/problems/max-sum-of-a-pair-with-equal-sum-of-digits/description/?envType=daily-question&envId=2025-02-12

class Solution {
public:
    int digitSum(int a) {
        int sum = 0;
        while (a) {
            sum += a % 10;
            a /= 10;
        }
        return sum;
    }

    int maximumSum(vector<int>& nums) {
        unordered_map<int, vector<int>> mp;

        for (int num : nums) {
            int sum = digitSum(num);
            mp[sum].push_back(num);
        }

        int maxSum = -1;

        for (auto& it : mp) {
            if (it.second.size() > 1) {
                // two largest numbers in the group
                sort(it.second.begin(), it.second.end(), greater<int>());
                
                int currSum = it.second[0] + it.second[1];
                maxSum = max(maxSum, currSum);
            }
        }

        return maxSum;
    }
};
