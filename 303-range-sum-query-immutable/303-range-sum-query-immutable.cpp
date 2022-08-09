class NumArray {
public:
    vector<int> accumulate;
    NumArray(vector<int>& nums) {
        int sum = 0;
        for(auto num : nums){
            sum += num;
            accumulate.push_back(sum);
        }
    }
    
    int sumRange(int left, int right) {
        if(left == 0) return accumulate[right];
        return accumulate[right]-accumulate[left-1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */