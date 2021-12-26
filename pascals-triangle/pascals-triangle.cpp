class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> vec;
        vector<int> v;
        v.push_back(1);
        vec.push_back(v);
        if(numRows == 1)
            return vec; 
        v.push_back(1);
        vec.push_back(v);
        if(numRows == 2)
            return vec; 
        vector<int> rem;
        for (int i = 0; i< numRows-2; i++){
            
            rem = v;
            v.clear();
            v.push_back(1);
            for(int j =0 ;j <rem.size()-1; j++){
                
                
                v.push_back(rem[j+1]+rem[j]);
                
            }
            v.push_back(1);
            
            vec.push_back(v);
        }
        return vec; 
    }
};