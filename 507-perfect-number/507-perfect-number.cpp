class Solution {
public:
    bool checkPerfectNumber(int num) {
        if ((num == 1) || (num < 0)) // edge cases - number is negitive or 1
            return false;
        
        int i = 2;
        int res = 1;
        for (; i<sqrt(num); i++)
        {
            if (num % i == 0)
                res += i + num/i;
        }
        
        if ((int(sqrt(num)) >= i ) && (num % i == 0)) // edge case - number has a whole sqrt
            res += i;
        
        return res == num;
    }
};