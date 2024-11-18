// https://leetcode.com/problems/defuse-the-bomb/description/?envType=daily-question&envId=2024-11-18

class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size() ;

        vector<int> ans(n,0) ;

        if(k==0)
        {
            return ans ;
        }

        for(int i = 0 ; i < n ; ++i)
        {
            int sum =0 ;

            if(k > 0)
            {
                for(int j = 1 ; j <= k ; ++j)
                {
                    sum = sum + code[(i+j) % n] ;
                }
            }
            else
            {
                for(int j = 1 ; j <= abs(k) ; ++j)
                {
                    sum += code[(i-j + n) % n] ;
                }
            }
            ans[i] = sum ;
        }
        return ans ;
    }
};
