// https://leetcode.com/problems/minimum-operations-to-exceed-threshold-value-ii/?envType=daily-question&envId=2025-02-13



#define ll long long
class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n = nums.size() ;

        ll count = 0 ;

        priority_queue<ll , vector<ll> , greater<ll>> pq ;

        for(auto it : nums)
        {
            pq.push(it) ;
        }
        while(pq.top() < k)
        {
            ll first = pq.top() ;
            pq.pop() ;
            ll second = pq.top() ;
            pq.pop() ;

            ll sum = 2*min(first , second) + max(first , second) ;
            pq.push(sum) ;
            count++ ;
        }
        return count ;
    }
};
