/*
* Count odds
* Subtract one odd from each odd group
* Add one odd which can be in center, 
  only when there exist one odd group
*/
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