class Solution {
public:
    // Recurrance relation
    // int fn (int a, int b){
    //     if (a == b) 
    //         return 1;
    //     if (b == 0)
    //         return 1;
    //     return fn(a-1,b) + fn(a-1, b-1);
    // }
    
    // signed integer overflow: 1383372541 + 1383339776 cannot be represented in type 'int' (solution.cpp) always this error
    int uniquePaths(int m, int n) {
        int a = m+n-2;
        int ans{0};
        int b = min(m-1,n-1);
        
        if (a == 0 || b==0 || a == 1)
            return 1;
        
        
        unsigned long long int arr[a+1][a+1];
            
        for(int i = 1; i < a; i++){
            
            for(int j = 0; j < i; j++){
                if(i == j || j == 0)
                    arr[i][j] = 1;
                
                if(i == j+1)
                    arr[i][j+1] = 1;
                
                arr[i+1][j+1] = arr[i][j+1]+ arr[i][j];
                if(i == a-1 && j == b-1)
                    break;
            }
        }
        return arr[a][b];
            
    }
};