class Solution {
public:
    int count = 0; 
    void bcktrk(vector<vector<int>>& grid, int i, int j, pair<int,int> &end, int k){
        if(i == end.first && j == end.second && k == 1){
            count++; return;
        }
        if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || k <= 1) return;
        if(grid[i][j] != 0) return;
        
        grid[i][j] = -1;
        bcktrk(grid, i+1, j, end, k-1);
        bcktrk(grid, i, j+1, end, k-1);
        bcktrk(grid, i-1, j, end, k-1);
        bcktrk(grid, i, j-1, end, k-1);
        grid[i][j] = 0;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        pair<int, int> start, end;
        start.first = 0; start.second = 0; 
        end.first = 0; end.second = 0;
        int not_walk = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == 1){
                    start.first = i; start.second = j;
                }
                else if(grid[i][j] == 2){
                    end.first = i; end.second = j;
                }
                else if(grid[i][j] == -1)
                    not_walk++;
            }
        }
        grid[start.first][start.second]= 0;
        int k = (grid.size()*grid[0].size()) - not_walk;
        bcktrk(grid, start.first, start.second, end, k);
        return count;
    }
};