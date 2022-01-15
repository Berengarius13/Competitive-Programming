class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        vector<int> temp; 
        bool ans=false;
        int s = 0; 
        int e = matrix.size()-1;
        int n = matrix[0].size()-1;
        int v{0};
        int m;
        if(matrix.size()==1 && matrix[0].size()==1){
            if(matrix[0][0]==target)
                return true;
             else
                return false;
        }       
        if(matrix.size()!=1){
        while(s<=e)
        {   
           m = (s+e)/2;
            if(target>=matrix[m][0]&& target<=matrix[m][n]){
                v = m;
                break;
            }
            else if (target< matrix[m][0] && target < matrix[m][n]){
                m = e; e--;
            }
            else if (target > matrix[m][0] && target > matrix[m][n]){
                m = s; s++;
            }
        }
    }
        
        for(int i =0; i<matrix[0].size(); i++ ){
            if(matrix[v][i] == target){
                ans= true; break;}
        }
        
        return ans;
    }
};
      
        // int s = 0; 
        // int e = nums.size()-1;
        // int ans = -1;
        // if(e ==0){
        //     if(nums[0]== target)
        //         return 0;
        // }
        // while(s<=e)
        // {
        //     int m = (s+e)/2; 
        //     if(target < nums[m]){
        //         m--; 
        //         e=m;
        //     }
        //     else if(target > nums[m]){
        //         m++;
        //         s =m;
        //     }
        //     else
        //         return m;
        // }