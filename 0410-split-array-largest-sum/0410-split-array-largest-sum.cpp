#define ll long long int
class Solution {
public:
    bool isPossible(vector<int>&n,int mid,int m){
        int sum=0,count=1;
        for(int i=0;i<n.size();i++){
            sum+=n[i];
            if(sum>mid){
                sum=n[i];
                count++;
            }
            if(count>m)return 0;
        }
        return 1;
    }
    int splitArray(vector<int>& nums, int k) {
        // sort(nums.begin(), nums.end());
        int ans = 0;
        int s = INT_MIN;
        int e = 0;
        for(int n:nums){
            s = max(n,s);
            e += n;
        }
        // cout<<IsPossible(nums, k, 5)<<" ";
        while(s <= e){
            ll mid = (s+e)/2;
            if(isPossible(nums, mid, k)){
                e = mid - 1;
                // ans = mid;
            }
            else{
                s = mid + 1;
            }
        }
        return s;
    }
};