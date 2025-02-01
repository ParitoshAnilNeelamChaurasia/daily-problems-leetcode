// https://leetcode.com/problems/special-array-i/description/?envType=daily-question&envId=2025-02-01

class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        int n = nums.size() ;

        if(n == 1)
        return true ;

        for(int i = 0 ; i<n - 1; ++i)
        {
            if(nums[i] % 2 == nums[i+1] % 2)
            {
                return false ;
            }
        }
        return true ;
    }
};
