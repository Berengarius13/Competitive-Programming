
class Solution {
public:
    pair<int, int> dfs(TreeNode* node, const int &start){
        if(node == NULL) return {0,0};
        
        auto left = dfs(node->left, start);
        auto right = dfs(node->right, start);
        //if(node->left == NULL && node->right == NULL) return {0,0};
        if(node->val == start){
            return {max(left.first, right.first), 1};
        }
        if(left.second >= 1){
            return {max(right.first+left.second, left.first), left.second+1};
        }
        if(right.second >= 1){
            return {max(left.first+right.second, right.first ), right.second+1};
        }
        
        return {max(left.first, right.first)+1, 0};
    }
    int amountOfTime(TreeNode* root, int start) {
        return dfs(root, start).first;
    }
};