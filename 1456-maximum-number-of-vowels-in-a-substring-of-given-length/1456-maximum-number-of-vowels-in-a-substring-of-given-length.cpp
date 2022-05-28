/** 
 * Sliding window like rabin karp
 */
class Solution {
public:
    bool isVovel(char c){
        if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
            return true;
        return false;
    }
    int maxVowels(string s, int k) {
        int max_count = 0;
        int count = 0;
        for(int i = 0; i < s.size(); i++){
            if(isVovel(s[i])) count++;
            if(i >= k){
                if(isVovel(s[i-k])) count--;
            }
            max_count = max(max_count, count);
        }
        return max_count;
    }
};