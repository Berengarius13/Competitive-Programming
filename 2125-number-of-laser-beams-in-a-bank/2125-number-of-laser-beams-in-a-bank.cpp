class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int r1 = 0;
        int ans = 0;
        for(auto &str : bank){
            int count = 0;
            for(int i = 0; i < str.size(); i++){
                if(str[i] == '1')
                    count++;
            }
            if(count != 0 && r1 == 0)
                r1 = count;
            else if(count != 0 && r1 != 0){
                ans += count * r1;
                r1 = count;
            }
        }
        return ans;
    }
};