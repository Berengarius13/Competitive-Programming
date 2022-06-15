class Solution {
public:
    bool isSubsequence(string s, string t) {
        int begin = 0; bool flag = false;
        if(s.size() > t.size()) return false;
        for(int i = 0; i < s.size(); i++){
            flag = false;
            for(int j = begin; j < t.size(); j++){
                if(s[i] == t[j]){
                    begin = j+1; flag = true; break;
                }
            }
            if(flag == false) return false;
        }
        return true;
    }
};