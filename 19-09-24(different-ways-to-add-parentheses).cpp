// https://leetcode.com/problems/different-ways-to-add-parentheses/description/?envType=daily-question&envId=2024-09-19

class Solution {
public:
    vector<int> f(string expr) {
        vector<int> ans;  
        int n = expr.size();

        for (int i = 0; i < n; ++i) 
        {
            if (expr[i] == '+' || expr[i] == '-' || expr[i] == '*') 
            {
                // Divide the expression into two parts
                vector<int> left = f(expr.substr(0, i));  
                vector<int> right = f(expr.substr(i + 1));  

                for (int k = 0; k < left.size(); ++k) 
                {
                    for (int j = 0; j < right.size(); ++j) 
                    {
                        if (expr[i] == '+') 
                        {
                            ans.push_back(left[k] + right[j]);
                        } 
                        else if (expr[i] == '-') 
                        {
                            ans.push_back(left[k] - right[j]);
                        } 
                        else if (expr[i] == '*') 
                        {
                            ans.push_back(left[k] * right[j]);
                        }
                    }
                }
            }
        }

        // If no operator is found, the expression must be a number
        if (ans.empty()) 
        {
            ans.push_back(stoi(expr));
        }

        return ans;
    }

    vector<int> diffWaysToCompute(string expr) 
    {
        return f(expr);
    }
};
