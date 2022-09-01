/*
* O(N^2 long (n)) approach
* Use of unordered map
* see a + b + c = 0;
* So what you can do is pick a value of a and find 
  all the pairs of b and c which satisfies the condition
* So pick a, reduce it's count, so it can't be used again
* Next iterate through unordered map and which you pick as b
  mark it used and find value of c in map
* Store it in set as there will be cases where duplicates might
  occur
*/
/*
There exist a 2 pointer approach
*/
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(auto &num : nums){
            mp[num]++;
        }
        set<vector<int>> unique;
        for(auto [a, a_count]: mp){
            mp[a]--;
            for(auto [b, b_count]: mp){
                if(mp[b] == 0) continue;
                mp[b]--;
                if(mp.find(-b-a) != mp.end() && mp[-b-a] > 0){
                    int c = -b-a;
                    vector<int> temp = {a, b, c};
                    sort(temp.begin(), temp.end());
                    unique.insert(temp);
                }
                mp[b]++;
            }
            mp[a]++;
        }
        vector<vector<int>> ans;
        for(auto &vec : unique){
            ans.push_back(vec);
        }
        return ans;
    }
};