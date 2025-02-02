// https://leetcode.com/problems/minimum-length-of-string-after-operations/description/?envType=daily-question&envId=2025-01-13

class Solution {
public:
    int minimumLength(string s) {
        vector<int> freq(26,0) ;

        int n = s.size() ;

        for(int i = 0 ; i < n ; ++i)
        {
            char ch = s[i] ;
            freq[ch-'a']++ ;
        }

        vector<int> curr_freq(26,0) ;

        int count = 0 ;
        for(int i = 0 ; i < n ; ++i)
        {
            char ch = s[i] ;
            if(freq[ch-'a'] < 3)
            {
                continue ;
            }
            // freq[ch-'a'] >= 3
            else
            {
                curr_freq[ch-'a']++ ;
                if(curr_freq[ch-'a'] == 3)
                {
                    curr_freq[ch-'a'] = curr_freq[ch-'a'] - 2 ;
                }
            }
        }

        for(int i = 0 ; i < curr_freq.size() ; ++i)
        {
            count += curr_freq[i] ;
        }
        return count ;
    }
};
