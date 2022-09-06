/*
* store all possible values  of c + d
* Look up in array all possible values of -a-b
*/
class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) 
    {
        int ans = 0;
        int n = nums1.size();
        unordered_map<int, int> mp;
        for(int i = 0; i < n; i++){
            int c = nums3[i];
            for(int j = 0; j < n; j++){
                int d = nums4[j];
                mp[c+d]++;
            }
        }
        for(int i = 0; i < n; i++){
            int a = nums1[i];
            for(int j  = 0; j < n; j++){
                int b = nums2[j];
                ans += mp[-a-b];
            }
        }
        return ans;
    }
};