// https://leetcode.com/problems/largest-number/description/?envType=daily-question&envId=2024-09-18

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        int n = nums.size() ;

        set<int> st ;
        for(auto it : nums)
        {
            st.insert(it) ;
        }

        if(st.size() == 1)
        {
            if(nums[0] == 0)
            return to_string(0) ;
        }

        auto mycomparator = [](int &a , int &b)
        {
            string s1 = to_string(a) ;
            string s2 = to_string(b) ;

            if(s1 + s2 > s2 + s1)
            {
                return true ;
            }
            return false ;
        } ;

        sort(nums.begin() , nums.end() , mycomparator) ;

        string ans = "" ;

        for(int &it : nums)
        {
            ans += to_string(it) ;
        }
        return ans ;
    }
};
