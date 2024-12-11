// https://leetcode.com/problems/find-longest-special-substring-that-occurs-thrice-i/?envType=daily-question&envId=2024-12-10

// STEPS

/*
1) FIND ALL THE "SUBSTRINGS"
2) FIND ALL "SPECIAL SUBSTRINGS"
3) FIND LENGTH OF LONGEST "SPECIAL SUBSTRING"
*/

// CATCH
// 1) direct find special substring instead of finding all substrings

class Solution {
public:
    int maximumLength(string s) {
        int n = s.size() ;

        unordered_map<string , int> mp ;

        for(int i = 0 ; i < n ; ++i)
        {
            string curr = "" ;
            for(int j = i ; j < n ; ++j)
            {
                if(curr.empty() || curr.back() == s[j])
                {
                    curr.push_back(s[j]) ;
                    mp[curr]++;
                }
                else
                {
                    break ;
                }
            }
        }

        int res = 0 ;

        for(auto &it : mp)
        {
            string str = it.first ;
            int count = it.second ;

            if(count >= 3 && str.length() > res)
            {
                res = str.length() ;
            }

        }

        if(res == 0)
        return -1 ;

        return res  ;

    }
};
