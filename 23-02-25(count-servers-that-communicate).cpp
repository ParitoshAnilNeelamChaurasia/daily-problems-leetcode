// https://leetcode.com/problems/count-servers-that-communicate/description/?envType=daily-question&envId=2025-01-23

class Solution {
public:
    int m , n ;
    int countServers(vector<vector<int>>& grid) {
        n = grid[0].size() ;
        m = grid.size() ;

        vector<int> rows(m) ;
        vector<int> col(n) ;

        for(int i = 0 ; i < m ; ++i)
        {
            for(int j = 0 ; j < n ; ++j)
            {
                rows[i] += grid[i][j] ;
                col[j] += grid[i][j] ;
            }
        }

        int count = 0 ;

        for(int i = 0 ; i < m ; ++i)
        {
            for(int j = 0 ; j < n ; ++j)
            {
                if(grid[i][j] == 1 && (rows[i] > 1 || col[j] > 1))
                {
                    count++ ;
                }
            }
        }
        return count ;


    }
};
