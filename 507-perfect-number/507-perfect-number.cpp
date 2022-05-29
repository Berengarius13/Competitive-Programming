class Solution {
public:
    bool checkPerfectNumber(int num) {
        int sum = 0;   //maintain sum of the divisors
        //loop through half the num value because we have to exclude the number itself
        for(int i = 1; i <= num / 2; i++)
        {
            //if its a divisor then it gets added to sum
            if(num % i == 0)
            {
                sum = sum + i;
            }
        }
        //self explanatory
        if(sum == num)
            return true;
        return false;
    }
};