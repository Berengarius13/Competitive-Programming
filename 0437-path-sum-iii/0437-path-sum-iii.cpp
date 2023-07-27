#define ll long long
class Solution {
public:
    void dfs(TreeNode* root, ll target, unordered_map<ll, ll> &mp, int &count, ll sum, bool insert){
        if(root == NULL) return;
        if(root->val + sum == target) count++;
        // if(insert){
        //      mp[root->val + sum]++;
        // }
        // else{
        //     count += mp.count(target - (root->val + sum));
        // }
        dfs(root->left, target, mp, count, sum + root->val, insert);
        dfs(root->right, target, mp, count, sum + root->val, insert);
    }
    int pathSum(TreeNode* root, int target) {
        if(root == NULL) return 0;
        int a = pathSum(root->left, target);
        int b = pathSum(root->right, target);
        int x = 0;
        unordered_map<ll, ll> mp;
        dfs(root->left, target, mp, x, root->val, true);
        if(root->val == target) x++;
        dfs(root->right, target, mp, x, root->val, false);
        return x + a + b;
    }
};