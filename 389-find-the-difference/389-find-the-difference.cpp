class Solution {
public:
    char findTheDifference(string s, string t) {
        char ans; 
        map<char, int> m1; 
        map<char, int> m2;
        /*
        * Remember this technique to store frequency in maps
        * Remember map is initialize to zero automatically
        */
        for(auto c: s)
            m1[c] = m1[c]+1;
        for(auto c: t)
            m2[c] = m2[c] +1;
        for(auto pair: m2){
            if(pair.second != m1[pair.first])
            {ans = pair.first; break;}
        }
        
        return ans;
        
    }
};