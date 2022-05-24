/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    public:
    #define ll unsigned long long 
    void end(TreeNode *root,unordered_map<ll,ll> &m,ll h,ll c){
        if(!root){
            return ;
        }
        if(m.find(h)==m.end()){
            m.insert({h,c});
        }
        else
        {
            if(m[h]<c){
                m[h]=c;
            }
        }
        end(root->left,m,h+1,2*c);
        end(root->right,m,h+1,2*c+1);
        
    }
    void strt(TreeNode *root,unordered_map<ll,ll> &m,ll h,ll c){
        if(!root){
            return ;
        }
        if(m.find(h)==m.end()){
            m.insert({h,c});
        }
        else
        {
            if(m[h]>c){
                m[h]=c;
            }
        }
        strt(root->left,m,h+1,2*c);
        strt(root->right,m,h+1,2*c+1);
        
    }
    int widthOfBinaryTree(TreeNode* root) {
        unordered_map<ll,ll> s,e;
        end(root,e,0,0);
        strt(root,s,0,0);
        ll ans=0;
        for (auto i = s.begin(); i!=s.end(); i++)
        {
            ans=max(ans,e[i->first]-i->second+1);
            
            
        }
        return int(ans);

    }
};