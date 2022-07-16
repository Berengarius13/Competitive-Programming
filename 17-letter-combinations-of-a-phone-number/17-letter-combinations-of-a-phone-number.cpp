class Solution {
public:
    vector<string> ans;
    vector<string> phone = {" ", " ", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    void dfs(string &digits, int i, string &temp){
        if(i == digits.size()){
            ans.push_back(temp); return;
        }
        int num = digits[i] - '0';
        for(auto &ch : phone[num]){
            temp +=ch;
            dfs(digits, i+1, temp);
            temp.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0) return ans;
        string temp;
        dfs(digits, 0, temp);
        return ans;
    }
};