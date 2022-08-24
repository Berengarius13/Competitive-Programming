/*
Lets say we are given [1,10000] and [2,10000] intervals and we are supposed to increase the count of values between 1 to 10000 and 2 to 10000 by 1.
So how you will do?
Brute force is to iterate over each interval and increase each position count that is appearing in intervals.
Can we do better?
Lets create a array from index 0 to 1e5.
Now iterate over each interval.Eg.:-
[1,10000]:- increase the counter at pos 1 and decrease at 10001.Same for other intervals.
Now do prefix sum.
This will incerase each position value in linear time.
In question when we do forward shift then we have to increase the count from position left to right.
11.So i will do line[left]++ and line[right+1]--.
For backward shift we want to decrease the value so
So i will do line[left]-- and line[right+1]++.
*/
class Solution {
public:
    // void shift_letter(string &s, vector<int> &change){
    //     for(int i = 0; i < s.size(); i++){
    //         int asci = (int)s[i] - 'a';
    //         int num = change[i];
    //         if(num < 0){
    //             num = abs(num);
    //             num = num % 26;
    //             num = -num + 26;
    //         }
    //         else
    //             num = num % 26;
    //         num = num + asci;
    //         num = num % 26;
    //         cout<<num<<" ";
    //         s[i] = (char) num + 'a';
    //     }
    // }
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        vector<int>  prePrefix (s.size()+1, 0);
        for(auto &shift : shifts){
            int left = shift[0];
            int right = shift[1];
            int dir = shift[2];
            if(dir == 1){
                prePrefix[left]++;
                prePrefix[right+1]--;
            }
            else{
                prePrefix[left]--;
                prePrefix[right+1]++;
            }
        }
        // We will do prefix sum, which do our job for ranged query
        for(int i = 1; i < prePrefix.size(); i++){
            prePrefix[i] += prePrefix[i-1];
        }
        for(int i = 0; i < s.size(); i++){
            int asci = (int)s[i] - 'a';
            int num = prePrefix[i];
            if(num < 0){
                num = abs(num);
                num = num % 26;
                num = -num + 26;
            }
            else
                num = num % 26;
            num = num + asci;
            num = num % 26;
            cout<<num<<" ";
            s[i] = (char) num + 'a';
            
        }
        return s;
    }
};