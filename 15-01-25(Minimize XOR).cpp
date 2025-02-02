// https://leetcode.com/problems/minimize-xor/description/?envType=daily-question&envId=2025-01-15

class Solution {
public:

    // taking AND
    bool is_set(int &x , int bit)
    {
        return x & (1 << bit) ;
    }

    // taking OR and left shift -> to move to current bit -> for setting the bit
    bool set_bit(int &x , int bit)
    {
        return x = x | (1 << bit) ;
    }

    // for unsetting the bit -> just perform negation of left shift 
    bool unset_bit(int &x, int bit)
    {
        return x = x & ~(1 << bit) ;
    }
    int minimizeXor(int num1, int num2) {

        int x = num1 ;
        int req_set_bit_count = __builtin_popcount(num2) ;
        int curr_set_bit_count = __builtin_popcount(x) ;

        int bit = 0 ;
        if(curr_set_bit_count < req_set_bit_count)
        {

            while(curr_set_bit_count < req_set_bit_count)
            {
                // start with least significant bit
                if(!is_set(x , bit) )
                {
                    set_bit(x , bit) ;
                    curr_set_bit_count++ ;
                }
                bit++ ;
            }
        }
        else if(curr_set_bit_count > req_set_bit_count)
        {
            while(curr_set_bit_count > req_set_bit_count)
            {
                // set bits => unset bits
                if(is_set(x , bit))
                {
                    unset_bit(x , bit) ;
                    curr_set_bit_count-- ;
                }
                bit++ ;
            }
        }
        return x ;
    }
};
