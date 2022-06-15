class Solution {
public:
//     void Rotate(vector<int> &nums, int begin, int k, int count){
//         int n = nums.size();
//         // if(n-1-begin < k) return;
//         if(count == 0) return;
        
//         for(int i = n-k ; i < nums.size(); i++){
//             swap(nums[i], nums[begin]);
//             begin++;
//         }
//         Rotate(nums, begin, k, count-1);
//     }
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        // cout<<k;
        // if(k){
        //     int count = n/k;
        //     Rotate(nums, 0, k, count);
        // }
        vector<int> ans;
        for(int i = n-k; i < n; i++)
            ans.push_back(nums[i]);
        for(int i = 0; i < n-k; i++)
            ans.push_back(nums[i]);
        nums = ans;
    }
};