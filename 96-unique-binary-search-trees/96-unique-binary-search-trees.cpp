/*
* Follow af recursion formula, and code it
* f(n) = E f(i-1)*f(n-i)
  number 
* Where n is not position dependent, what it actually
  is is the number of elements int the left/right subtree  
* Number of trees = left subtree number * right subtree number  
*/
class Solution {
public:
    
    int dfs(int n, vector<int> &memo){
        if(n == 0 || n == 1) return 1;
        
        if(memo[n] != -1) return memo[n];
        int left_right = 0;
        for(int i = 1; i <= n; i++){
            int left_number = i-1;
            int right_number = n-i;
            left_right += dfs(left_number, memo) * dfs(right_number, memo);
        }
        
        return memo[n] = left_right;
    }
    int numTrees(int n) {
        vector<int> memo (n+1, -1);
        return dfs(n, memo);
    }
};