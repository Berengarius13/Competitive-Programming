class Solution {
public:
    int max_len = 0;
    int lcs(vector<int> &text1, vector<int> &text2, int i, int j, vector<vector<int>> &memo){
        if(memo[i][j] != -1) return memo[i][j];
        if(i == text1.size() || j == text2.size()) return 0;
        
        int a = 0; int b = 0; int c = 0;
        if(text1[i] == text2[j])
            a = 1 + lcs(text1, text2, i+1, j+1, memo);
        //else{
            b = lcs(text1, text2, i+1, j, memo);
            c = lcs(text1, text2, i, j+1, memo);
        //}
        memo[i][j] = a;
        max_len = max(max_len, a);
        return a;
    }
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> memo(nums1.size()+1, vector<int> (nums2.size()+1, -1));
        lcs(nums1, nums2, 0, 0, memo);
        // for(int i = 0; i < memo.size(); i++){
        //     for(int j = 0; j < memo[0].size(); j++)
        //         max_len = max(max_len, memo[i][j]);
        // }
        return max_len;
    }
};