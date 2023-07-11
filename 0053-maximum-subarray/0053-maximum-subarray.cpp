class Solution {
public:
    int absolute_max;
    int m_s(vector<int> &nums, int i){
        if(i == nums.size()) return 0;
        int res = max(nums[i], nums[i]+m_s(nums, i+1));
        absolute_max = max(res, absolute_max);
        return res;
    }
    int maxSubArray(vector<int>& nums) {
        absolute_max = nums[0];
        m_s(nums, 0);
        return absolute_max;
    }
};
/*
* Understood got it finally
* At every step you have two choices
* keep adding the previous sum
* Or start again from there
* Here no need to call recursion two times for it because we have have choice to return a value to previous call
* That value can either be total sum till then or a[i];
* total sum till then = a[i] + previsus(we get it from recursio)
* If we return a[i] then sum starts from there
* if we return summ till then then we are adding in that subarray only
* So how do you decide what to do? Well return whatever is maximum
* Now this step is confusing let me clarify
* if a[i] > a[i] + p which basically means p is -ve (wooosh!!)
* Why would you want to add deadweight to behind instead give back a[i] and start a new attemp at subaray creation
* IF p is +ve then plese add that value cuz it will defintely increase the sum
* got it?
* It's just kadanes written in confusing way!
*/