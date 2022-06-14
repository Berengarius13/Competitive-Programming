class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        vector<int> g_c;
        for(int i = 0; i < gas.size(); i++)
            g_c.push_back(gas[i]-cost[i]);
        int a = 0; int b = 0; int sum = 0;
        int val = 0;
        for(auto &it : g_c)
            val+=it;
        if(val<0) return -1;
        while(b< gas.size()){
            if(sum+g_c[b] >= 0){
                sum+=g_c[b];
                b++;
            }
            else{
                sum = 0;
                b++; a = b;
            }
        }
        if(a == gas.size()) return -1;
        else return a;
    }
};