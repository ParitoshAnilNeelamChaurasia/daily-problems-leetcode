// https://leetcode.com/problems/maximum-beauty-of-an-array-after-applying-operation/?envType=daily-question&envId=2024-12-11

class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        int n = nums.size() ;

        vector<pair<int,int>> intervals(n) ;

        for(int i = 0 ; i < n ; ++i)
        {
            intervals[i] = {nums[i] - k , nums[i] + k} ;
        }

        sort(intervals.begin() , intervals.end()) ;

        deque<int> deq ; // (only ending point)

        int max_beauty = 0 ;

        for(pair<int,int> &interval : intervals)
        {
            while(!deq.empty() && deq.front() < interval.first)
            {
                deq.pop_front() ;
            }

            deq.push_back(interval.second) ;

            max_beauty = max(max_beauty , (int)deq.size()) ;
        }

        return max_beauty ;
    }
};
