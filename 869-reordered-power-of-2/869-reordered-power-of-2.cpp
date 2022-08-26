class Solution {
public:
    bool reorderedPowerOf2(int n) {
        unordered_set<string> s;
        for(int i = 0; i < 31; i++){
            long num = 1 << i;
            string str = to_string(num);
            sort(str.begin(), str.end());
            s.insert(str);
        }
        string str = to_string(n);
        sort(str.begin(), str.end());
        return !(s.find(str) == s.end());
    }
};