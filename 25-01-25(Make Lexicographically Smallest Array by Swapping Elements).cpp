// https://leetcode.com/problems/make-lexicographically-smallest-array-by-swapping-elements/description/?envType=daily-question&envId=2025-01-25

Step-by-Step Dry Run:
Initialize variables:

n = 5 (size of nums)
val_ind = [] (to store value-index pairs)
Create value-index pairs:


val_ind = [(5, 0), (1, 1), (3, 2), (8, 3), (9, 4)]
Sort val_ind by values:


val_ind = [(1, 1), (3, 2), (5, 0), (8, 3), (9, 4)]
Group values based on the limit:

Start with the first pair: gp_pairs = [[(1, 1)]]
Compare consecutive elements:
3 - 1 = 2 (≤ limit): Add (3, 2) to the current group.

gp_pairs = [[(1, 1), (3, 2)]]
5 - 3 = 2 (≤ limit): Add (5, 0) to the current group.

gp_pairs = [[(1, 1), (3, 2), (5, 0)]]
8 - 5 = 3 (≤ limit): Add (8, 3) to the current group.

gp_pairs = [[(1, 1), (3, 2), (5, 0), (8, 3)]]
9 - 8 = 1 (≤ limit): Add (9, 4) to the current group.

gp_pairs = [[(1, 1), (3, 2), (5, 0), (8, 3), (9, 4)]]
Sort indices within each group and update nums:

For the group [(1, 1), (3, 2), (5, 0), (8, 3), (9, 4)]:
Extract indices: [1, 2, 0, 3, 4]
Sort indices: [0, 1, 2, 3, 4]

  
Assign values in order:

nums[0] = 1, nums[1] = 3, nums[2] = 5, nums[3] = 8, nums[4] = 9
Final nums = [1, 3, 5, 8, 9]
Final Output:
nums = [1, 3, 5, 8, 9]

class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size() ;

        vector<pair<int,int>> val_ind ;

        for(int i = 0 ; i < n ; ++i)
        {
            val_ind.push_back({nums[i] , i}) ;
        }

        sort(val_ind.begin() , val_ind.end()) ;

        vector<vector<pair<int,int>>> gp_pairs ;

        gp_pairs.push_back({val_ind[0]}) ;

        for(int i = 1 ; i < n ; ++i)
        {
            if(val_ind[i].first - val_ind[i-1].first <= limit)
            {
                gp_pairs.back().push_back(val_ind[i]) ;
            }
            else
            {
                gp_pairs.push_back({val_ind[i]}) ;
            }
        }

        for(auto &it : gp_pairs)
        {
            vector<int> indices ;
            for(auto &[val , ind] : it)
            {
                indices.push_back(ind) ;
            }

            sort(indices.begin() , indices.end()) ;

            for(int i = 0 ; i < indices.size() ; ++i)
            {
                nums[indices[i]] = it[i].first ;
            }
        }
        return nums ;
    }
};
