#define grap unordered_map< int, vector<int> > 

class Solution {
public:
    
    int snakesAndLadders(vector<vector<int>>& board) {
        grap graph;
        int n = board.size();
        vector<int> nums;
        
        int k = 0; bool flag = true;
        for(int i = n-1; i >= 0; i--){
            if(flag == true){
                for(int j = 0; j <= n-1; j++){
                    if(board[i][j] == -1){
                        nums.push_back(k+1);
                    }
                    else{
                        nums.push_back(board[i][j]);
                    }
                    k++;
                }
                flag = false;
            }
            else{
                for(int j = n-1; j >= 0; j--){
                    if(board[i][j] == -1){
                        nums.push_back(k+1);
                    }
                    else{
                        nums.push_back(board[i][j]);
                    }
                    k++;
                }
                flag = true;
            }
        }
        for(int i = 0; i < n*n; i++){
            for(int j = i+1; j <= min(i+6, n*n-1); j++){
                if(nums[j] != i+1){
                    graph[i+1].push_back(nums[j]);
                }
            }
        }
        // for(int i = 1; i <= n*n; i++){
        //     cout<<i<<" : ";
        //     for(auto it : graph[i]) cout<<it<<" ";
        //     cout<<endl;
        // }
        int len = 0;
        vector<int> visited(n*n+1, 0);
        queue<int> q;
        q.push(1);
        while(!q.empty()){
            int size = q.size();
            for(int i = 0; i < size; i++){
                int f = q.front(); q.pop();
                if(f == n*n) return len;
                for(auto &node : graph[f]){
                    if(visited[node] == 0){
                        q.push(node);
                        visited[node] = 1;
                    }
                }
            }
            len++;
        }
        
        return -1;
    }
};