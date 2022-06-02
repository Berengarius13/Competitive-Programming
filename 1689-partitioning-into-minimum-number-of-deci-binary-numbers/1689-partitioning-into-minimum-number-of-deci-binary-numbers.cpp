class Solution {
public:
    int minPartitions(string n) {
        int maxi = 0;
        for(auto &c : n){
            int i = c - '0';
            maxi = max(i, maxi);
        }
        return maxi;
    }
};