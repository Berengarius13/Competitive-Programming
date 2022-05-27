class Solution {
public:
    int numberOfSteps(int num) {
        int i = 0;
        while(num>0){
            if((num&1) == 1){
                num--;
            }
            else{
                num = (num >> 1);
            }
            i++;
        }
        return i;
    }
};