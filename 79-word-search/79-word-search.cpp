class Solution {
public:
    //pass board by reference
    bool DFS(vector<vector<char>>& board, string word, int i, int j, int n) {
		//check if all the alphabets in the word is checked
        if(n == word.size()) return true; 
        
		//check if i and j are out of bound or if the characters aren't equal
        if(i < 0 || i >= board.size() || j < 0 || j >= board[i].size() || board[i][j] != word[n]) return false;
        
		//mark as visited 
        board[i][j] = '0';
        
		//branch out in all 4 directions
        bool status = DFS(board, word, i + 1, j, n + 1) ||  //down
                        DFS(board, word, i, j + 1, n + 1) ||  //right
                        DFS(board, word, i - 1, j, n + 1) ||  //up
                        DFS(board, word, i, j - 1, n + 1);  //left
        
		//change the character back for other searches
        board[i][j] = word[n];
		
        return status;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        if(word == "") return false;
        
        for(int i = 0; i < board.size(); i++) 
            for(int j = 0; j < board[i].size(); j++) 
				//check if the characters are equal then call DFS
                if(board[i][j] == word[0] && DFS(board, word, i, j, 0))
                    return true;
        
        return false;
    }
};


/*
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
*/
