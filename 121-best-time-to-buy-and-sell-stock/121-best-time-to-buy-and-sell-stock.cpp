class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int i = 0; 
        int ans = INT_MIN; 
        int maxi = 0;
        while(i+1 < prices.size()){
            
            maxi = maxi + prices[i+1] - prices[i];
            ans = max(maxi, ans);
            if(maxi < 0){
                ans = max(maxi, ans);
                maxi = 0;
            }
            i++;
        }
        if(ans < 0) return 0;
        else return ans;
        
    }
};