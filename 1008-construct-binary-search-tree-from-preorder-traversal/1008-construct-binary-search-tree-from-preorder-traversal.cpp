class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder, int max_val = INT_MAX) {
        if (i == preorder.size() || preorder[i] > max_val) return NULL;
        
        TreeNode* root = new TreeNode(preorder[i++]);
        
        root->left = bstFromPreorder(preorder, root->val);
        root->right = bstFromPreorder(preorder, max_val);
        
        return root;
    }
    
private:
    int i = 0;
};











































// /**
//  * Definition for a binary tree node.
//  * struct TreeNode {
//  *     int val;
//  *     TreeNode *left;
//  *     TreeNode *right;
//  *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//  * };
//  */
// class Solution {
// public:
//  TreeNode* combi(vector<int> &preorder, vector<int> &inorder, unordered_map<int,int> &mp, int root, pair<int, int> range){ 

//         if(range.second< range.first) return NULL;
//         TreeNode* node = new TreeNode(preorder[root]);
//         int deref_i = mp[preorder[root]]; // The root value in inorder
//         // Left side calculation
//         int left_root = root+1; // Root value according to preorder
//         pair<int, int> left_range = {range.first, deref_i-1};
//         // Right side calculation
//         int right_root = left_root+(left_range.second - left_range.first)+1;// Formula to get starging node of right subtree, 
//                                                                             // using range of left subtree of inorder, as length is absolute
//         pair<int, int> right_range = {deref_i+1, range.second};
//         TreeNode* left = combi(preorder, inorder, mp, left_root, left_range);
//         TreeNode* right = combi(preorder, inorder, mp, right_root, right_range);
        
//         node->left = left;
//         node->right = right;
//         return node;
//     }
//     TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
//         unordered_map<int, int> mp;
//         for(int i = 0; i < inorder.size(); i++)
//             mp.insert({inorder[i], i});
//         pair<int, int> range = {0, inorder.size()-1}; // Range of inorder aka left to right in inorder
//         int root = 0; // Root of tree, aka first node of preorder, root+1 for left and root+1+l+1, for right, 
//                   // l is length of left that we get from inorder range
//         return combi(preorder, inorder, mp, root, range);    
//     }    
//     TreeNode* bstFromPreorder(vector<int>& preorder) {
//         vector<int> inorder = preorder;
//         sort(inorder.begin(), inorder.end());
//         return buildTree(preorder, inorder);
//     }
// };