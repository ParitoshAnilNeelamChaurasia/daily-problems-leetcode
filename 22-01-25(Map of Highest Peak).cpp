// https://leetcode.com/problems/map-of-highest-peak/?envType=daily-question&envId=2025-01-22

// dfs fails because
/*
1 8
2 7
3 6         -> (3,6) -> diff != 1 -> therefore dfs fails
4 5

*/


// bfs succeeds because it traverse level wise
/*
0 1 3
1 2 3
3 3 3
*/


// in this problem multilevel bfs works

class Solution {
public:
    int n , m;

    vector<vector<int>> directions{
            {0,1},
        {-1,0},  {1,0},
            {0,-1}
    } ;

    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        m = isWater.size() ;
        n = isWater[0].size() ;

        vector<vector<int>> height(m , vector<int>(n,-1)) ;

        queue<pair<int,int>> q ;

        for(int i = 0 ; i < m ; ++i)
        {
            for(int j = 0 ; j < n ; ++j)
            {
                if(isWater[i][j] == 1)
                {
                    height[i][j] = 0 ;
                    q.push({i,j}) ;
                }
            }
        }

        while(!q.empty())
        {
            int sz = q.size() ;

            while(sz--)
            {
                pair<int,int> curr = q.front() ;
                q.pop() ;

                int i = curr.first ;
                int j = curr.second ;

                for(auto &dir : directions)
                {
                    int new_i = i + dir[0] ;
                    int new_j = j + dir[1] ;

                    if(new_i >= 0 && new_i < m && new_j >= 0 && new_j < n && height[new_i][new_j] == -1)
                    {
                        height[new_i][new_j] = height[i][j] + 1 ;
                        q.push({new_i,new_j}) ;
                    }
                }
            }
        }
        return height ;
    }
};
