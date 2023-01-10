#define ll long long
class Solution {
public:
    bool isPossible(vector<int> &nums, long long k, long long size){
        ll num_piles = 0;
        for(auto num : nums){
            num_piles += (num/size);
        }
        return num_piles >= k;
        
    }
    int maximumCandies(vector<int>& candies, long long k) {
        int s = 1;
        int e = INT_MIN;
        for(auto num : candies) e = max(e, num);
        while(s <= e){
            int mid = (e + (s-e)/2);
            if(isPossible(candies, k, mid)){
                s = mid + 1;
            }
            else{
                e = mid - 1;
            }
        }
        return e;
    }
};