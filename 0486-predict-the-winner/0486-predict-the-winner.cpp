#define vi vector<int>
class Solution {
public:
    bool fun(vi &nums, int sumA, int sumB, bool turn, int i, int j){
        if(i > j){
            if(sumA >= sumB) {
                return true;
            }
            return false;
        }
        bool a, b;
        if(turn){
            a = fun(nums, sumA + nums[i], sumB, !turn, i+1, j);
            b = fun(nums, sumA + nums[j], sumB, !turn, i, j-1);
            return a || b;
        }
        else{
            a = fun(nums, sumA , sumB + nums[i], !turn, i+1, j);
            b = fun(nums, sumA , sumB + nums[j], !turn, i, j-1);
            return a && b;
        }
        
    }
    bool PredictTheWinner(vector<int>& nums) {
        return fun(nums, 0, 0, true, 0, nums.size()-1);
    }
};