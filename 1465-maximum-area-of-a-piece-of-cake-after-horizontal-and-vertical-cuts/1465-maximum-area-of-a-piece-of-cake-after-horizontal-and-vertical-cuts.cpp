class Solution {
public:
    typedef long long ll;
    ll multiply(ll a, ll b, ll mod)
    {
        return ((a % mod) * (b % mod)) % mod;
    }
    int M = 1e9 + 7;
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        int max_bred = INT_MIN;
        int max_len = INT_MIN;
        int prev = 0;
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
        for(auto &cut : horizontalCuts){
            max_len = max(max_len, cut - prev);
            prev = cut;
        }
        max_len = max(max_len, (h - *(--horizontalCuts.end())));
        prev = 0;
        for(auto &cut : verticalCuts){
            max_bred = max(max_bred, cut - prev);
            prev = cut;
        }
        max_bred = max(max_bred, (w - *(--verticalCuts.end())));
        return multiply(max_bred, max_len, 1e9+7);    
    }
};