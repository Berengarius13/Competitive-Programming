/*
* Use a carry variable
*/
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size()-1;
        vector<int> ans;
        int carry = 1;
        for(int i = n; i >= 0; i--){
            if(digits[i] + carry >= 10){
                carry = 1;
                ans.push_back(0);
            }
            else{
                ans.push_back(carry + digits[i]);
                carry = 0;
            }
        }
        if(carry) ans.push_back(carry);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};