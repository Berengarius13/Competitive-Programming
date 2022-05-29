/**
 * Remember why we are sorting
 * Because Sorting we don't need to check previous elements
 * If it starts from 4, then next k elements will be 4, 5, 6, 7 .. k elements
 * When you use them just reduce their frequency
 * If frequency is less than zero, aka we need the element and it is not there
 * Than return false
 */

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