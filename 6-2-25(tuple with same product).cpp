// https://leetcode.com/problems/tuple-with-same-product/description/?envType=daily-question&envId=2025-02-06

class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int n = nums.size() ;

        unordered_map<int,int> mp ;

        int ans = 0 ;
        for(int i = 0 ; i < n ; ++i)
        {
            for(int j = i+1 ; j < n ; ++j)
            {
                int product = nums[i]*nums[j] ;
                mp[product]++ ;
            }
        }

        for(auto &it : mp)
        {
            int val = it.second ;
            ans += (val)*(val-1) ;
        }
        return ans ;
    }
};
