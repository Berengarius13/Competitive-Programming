class Solution {
public:
    string largestNumber(vector<int>& nums) {
        multimap<int,int> mp; // Use reverse iterator
        for(int i = 0; i < nums.size(); i++){
            int num = nums[i];
            if(num == 0){
                mp.insert({0, i});
                continue;
            }
            vector<int> number;
            while(num){
                int lsb = num % 10;
                number.push_back(lsb);
                num /= 10;
            }
            reverse(number.begin(), number.end());
            num = nums[i];
            int j = 0; 
            while(num <= 1e9/10){
                if(j == number.size()) j = 0;
                num = num*10;
                if(num > 1e9 - number[j]) break;
                num += number[j];
                j++; 
            }
            mp.insert({num, i});
        }
        string ans;
        bool flag = false;
        for(auto it = mp.rbegin(); it != mp.rend(); ++it){
            if(nums[it->second] != 0) flag = true;
            ans += to_string(nums[it->second]);
        }
        if(!flag){
            return "0";
        }
        return ans;
    }
};