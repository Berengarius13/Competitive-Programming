
class Solution {
public:
    TreeNode* combi(vector<int>& inorder, vector<int>& postorder, unordered_map<int,int> &mp,
                    int root, pair<int,int> range)
    {
        if(range.first > range.second) return NULL;
        TreeNode* node = new TreeNode(postorder[root]);
        int deref = mp[postorder[root]];
        // Right
        int right_root = root-1;
        pair<int,int> right_range = {deref+1, range.second};
        // Left
        int left_root = right_root - (right_range.second-right_range.first)-1;
        pair<int,int> left_range = {range.first, deref-1};
        
        TreeNode* left = combi(inorder, postorder, mp, left_root, left_range);
        TreeNode* right = combi(inorder, postorder, mp, right_root, right_range);
        
        node->left = left; node->right = right;
        return node;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int> mp;
        for(int i = 0; i < inorder.size(); i++)
            mp.insert({inorder[i], i});
        int root = postorder.size()-1;
        pair<int,int> range = {0, postorder.size()-1};
        return combi(inorder, postorder, mp, root, range);
    }
};