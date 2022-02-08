class Solution {
public:
    void sort(vector<int> &nums, int i, int n, vector<int> &ans){
        if(i+1 == n){
            if(nums[i]>nums[n]) swap(nums[i],nums[n]);
            return;
        }
        if(i==n) return;
        
        sort(nums, i, (n+i)/2, ans);
        sort(nums, ((n+i)/2)+1, n, ans);
        int a=i; 
        int m = (i+n)/2;
        int b = m+1;
        while(a<=m && b <=n){
            if(nums[a]>nums[b]){
                ans.push_back(nums[b]);
                b++;
            }
            else{
                ans.push_back(nums[a]);
                a++;
            }
        }
        while(a<=m){
            ans.push_back(nums[a]);
            a++;
        }
        while(b<=n){
            ans.push_back(nums[b]);
            b++;
        }
        m=0;
        for(int v = i; v<=n; v++){
            swap(ans[m],nums[v]);
            m++;
        }
        ans.clear();
        return;
    }
    vector<int> sortArray(vector<int>& nums) {
        vector<int> ans;
        sort(nums, 0, nums.size()-1, ans);
        return nums;
    }
};