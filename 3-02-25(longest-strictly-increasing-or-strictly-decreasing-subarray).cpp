// https://leetcode.com/problems/longest-strictly-increasing-or-strictly-decreasing-subarray/?envType=daily-question&envId=2025-02-03

class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
       

        int count_inc = 1;
        int mx = 1;

        for (int i = 0; i < n - 1; ++i) 
        {
            if (nums[i + 1] > nums[i]) 
            {
                count_inc++;
            } 
            else 
            {
                count_inc = 1;
            }
            mx = max(mx, count_inc);
        }

        int count_dec = 1;
        int mn = 1;

        for (int i = 0; i < n - 1; ++i) 
        {
            if (nums[i + 1] < nums[i]) 
            {
                count_dec++;
            } 
            else 
            {
                count_dec = 1;
            }
            mn = max(mn, count_dec);
        }

        return max(mx, mn);
    }
};
