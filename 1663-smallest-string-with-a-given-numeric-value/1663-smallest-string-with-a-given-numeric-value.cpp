class Solution {
public:
    char int_to_asci(int a){
        int ascii = a+96;
        return (char)ascii;
    }
    string getSmallestString(int n, int k) {
        int val_n = n;
        string s;
        vector<int> vec;
        for(int i = 0; i < val_n; i++){
            n = n -1; 
            if ( n * 26 >= k){
                k = k - 1; 
                s.push_back('a');
            }
            else{
                int temp = k - (n*26);
                k = k - (temp);
                s.push_back(int_to_asci(temp));
            }
        }
        return s;
        
    }
};