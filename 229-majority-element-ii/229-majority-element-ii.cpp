/*
* More than 2 elements can't appear more than n/3 times
* There can be no majority elelmnt, 1 or two 
* n/3 + 1 (+) n/3 + 1 (+) x = n
  then x = n/3 - 2
* So it is impossible to have majority elements more than 2   
* Similar to moore voting algorithm
*/
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int element1  = -1; 
        int element2 = -1;
        int count1 = 0;
        int count2 = 0;
        for(auto num : nums){
            if(element1 == num){
                count1++;
            }
            else if(element2 == num){
                count2++;
            }
            else if(count1 == 0){
                count1 = 1; 
                element1 = num;
            }
            else if(count2 == 0){
                count2 = 1;
                element2 = num;
            }
            else{
                count1--; count2--;
            }
        }
        int n = nums.size();
        count1 = 0; count2 = 0;
        for(auto num : nums){
            if(num == element1)
                count1++;
            if(num == element2)
                count2++;
        }
        vector<int> ans;
        if(count1 > n/3)
            ans.push_back(element1);
        if(count2 > n/3 && element2 != element1)
            ans.push_back(element2);
        return ans;
        
    }
};