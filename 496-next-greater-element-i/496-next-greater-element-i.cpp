class Solution {
public:
    /*
    * We are using hashing to mark values in nums2 
    * We can directly use that information in nums1
    */
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        unordered_map<int, int> ma; 
        stack<int> stak;
        int n = nums2.size()-1;
        ma[nums2[n]] = -1;
        for(int i = n-1; i>=0; i--){
            if(nums2[i]< nums2[i+1]){
                stak.push(nums2[i+1]);
                ma[nums2[i]] = nums2[i+1];
            }
            else if(nums2[i]>nums2[i+1]){
                while(!stak.empty()){
                    if(stak.top()> nums2[i]){
                       ma[nums2[i]] = stak.top();
                        stak.push(nums2[i]);
                        break;
                    }
                    else stak.pop();
                }
                if(stak.empty()){
                        stak.push(nums2[i]);
                        ma[nums2[i]] = -1;
                    }
            }
        }
        for(auto num: nums1){
            ans.push_back(ma[num]);
        }
        return ans;
    }
};