class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        vector<int> temp; 
        for(int i = 0; i< matrix.size(); i++){
            for(int j =0; j < matrix[0].size(); j++)
                temp.push_back(matrix[i][j]);
        }
        int s =0; 
        int e = matrix.size();
        auto it = find(temp.begin(), temp.end(), target);
        if(it != temp.end())
            return true;
        else
            return false;
    }
};