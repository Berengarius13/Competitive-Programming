class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        stack<pair<int, int>> s;
        vector<int> vec(t.size(), 0);
        for(int i = 0; i < t.size()-1; i++){
            if(t[i] < t[i+1]){
                vec[i] = 1;
                if(!s.empty()){
                    int tem = s.top().first;
                    int ite = s.top().second;
                    while(tem < t[i+1]){
                        vec[ite] = i + 1 - ite;
                        s.pop();
                        if(s.empty()) break; 
                        tem = s.top().first;
                        ite = s.top().second;
                    }
                }
            }
            else if (t[i] >= t[i+1]){
                s.push({t[i], i});
            }  
        }
        return vec;
    }
};