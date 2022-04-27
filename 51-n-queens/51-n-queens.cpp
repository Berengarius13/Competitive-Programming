class Solution {
public:
    vector<vector<string>> ans;
    
    void n_q(vector<string> &temp, vector<vector<int>> &maze, int x, int y, int s){
        int n = temp.size();
        temp[x][y] = 'Q';
        if(s == n){
            ans.push_back(temp);
            temp[x][y] = '.';
            // Here it directly runs back without changing value thus we 
            // need to change value of Q back
            return;
        }
        for(int i = 0; i < n; i++){
            if(x+i< n && y + i < n && !maze[x+i][y+i]) maze[x+i][y+i] = s;
            if(x+i< n && y - i >= 0 && !maze[x+i][y-i]) maze[x+i][y-i] = s;
            if(x-i>= 0 && y + i < n && !maze[x-i][y+i]) maze[x-i][y+i] = s;
            if(x-i>= 0 && y - i >= 0 && !maze[x-i][y-i]) maze[x-i][y-i] = s;
            if(!maze[x][i]) maze[x][i] = s;
            if(!maze[i][y]) maze[i][y] = s;
        }
        for(int i = 0; i < n; i++){
            /*
            * You will assume that you will definately find a queen in next row
            * Assuming that time complexity reduces
            * Why? Otherwise there will be 2 queens in same row which is illegal
            */
                if(maze[x+1][i]== 0)
                    n_q(temp, maze, x+1, i, s+1);
        }
        if(temp[x][y] == 'Q')
            temp[x][y] = '.';
        for(int i = 0; i < n; i++){
            if(x+i< n && y + i < n && maze[x+i][y+i] == s) maze[x+i][y+i] = 0;
            if(x+i< n && y - i >= 0 && maze[x+i][y-i] == s) maze[x+i][y-i] = 0;
            if(x-i>= 0 && y + i < n && maze[x-i][y+i] == s) maze[x-i][y+i] = 0;
            if(x-i>= 0 && y - i >= 0 && maze[x-i][y-i] == s) maze[x-i][y-i] = 0;
            if(maze[x][i] == s) maze[x][i] = 0;
            if(maze[i][y] == s) maze[i][y] = 0;
        }
        return;
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<int>> maze(n, vector<int> (n, 0));
        vector<string> temp(n, string  (n , '.'));
        /* 
        * There will always be a queen in first row of nXn, n queen
        * Assuming that time complexity reduced y 1/n
        */
        for(int i = 0; i < n; i++)
            n_q(temp, maze, 0, i, 1);
        
        // vector<vector<string>> yes;
        // for(auto &it: ans){
        //     yes.push_back(it);
        // }
        return ans;
    }
};