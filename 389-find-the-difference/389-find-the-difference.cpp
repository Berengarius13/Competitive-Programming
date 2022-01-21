class Solution {
public:
    char findTheDifference(string s, string t) {
        // Maps method
//         char ans; 
//         unordered_map<char, int> m1; 
//         unordered_map<char, int> m2;
//         /*
//         * Remember this technique to store frequency in maps
//         * Remember map is initialize to zero automatically
//         */
//         for(auto c: s)
//             m1[c] = m1[c]+1;
//         for(auto c: t)
//             m2[c] = m2[c] +1;
//         for(auto pair: m2){
//             if(pair.second != m1[pair.first])
//             {ans = pair.first; break;}
//         }
        
//         return ans;
        // Bitwise method
        int b = 0; 
        for(auto c:s)
            b = b^c;
        for(auto c:t)
            b = b^c;
        return b;
        
    }
};