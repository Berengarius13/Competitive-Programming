class Solution {
public:
    int kthFactor(int n, int k) {
        int res = 0;
		
		 // A TreeSet to store the factors in ascending order
        set<int> s;     
		
		// Find all the factors and store it in the set
        for(int i = 1; i <= sqrt(n); ++i)
        {
            if (n % i == 0) 
            { 
                s.insert(i); 
                if (i != sqrt(n)) 
                    s.insert(n / i); 
            }
        }
		
		// If the size of set is smaller than given k, return -1
        if(s.size() < k)
            return -1;
			
		// Else we return the kth element by iterating till the kth element in the set.
        auto it = s.begin();
        while(--k > 0)
            it++;
        return *it;
    }
};