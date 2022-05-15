class Solution {
public:
    vector<string>ans;
    vector<string>generateParenthesis(int n) {
        f("",n,n);
        return ans;
    }
    void f(string s, int open, int close){
        if(open==0 && close==0){
            ans.push_back(s);
            return;
        }
        if(open>0)f(s+"(",open-1,close);
        if(open<close)f(s+")",open,close-1);
    }
};
/*
First approach using sets
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
                temp[j] = ' ';// Backtrack
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
*/