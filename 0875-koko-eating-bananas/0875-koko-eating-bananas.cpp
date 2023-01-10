class Solution {
public:
    bool isPossible(vector<int> &nums, int h, int speed){
        int n = nums.size();
        int time = 0;
        for(int i = 0; i < n; i++){
            if(nums[i]%speed == 0){
                time += nums[i]/speed;
            }
            else{
                time += (nums[i]/speed + 1);
            }
            if(time > h) return false;
        }
        return time <= h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int s = 1;
        int e = INT_MIN;
        for(auto &num : piles) e = max (e, num);
        while(s <= e){
            int mid = (e + (s-e)/2);
            if(isPossible(piles, h, mid)){
                e = mid - 1;
            }
            else{
                s = mid + 1;
            }
        }
        return s; 
    }
};