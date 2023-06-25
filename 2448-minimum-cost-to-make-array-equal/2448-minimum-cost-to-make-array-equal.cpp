#define pll pair<long long, long long> 
#define ll long long 
#define vll vector<long long> 
class Solution {
public:
    long long minCost(vector<int>& arr, vector<int>& cost) {
        vector<pll> nums;
        int n = arr.size();
        for(int i = 0; i < n; i++){
            nums.push_back({arr[i], cost[i]});
        }
        sort(nums.begin(), nums.end());
        vll prefix = {0};
        ll sum = 0;
        for(int i = 0; i < n; i++){
            sum += nums[i].second;
            prefix.push_back(sum);
        }
        ll lastCost = 0; // p[i+1] - p[j];
        for(int i = 0; i < n; i++){
            lastCost += abs(nums[0].first - nums[i].first) * nums[i].second;
        }
        ll ans = lastCost;
        cout << lastCost << " ";
        for(int i = 1; i < n; i++){
            ll p1 = prefix[i] - prefix[0];
            ll p2 = prefix[n] - prefix[i];
            lastCost +=( (nums[i].first-nums[i-1].first) *p1) + ((nums[i-1].first - nums[i].first) * p2);
            cout <<(nums[i-1].first - nums[i].first) * p2<< " ";
            ans = min(lastCost, ans);
        }
        return ans;
    }
};