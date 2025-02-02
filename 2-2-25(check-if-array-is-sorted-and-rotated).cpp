// https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/description/?envType=daily-question&envId=2025-02-02

class Solution {
public:
    int n;

    void rotate(vector<int>& arr) 
    {
        int x = arr[n - 1]; 
        for (int i = n - 1; i > 0; --i) 
        {
            arr[i] = arr[i - 1];  
        }
        arr[0] = x;  
    }

    bool is_equal(vector<int>& nums, vector<int>& ans) 
    {
        for (int i = 0; i < nums.size(); ++i) 
        {
            if (nums[i] != ans[i]) 
            {
                return false;
            }
        }
        return true;
    }

    bool check(vector<int>& nums) {
        n = nums.size();
        vector<int> ans = nums;
        sort(ans.begin(), ans.end());  

        for (int i = 0; i < n; ++i) 
        {
            if (is_equal(nums, ans) == true) 
            {
                return true;
            }
            rotate(nums);  // Rotate for the next check
        }

        return false;
    }
};
