#define ll long long
#define vll vector<long long> 
class Solution {
public:
    
    bool reorderedPowerOf2(int n) {
        vll nums;
        ll x = 1;
        while(x <= 1e9){
            nums.push_back(x);
            x *= 2;
        }
        string s = to_string(n);
        sort(s.begin(), s.end());
        for(int i = 0; i < nums.size(); i++){
            string t = to_string(nums[i]);
            sort(t.begin(), t.end());
            if(s == t) return true;
        }
        return false;    
            
    }
};