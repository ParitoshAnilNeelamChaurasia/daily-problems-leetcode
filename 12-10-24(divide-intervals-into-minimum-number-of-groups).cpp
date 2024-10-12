// https://leetcode.com/problems/divide-intervals-into-minimum-number-of-groups/description/?envType=daily-question&envId=2024-10-12

class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        int n = intervals.size() ;

        sort(intervals.begin() , intervals.end()) ;

        // min heap -> to store ending points
        priority_queue<int,vector<int>,greater<int>> pq;

        for(vector<int> &interval : intervals)
        {
            int st = interval[0] ;
            int end = interval[1] ;

            // if st > end_pt of top element of pq 
            if(!pq.empty() && st > pq.top())
            {
                // pop it
                pq.pop() ;
            }
            // push in pq -> st <= pq.top -> end_element
            pq.push(end) ;
        }
        return pq.size() ;
    }
};
