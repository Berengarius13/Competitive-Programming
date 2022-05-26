/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/*
* Decide_dfs, returns the value of target_i, to previsous recursion calls
* Dfs function, does depth first search and find the value at given distance and inserts in         answer
* Main idea is that target we will remember height of target node.
* From target node do dfs, initial distance i = 0, and all at k are added
* The first parent of will be at 1 distance from target, thus we will add 1 to initial distanc
  thus starting ditance for dfs will be i+1 = 1
* This continues, as we go to parent of parent of target, intial distance changes to i+2.
*/
class Solution {
public:
    vector<int> ans;
    int decide_dfs(TreeNode* node, TreeNode* target, int i, int &k){
        if(node == NULL) return 0;
        
        int a = decide_dfs(node->left, target, i+1, k);
        int b = decide_dfs(node->right, target, i+1, k);
        
        if(b){
            if(b-i == k) ans.push_back(node->val); // Edge case, if parent is at k distance
            dfs(node->left, b-i+1, k);
            // If b is not 0, thus we have already done dfs on b, thus we do dfs on a branch side
            // Remember to edit the inital distance
        }
        if(a){
            if(a-i == k)ans.push_back(node->val);
            dfs(node->right, a-i+1, k);
        }
        if(node->val == target->val){
            dfs(node, 0, k);
            return i;
        }
        return a+b; // If a+b = 0, target is not found yet!
                    // If a+b = 1, target if found, and remeber to not do dfs again on that                              branch
    }
    // A function that simply remembers initial distance, and remembers nodes at k distance.
    void dfs(TreeNode* node, int i, int &k){
        if(node == NULL) return;
        if(i == k)
            ans.push_back(node->val);
        dfs(node->left, i+1, k);
        dfs(node->right, i+1, k);
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        decide_dfs(root, target, 0, k);
        return ans;
    }
};