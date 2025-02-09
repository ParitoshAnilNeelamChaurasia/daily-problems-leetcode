// https://leetcode.com/problems/count-number-of-bad-pairs/description/?envType=daily-question&envId=2025-02-09

#define ll long long
class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        ll n = nums.size() ;

        vector<int> ans(n) ;

        for(int i = 0 ; i < n ; ++i)
        {
            ans[i] = nums[i] - i ;
        }

        ll res = 0 ;


        unordered_map<int,int> mp ;

        mp[ans[0]] = 1 ;

        for(int j = 1 ; j < n ; ++j)
        {
            int count_of_nums_j = mp[ans[j]] ;
            
            int tot_num_before_j = j ;

            int bad_pairs = tot_num_before_j - count_of_nums_j ;

            res += bad_pairs ;

            mp[ans[j]]++ ;
        }
        return res ;
    }
};
