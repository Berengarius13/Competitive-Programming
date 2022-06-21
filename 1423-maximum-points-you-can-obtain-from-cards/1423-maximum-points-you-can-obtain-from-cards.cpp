class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int total_sum = 0;
        int sub_sum = 0; 
        int min_sum = INT_MAX;
        int a = 0; 
        int t = cardPoints.size()-k;
        while(a < cardPoints.size()){
            total_sum += cardPoints[a];
            sub_sum += cardPoints[a];
            
            if(a == t-1)
              min_sum = min(min_sum, sub_sum);  
            
            if(a >= t){
                sub_sum -= cardPoints[a-t];
                min_sum = min(min_sum, sub_sum);
            }
            a++;
        }
        
        return total_sum - min_sum;
    }
};
































/*
class Solution {
public:
    int knapsack(vector<int> &card, int k, int i, int j, vector<vector<int>> &memo){
        if(j < 0 || i >= card.size() || k == 0 || i > j) return 0;
        if(memo[i][j] != -1) return memo[i][j];
    
        
        int start = card[i] + knapsack(card, k-1, i+1, j, memo);
        
        
        int end = card[j] + knapsack(card, k-1, i, j-1, memo);
        
        memo[i][j] = max(start, end);
        return max(start, end);
    }
    int maxScore(vector<int>& cardPoints, int k) {
        vector<vector<int>> memo(cardPoints.size()+1, vector<int> (cardPoints.size()+1, -1));
        return knapsack(cardPoints, k, 0, cardPoints.size()-1, memo);
    }
};
*/