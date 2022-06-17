class Solution {
public:
    int longestPalindrome(string s) {
        vector<int> count(256);
        for (char c : s)
            ++count[c];
        int odds = 0;
        for (int c : count)
            odds += c & 1;
        return s.size() - odds + (odds > 0);
    }
};