class Solution {
public:
    // Heapify 
    // n = We need to difine how much of heap we want to create
    void heapify(vector<int> &nums,int n,int i){
        
        int largest = i;
        int left = 2*i + 1; 
        int right = 2*i + 2; 
        if(left < n && nums[largest]< nums[left]) 
            largest = left;
        if(right < n && nums[largest] < nums[right])
            largest = right;
        if(i != largest){
            swap(nums[largest], nums[i]);
            heapify(nums, n,largest);
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        for(int i = nums.size()/2-1; i >= 0; i--){
            heapify(nums, nums.size(),i);
        }
        for(int i = nums.size()-1;  i >=0; i--){
            swap(nums[0],nums[i]);
            heapify(nums, i,0);
        }
        return nums;
            
    }
};