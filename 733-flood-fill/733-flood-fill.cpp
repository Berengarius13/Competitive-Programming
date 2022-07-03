class Solution {
public:
    void dfs(vector<vector<int>>& image, int i, int j, int &color, int to_visit){
        if(i < 0 || j < 0 || i >= image.size() || j >= image[0].size()) return;
        if(image[i][j] != to_visit) return;
        image[i][j] = color;
        dfs(image, i+1, j, color, to_visit);
        dfs(image, i, j+1, color, to_visit);
        dfs(image, i-1, j, color, to_visit);
        dfs(image, i, j-1, color, to_visit);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int to_visit = image[sr][sc];
        if(to_visit == color) return image;
        dfs(image, sr, sc, color, to_visit);
        return image;
    }
};