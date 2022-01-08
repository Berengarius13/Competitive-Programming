class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int n = mat.size();
        int k = 4;
            while(k>0)
        {for(int i = 0; i< n; i++){
            for(int j =0; j<=i; j++)
                swap(mat[i][j], mat[j][i]);
        }
        
        for(int i =0; i< n; i++)
        {
            for(int j =0; j < n/2; j++)
                swap(mat[i][j], mat[i][n-j-1]);
        }
        if(mat == target)
            return true;
         k--;
    }
    
    return false;
    }
    
};