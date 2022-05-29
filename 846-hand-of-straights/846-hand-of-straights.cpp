class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        map<int, int> mp;
        for(auto &num:hand)
            mp[num]++;
        
        for(auto [key, value]: mp){
            
            while(mp[key]){
                
                for(int i = key; i < key+groupSize; i++){
                    
                    mp[i]--;
                    if(mp[i] < 0)
                        return false;
                }
            }
        }
        return true;
    }
};