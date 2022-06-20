class Solution {
public:
    string lcs(string &str1, string &str2, int i, int j, vector<vector<string>> &memo){
        if(memo[i][j] != ".") return memo[i][j];
        if(i == str1.size() || j == str2.size()) return string();
        
        string a, b, c;
        if(str1[i] == str2[j]){
            a = str1[i] + lcs(str1, str2, i+1, j+1, memo);
            memo[i][j] = a;
            return a;
        }
        else{
            b = lcs(str1, str2, i+1, j, memo);
            c = lcs(str1, str2, i, j+1, memo);
            if(b.size() > c.size()){
                memo[i][j] = b;
                return b;
            }
            else{
                memo[i][j] = c;
                return c;
            }
        }
        return string();
    }
    string shortestCommonSupersequence(string str1, string str2) {
        vector<vector<string>> memo(str1.size()+1, vector<string> (str2.size()+1, "."));
        string LCS = lcs(str1, str2, 0, 0, memo);
        int a,b,k; a = 0; b = 0; k = 0;
        string ans;
        while(k < LCS.size()){
            while(str1[a] != LCS[k]){
                ans.push_back(str1[a]);
                a++;
            }
            if(str2[b] != LCS[k]){
                ans.push_back(str2[b]);
                b++;
            }
            if(str2[b] == LCS[k] && str1[a] == LCS[k]){
                ans.push_back(LCS[k]);
                a++; b++; k++;
            }
        }
        while(a < str1.size()){
            ans.push_back(str1[a]); a++;
        }
        while(b < str2.size()){
            ans.push_back(str2[b]); b++;
        }
        return ans;
    }
};