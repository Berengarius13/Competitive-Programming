class Solution {
public:
	vector<int> searchRange(vector<int>& nums, int target) {
		int left = get_first_element_position(nums, target);
		int right = get_last_element_position(nums, target);
		return left <= right ? vector<int>{left, right} : vector<int>(2, -1);
	}
private:
	int get_first_element_position(vector<int>& nums, int target){
		int left = 0, right = nums.size() - 1, mid;
		while ( left <= right )
		{
			mid = (right + left) / 2;
			if ( nums[mid] < target) left = mid + 1;
			else right = mid - 1;
		}
		return left;
	}
	int get_last_element_position(vector<int>& nums, int target){
		int left = 0, right = nums.size() - 1, mid;
		while ( left <= right )
		{
			mid = (right + left) / 2;
			if ( nums[mid] <= target ) left = mid + 1;
			else right = mid - 1;
		}    
		return right;
	}        
};


/*
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int s = 0; 
        int e = nums.size()-1;
        while(e>=s){
            int mid = (s+e)>>1;
            if(nums[mid] < target)
                s = ++mid;
            else if(nums[mid] > target)
                e = --mid;
            else{
                if(nums[s] < target)
                    s++;
                else if(nums[e] > target)
                    e--;
                if(nums[s] == target && nums[e] == target) break;
            }
        }
        vector<int> ans;
        if(s > e) ans = {-1, -1};
        else ans = {s , e};
        return ans;
    }
};
*/