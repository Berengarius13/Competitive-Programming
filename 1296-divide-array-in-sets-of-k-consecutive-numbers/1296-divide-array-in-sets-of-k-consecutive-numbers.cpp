class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        map<int, int> mp;
        for(auto &it : nums)
            mp[it]++;
        
        for(auto [key, value] : mp){
            
            while(mp[key]){ // While there is still frequency left loop continues
                
                for(int i = key; i < key+k; i++){ // let's say it's 1, so 1,2,3,4 must pe present
                    mp[i]--; // we used it
                    if(mp[i]< 0)
                        return false; // We need that value and it did'n existedj
                }       
            }
        }
        return true;
    }
};