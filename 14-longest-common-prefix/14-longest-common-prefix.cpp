class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int size = INT_MAX;
        for(auto &str : strs)
            size = min((int)str.size(), size);
        
        string ans;
        for(int i = 0; i < size; i++){
            bool flag = true;
            char comp = strs[0][i];
            for(int j = 0; j < strs.size(); j++){
                if(j != 0 && comp != strs[j][i]){
                    flag = false; break;
                }
                comp = strs[j][i];
            }
            if(flag)
                ans += comp;
            else break;
        }
        return ans;
    }
};