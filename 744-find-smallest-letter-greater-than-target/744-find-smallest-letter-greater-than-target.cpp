class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int s = 0;
        int e = letters.size()-1;
        while(s <= e){
            int m = (s+e)>>1;
            if(letters[m] > target)
                e = m-1;
            else if(letters[m] < target)
                s = m+1;
            else{
                s = m+1;
            }
        }
        if(e+1 == letters.size())
            return letters[0];
        else
            return letters[e+1];
    }
};