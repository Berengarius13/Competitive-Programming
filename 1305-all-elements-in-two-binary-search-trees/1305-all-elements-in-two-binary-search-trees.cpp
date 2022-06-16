
class Solution {
public:
    void dfs(TreeNode* node, vector<int> &arr){
        if(node == NULL) return;
        
        dfs(node->left, arr);
        arr.push_back(node->val);
        dfs(node->right, arr);
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> a, b;
        dfs(root1, a); 
        dfs(root2, b);
        vector<int> ans(a.size()+b.size());
        int x = 0; 
        int y = 0;
        int z = 0;
        while(x< a.size() && y < b.size()){
            if(a[x] > b[y]){
                ans[z] = b[y];
                y++; z++;
            }
            else{
                ans[z] = a[x];
                x++; z++;
            }
        }
        while(x < a.size()){
            ans[z] = a[x];
            x++; z++;
        }
        while(y < b.size()){
            ans[z] = b[y];
            y++; z++;
        }
        return ans;
    }
};