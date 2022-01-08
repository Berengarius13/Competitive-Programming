class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {

        
        vector<int> temp, ans;
        for(int i =0; i< nums.size(); i++)
        {      if(nums[i]<0)
                    temp.push_back(nums[i]);
                
         } 
        for(int i =0; i < temp.size()/2; i++)
                swap(temp[i], temp[temp.size()-i-1]);
        
        for(auto &t: temp)
            t = abs(t);
        
         
        int m = nums.size();
        int n = temp.size();
        int i =n; 
        int j =0;
        while(i<m && j <n){
            if(nums[i]>temp[j])
            {
                ans.push_back(temp[j]);
                j++;
            }
            else{
                ans.push_back(nums[i]);
                i++;
            }
        }
        while(i<m){
            ans.push_back(nums[i]);
            i++;
        }
        while(j<n){
            ans.push_back(temp[j]);
            j++;
        }
        
        
        
        for(auto &an: ans)
            an = an*an;    
       
       return ans;     
    }
};