class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int, char>> pq;
        pair<int, char> last = {0, 'a'};
        if(a != 0) pq.push({a, 'a'});
        if(b != 0) pq.push({b, 'b'});
        if(c != 0) pq.push({c, 'c'});
        string ans;
        while(!pq.empty()){
            auto top = pq.top();
            pq.pop();
            if(top.first >= 2 && last.first <= top.first){
                ans += top.second;
                ans += top.second;
                top.first -= 2;
            }
            else if(top.first >= 1){
                ans += top.second;
                top.first--;
            }
            if(last.first != 0) pq.push(last);
            last = top;
        }
        return ans;
    }
};