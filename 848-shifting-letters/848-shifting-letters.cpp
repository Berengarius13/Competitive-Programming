class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        for(int i = shifts.size()-2; i >= 0; i--){
            shifts[i] += shifts[i+1];
            shifts[i] %= 26;
        }
        for(int i = 0; i < s.size(); i++){
            int asci = s[i]-'a';
            asci = (asci+shifts[i]) %26;
            s[i] = asci + 'a';
        }
        return s;
    }
};