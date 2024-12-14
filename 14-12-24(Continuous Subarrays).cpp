// Brute Force
#define ll long long
class Solution {
public:

    bool is_continous(vector<int> &nums , int st , int end)
    {
        for(int i = st ; i <= end ; ++i)
        {
            for(int j = i+1 ; j <= end ; ++j)
            {
                if(abs(nums[j]-nums[i]) > 2)
                {
                    return false ;
                }
            }
        }
        return true ;
    }
    long long continuousSubarrays(vector<int>& nums) {
        ll n = nums.size() ;

        ll count = 0 ;

        for(int i = 0 ; i < n ; ++i)
        {
            for(int j = i ; j < n ; ++j)
            {
                if(is_continous(nums , i , j) == true)
                {
                    count++ ;
                }
            }
        }
        return count ;
    }
};

// optimized

class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        
    int n = nums.size();
    multiset<int> window; // To store elements in the current window
    int i = 0; // Left boundary of the window
    long long count = 0; // Total number of valid subarrays

    for (int j = 0; j < n; j++) { // j is the right boundary
        window.insert(nums[j]); // Add current element to the window

        // Check the condition |max - min| <= 2
        while (*window.rbegin() - *window.begin() > 2) {
            // Shrink the window from the left
            window.erase(window.find(nums[i]));
            i++;
        }

        // Add the number of valid subarrays ending at index j
        count += (j - i + 1);
    }
    return count;
    }
};
