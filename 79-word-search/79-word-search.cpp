class Solution {
public:
    bool ans = false;
    void bcktrk(vector<vector<char>>& board, string &word, int i, int j, int k){
        if(k == word.size()){
            ans = true; return;
        }
        int n = board.size();
        int m = board[0].size();
        if(board[i][j] != '.' && word[k] == board[i][j]){
            board[i][j] = '.';
            bcktrk(board, word, i, j, k+1);
            board[i][j] = word[k];
        }
        if(j+1 < m){
            if(board[i][j+1] != '.' && board[i][j+1] == word[k]){
                board[i][j+1] = '.';
                bcktrk(board, word, i, j+1, k+1);
                board[i][j+1] = word[k];
            }
        }
        if(j-1 >= 0){
            if(board[i][j-1] != '.' && board[i][j-1] == word[k]){
                board[i][j-1] = '.';
                bcktrk(board, word, i, j-1, k+1);
                board[i][j-1] = word[k];
            }
        }
        if(i+1 < n){
            if(board[i+1][j] != '.' && board[i+1][j] == word[k]){
                board[i+1][j] = '.';
                bcktrk(board, word, i+1, j, k+1);
                board[i+1][j] = word[k];
           }
        }
        if(i-1 >= 0){
            if(board[i-1][j] != '.' && board[i-1][j] == word[k]){
                board[i-1][j] = '.';
                bcktrk(board, word, i-1, j, k+1);
                board[i-1][j] = word[k];
            }
        }
    }
    bool exist(vector<vector<char>>& board, string word) {
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                if(board[i][j] == word[0]){
                    bcktrk(board, word, i, j, 0);
                    if(ans) return ans;
                }
            }
        }
        return ans;
    }
};