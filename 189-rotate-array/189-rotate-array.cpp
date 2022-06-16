/* * 
 * Reverse whole array
 * Reverse first k
 * Reverse reverse remaining
 */
class Solution {
public:
    void reverse(vector<int> &nums, int s, int e){
        int m = (s+e)>>1;
        while(s < e){
            swap(nums[s], nums[e]);
            s++; e--;
        }
    }
    void rotate(vector<int>& nums, int k) {
        int n = nums.size()-1;
        if(k == 0) return;
        k = k % nums.size();
        reverse(nums,0, n);
        reverse(nums,0, k-1);
        reverse(nums,k, n);
    }
};
































/*
class Solution {
public:
    void Rotate(vector<int> &nums, int begin, int k, int count){
        int n = nums.size();
        // if(n-1-begin < k) return;
        if(count == 0){
           return;
        }
        
        for(int i = n-k ; i < nums.size(); i++){
            swap(nums[i], nums[begin]);
            begin++;
        }
        // k = n-k;
        Rotate(nums, begin, k, count-1);
    }
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        if(k){
            int count = n/k;
            Rotate(nums, 0, k, count);
        }
        
    }
};
*/
/*
 int calculate (int i, int n, int k){
        if(i < n-k)
            return i + k;
        else
            return i - (n-k);
    }
    void rotate(vector<int>& nums, int k) {
        int i = k;
        int val = nums[k];
        k = k % nums.size();
        for(int j = 0; j  < k; j++){
            
            int f = calculate(i, nums.size(), k); 
            cout<<f<<" ";
            int temp = nums[f];
            nums[f] = val;
            
            val = temp;
            i = f;
        }
    }
*/