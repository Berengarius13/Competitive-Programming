class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        vector<int> gc;
        int n = gas.size();
        for(int i = 0; i < n; i++) gc.push_back(gas[i] - cost[i]);
        int sum = 0;
        int a = n-1;
        for(int i = 0; i <= a; i++){
            sum += gc[i];
            
            if(sum < 0){
                while(a > i && sum  < 0){
                    sum += gc[a];
                    a--;
                }
            }
        }
        if(sum < 0) return -1;
        a++;
        if(a == n) a = 0;
        return a;
    }
};