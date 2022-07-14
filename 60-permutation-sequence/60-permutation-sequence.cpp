class Solution {
public:
    vector<int> fact = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};
    string getPermutation(int n, int k) {
        k = k - 1;
        string ans;
        vector<int> mp;
        for(int i = 0; i < n; i++)
            mp.push_back(i+1);
        
        while(n){
            int priority = k/fact[n-1];
            ans  +=  mp[priority] + '0';
            mp.erase(mp.begin()+priority);
            k = k - (fact[n-1]* priority);
            n = n-1;
        }
        return ans;
    }
};