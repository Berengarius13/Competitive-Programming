class Solution {
public:
    unordered_set<string> ans;
    void combi(string temp, int i, int &n, int size){
        if(size >= 2*n){
            ans.insert(temp);
            return;
        }
        while(temp[i] != ' ')
            i++;
        if(i >= 2*n) return;
        temp[i] = '(';
        for(int j = i + 1; j < 2*n; j += 2){
            if(temp[j] == ' '){
                temp[j] = ')';
                    combi(temp, i, n, size+2);
                temp[j] = ' ';
            }
        }  
    }
    vector<string> generateParenthesis(int n) {
        string temp;
        temp.resize(2*n);
        for(auto &it:temp){
            it = ' ';
        }
        combi(temp, 0, n, 0);
        vector<string> the;
        for(auto &it : ans)
            the.push_back(it);
        return the;
    }
};