class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int i = 0; 
        int ans = 0; 
        int maxi = 0;
        while(i+1 < prices.size()){
            
            maxi = maxi + prices[i+1] - prices[i];
            if(maxi < 0) maxi = 0;
            ans = max(maxi, ans);
            i++;
        }
        return ans;
        
    }
};