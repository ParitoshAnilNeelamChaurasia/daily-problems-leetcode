
// https://leetcode.com/problems/maximum-ascending-subarray-sum/description/?envType=daily-question&envId=2025-02-04

class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int n = nums.size() ;

        vector<int> ans(n) ;

        ans[0] = nums[0] ;

        for(int i = 1 ; i < n ; ++i)
        {
            if(nums[i] > nums[i-1] )
            {
                ans[i] = nums[i] + ans[i-1] ;
            }
            else
            {
                ans[i] = nums[i] ;
            }
        }

        return *max_element(ans.begin() , ans.end()) ;
    }
};
