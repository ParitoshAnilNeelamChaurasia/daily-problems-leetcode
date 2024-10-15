// https://leetcode.com/problems/separate-black-and-white-balls/description/?envType=daily-question&envId=2024-10-15

#define ll long long 

class Solution {
public:
    long long minimumSteps(string s) {
        int n = s.size() ;

        ll swap = 0 ;
        ll black = 0 ;

        for(int i = 0 ; i < n ; ++i)
        {
            if(s[i] == '0')
            {
                swap += black ;
            }
            else
            {
                black++ ;
            }
        }
        return swap ;
    }
};
