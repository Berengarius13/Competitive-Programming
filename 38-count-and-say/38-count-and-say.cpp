/* *
 * Initialize first string str
 * Derive temp from str
 * Use 2 pointer to keep track of repeating
   element and their count
 * Append count of last element in temp whenever 
   a != b
 */
class Solution {
public:
    string countAndSay(int n) {
        string str = "1";
        for(int i = 1; i < n; i++){
            int a = 0; int b = 0; int count = 0; string temp;
            while(b < str.size()){
                if(str[a] == str[b]){
                    count++; b++;
                }
                else{
                    temp += to_string(count);
                    temp += str[a];
                    a = b; count = 0;
                }
            }
            temp += to_string(count);
            temp += str[a];
            str = temp;
        }
        return str;
    }
};
