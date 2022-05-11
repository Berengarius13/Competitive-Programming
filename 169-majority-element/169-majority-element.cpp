class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int element = 0;
        int count = 0;
        for(auto &num: nums){
            if (count  == 0)
                element = num;
            if(element == num)
                count++;
            else
                count--;
        }
        return element;
    }
};
/*
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> m;
        for(auto &num : nums){
            m[num]++;
        }
        int ans;
        for(auto &it : m){
            if(it.second> (nums.size()/2))
            {
                ans = it.first;
            }
        }
        return ans;
    }
};
*/