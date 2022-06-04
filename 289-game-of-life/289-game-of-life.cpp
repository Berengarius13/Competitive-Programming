class Solution {
public:
    void dfs(vector<vector<int>>& board, int i, int j){
        if(j == board[0].size()){
            i++; j = 0;
        }
        if(i == board.size()) return;
        int count_z = 0; int count_o = 0;
        int assign = 0;
        int U, L, R, D;
        bool up = 0; bool dow = 0; 
        bool le = 0; bool ri = 0;
        if(i-1 >= 0){
            up = 1; U = i-1;
        }
        if(i+1 < board.size()){
            dow = 1; D = i+1;
        }
        if(j-1 >= 0){
            le = 1; L = j-1;
        }
        if(j+1 < board[0].size()){
            ri = 1; R = j+1;
        }
        if(up) (board[U][j]) ? count_o++ : count_z++;
        if(le & up) (board[U][L]) ? count_o++ : count_z++;
        if(up & ri) (board[U][R]) ? count_o++ : count_z++;
        if(le) (board[i][L]) ? count_o++ : count_z++;
        if(ri) (board[i][R]) ? count_o++ : count_z++;
        if(dow) (board[D][j]) ? count_o++ : count_z++;
        if(dow & le) (board[D][L]) ? count_o++ : count_z++;
        if(dow & ri) (board[D][R]) ? count_o++ : count_z++;
        
        if(board[i][j] == 1){
            if(count_o == 2 || count_o == 3) assign = 1;
        }
        else{
            if(count_o == 3) assign = 1;
        }
        dfs(board, i, j+1);
        board[i][j] = assign;
    }
    void gameOfLife(vector<vector<int>>& board) {
        dfs(board, 0, 0);
    }
};