class Solution {
public:
    vector<vector<char>> ans;
    bool solver(vector<vector<char>> &board, int i, int j, vector<vector<vector<int>>> &vec)    {
        
        if(j == 9){
            i++; j = 0;
        }
        if(i== 9){
            return true;
        }
        // for(int m = j+1; m < 9; m++){     
        // }
        int m = j;
        if(board[i][m] == '.'){
            for(int k = 1; k <= 9; k++){
                if(vec[0][i][k] == 0 && vec[1][m][k] == 0 && vec[2][(3*(i/3))+(m/3)][k]==0){
                    vec[0][i][k] = 1;
                    vec[1][m][k] = 1;
                    vec[2][(3*(i/3))+(m/3)][k] = 1; 
                    board[i][m] = char(k+48);
                    if(solver(board, i, m+1, vec))
                        return true;
                    vec[0][i][k] = 0;
                    vec[1][m][k] = 0;
                    vec[2][(3*(i/3))+(m/3)][k] = 0; 
                    board[i][m] = '.';
                }
            }
            // return false;
          }
        else {
            return solver(board, i, m+1, vec);
        }
        return false;  
    }
    void solveSudoku(vector<vector<char>>& board) {
       // Create Hash [3][9][10],           int x = character - '0'
        /*
        * [3] = {R, C, 3x3}
        * [9] = {0, 8} i, j values
        * [10] = {k}, values of digits
        */
        vector<vector<vector<int>>> vec (3, vector<vector<int>> (9, vector<int> (10, 0)));
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                if(board[i][j] != '.'){
                    int k = (int)board[i][j] - '0';
                    vec[0][i][k] = 1;
                    vec[1][j][k] = 1;
                    vec[2][(3*(i/3))+(j/3)][k] = 1;
                }
            }
        }
        solver(board, 0, 0, vec);
    }
};