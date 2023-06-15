#define ll unsigned long long
#define bit bitset<64>
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*, ll>> q;
        q.push({root, 1});
        ll ans = 1;
        while(!q.empty()){
            int sz = q.size();
            ll left, right;
            for(int i = 0; i < sz; i++){
                TreeNode* node = q.front().first;
                ll s = q.front().second;
                q.pop();
                if(i == 0){
                    left = s;
                }
                if(i == sz-1){
                    right = s;
                }
                if(node->left != NULL){
                    q.push({node->left, 2*s});
                }
                if(node->right != NULL){
                    q.push({node->right, 2*s+1});
                }
            }
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};