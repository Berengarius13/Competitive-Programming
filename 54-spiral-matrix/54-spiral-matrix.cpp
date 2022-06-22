/**
 * Basic DFS go like this
 * Right (then again you try to go right but can't so)
 * Down (then try right, but can't, then down, but can't so)
 * Left (then right can't, down can't, left can't so)
 * Up but.. just as you go just one step up you will go 
   immediately right, cuz in recursion is called again.
 * That's not what we want, we want it to go as up as possible
 * Solution? we will return "true" from last left call
 * That is cue to go as up as as posible
 * Thus we run a for loop, reducing i as much as possible
 * Then simply call the dfs for RIGHT from there
 * Simple this whole cycle repeats
 */

class Solution {
public:
    vector<int> ans;
    bool dfs(vector<vector<int>>& matrix, int i, int j){
        if(i < 0 || i >= matrix.size() || j < 0 || j >= matrix[0].size()) return true;
        if(matrix[i][j] == -300) return true; // AKA visited
        ans.push_back(matrix[i][j]);
        matrix[i][j] = -300;
        dfs(matrix, i, j+1);
        dfs(matrix, i+1, j);
        bool a = dfs(matrix, i, j-1);
        if(a){
            while(i-1 >= 0 && matrix[i-1][j] != -300){
                ans.push_back(matrix[i-1][j]); matrix[i-1][j] = -300;
                i--;
            }
           dfs(matrix, i, j+1);
        }
        return false;
    }
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int i = 0;
        int j = 0;
        dfs(matrix, i, j);
        return ans;
    }
};
