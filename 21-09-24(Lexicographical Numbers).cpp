// https://leetcode.com/problems/lexicographical-numbers/?envType=daily-question&envId=2024-09-21

class Solution {
public:
    vector<int> ans ;

    void f(int curr , int n)
    {
        if(curr > n)
        return ;

        ans.push_back(curr) ;

        for(int i = 0 ; i <= 9 ; ++i)
        {
            int next_num = curr*10 + i ;

            if(next_num > n)
            return ;

            f(next_num , n) ;
        }
    }
    vector<int> lexicalOrder(int n) {

        for(int i = 1 ; i <= 9 ; ++i)
        {
            f(i , n ) ;
        }
        return ans ;
    }
};
