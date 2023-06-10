// Debug Template, copied from Mikel_Arteta_8 (https://codeforces.com/blog/entry/68809)
void __print(int x) {cout << x;}
void __print(long x) {cout << x;}
void __print(long long x) {cout << x;}
void __print(unsigned x) {cout << x;}
void __print(unsigned long x) {cout << x;}
void __print(unsigned long long x) {cout << x;}
void __print(float x) {cout << x;}
void __print(double x) {cout << x;}
void __print(char x) {cout << '\'' << x << '\'';}
void __print(const char *x) {cout << '\"' << x << '\"';}
void __print(const string &x) {cout << '\"' << x << '\"';}
void __print(bool x) {cout << (x ? "true" : "false");}
template<typename T, typename V>
void __print(const pair<T, V> &x) {cout << '{'; __print(x.first); cout << ','; __print(x.second); cout << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cout << '{'; for (auto &i: x) cout << (f++ ? "," : ""), __print(i); cout << "}";}
void _print() {cout << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cout << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cout << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

class Solution {
public:
    int trap(vector<int>& nums) {
        multimap<int, int, greater<int>> mp; // peak => index
        int n = nums.size();
        for(int i = 0; i < nums.size(); i++){
            if(i == 0 && i + 1 < n && nums[i] > nums[i+1]){
                mp.insert({nums[i], i});
            }
            else if(i == nums.size()-1 && i-1 >= 0 && nums[i] > nums[i-1]){
                mp.insert({nums[i], i});
            }
            else{
                if(i + 1 < n && i - 1 >= 0 && (nums[i] > nums[i-1] && nums[i] > nums[i+1] || nums[i] >= nums[i-1] && nums[i] > nums[i+1] || nums[i] >= nums[i+1] && nums[i] > nums[i-1]) ){
                    mp.insert({nums[i], i});
                }
            }
        }
        int l = -1;
        int r = -1;
        int ans = 0;
        debug(mp);
        for(auto it = mp.begin(); it != mp.end(); ++it){
            if(it == mp.begin()){
                l = it->second;
                r = it->second;
            }
            else{
                int id = it->second;
                int peak = it->first;
                if(id > r){
                    for(int i = r+1; i < id; i++){
                        if(peak - nums[i] > 0) ans += peak - nums[i];
                    }
                    r = id;
                }
                else if(id < l){
                    for(int i = id+1; i < l; i++){
                        if(peak - nums[i] > 0) ans += peak - nums[i];
                    }
                    l = id;
                }
            }
        }
        return ans;
    }
};