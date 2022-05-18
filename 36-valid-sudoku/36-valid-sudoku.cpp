class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<vector<int>>> vec (3, vector<vector<int>> (9, vector<int> (10, 0)));
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                if(board[i][j] != '.'){
                    int k = (int)board[i][j] - '0';
                    vec[0][i][k]++;
                    vec[1][j][k]++;
                    vec[2][(3*(i/3))+(j/3)][k]++;
                    if(vec[0][i][k]>1 || vec[1][j][k]>1 || vec[2][(3*(i/3))+(j/3)][k]>1 )
                        return false;
                }
            }
        }
        return true;
    }
};