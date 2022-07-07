class Solution {
public:
    int titleToNumber(string arr) {
        int ans = 0; 
        int j = 0;
        for(int i = arr.size()-1; i >= 0; i--){
            int index = arr[i]-'A'+1;
            ans += index * pow(26, j);
            j++;
        }
        return ans;
    }
};