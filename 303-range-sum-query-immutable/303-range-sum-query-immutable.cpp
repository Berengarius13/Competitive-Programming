class NumArray {
public:
    vector<int> numbers;
    NumArray(vector<int>& nums) {
        numbers = nums;
    }
    
    int sumRange(int left, int right) {
        int temp = 0;
        for(int i = left; i <= right; i++)
            temp += numbers[i];
        return temp;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */