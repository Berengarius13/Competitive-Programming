class Solution {
public:
    int dfs(vector<vector<int>> &board, int i, int count){
        int n = board.size();
        if(i == n){
            if(count == 0) return 1;
            return 0;
        }
        int a = 0;
        for(int j = 0; j < n; j++){

            if(board[i][j] == 0 && count >= 0){
                for(int k = 0; k < n; k++){
                board[k][j]++;
                if(i + k < n && j + k < n)
                    board[i+k][j+k]++;
                if(i + k < n && j - k >= 0)
                    board[i+k][j-k]++;
                }
                
                a += dfs(board, i+1, count-1);
                
                for(int k = 0; k < n; k++){
                board[k][j]--;
                if(i + k < n && j + k < n)
                    board[i+k][j+k]--;
                if(i + k < n && j - k >= 0)
                    board[i+k][j-k]--;
                }
            }
        }
        
        return a;
    }
    int totalNQueens(int n) {
        vector<vector<int>> board (n, vector<int> (n , 0));
        return dfs(board, 0, n);
    }
};