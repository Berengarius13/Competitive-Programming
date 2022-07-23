class Solution {
public:
    int mcm(vector<int> &values, int i, int j, vector<vector<int>> &memo){
        if(i+1 >= j) return 0;
        if(memo[i][j] != -1) return memo[i][j];
        int min_triangle = INT_MAX;
        
        for(int k = i+1; k < j; k++){
            int a = mcm(values, i, k, memo) + mcm(values, k, j, memo) + 
                    values[i] * values[j] * values[k];
            min_triangle = min(a, min_triangle);
        }
        memo[i][j] = min_triangle;
        return min_triangle;
    }
    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();
        vector<vector<int>> memo(n+1, vector<int> (n+1, -1));
        return mcm(values, 0, n-1, memo);
    }
};