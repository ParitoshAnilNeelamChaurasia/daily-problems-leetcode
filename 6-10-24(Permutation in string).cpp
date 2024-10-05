// https://leetcode.com/problems/permutation-in-string/description/?envType=daily-question&envId=2024-10-05

class Solution {
public:
    int m , n ;
    
    bool checkInclusion(string s1, string s2) {
        m = s1.size() ;
        n = s2.size() ;

        if(m > n)
        return false ;

        sort(s1.begin() , s1.end()) ;

        for(int i = 0 ; i <= n - m  ; ++i)
        {
            string ans = s2.substr(i , m) ;

            sort(ans.begin() , ans.end()) ;

            if(s1 == ans)
            return true ;
        }
        return false ;
    }
};
