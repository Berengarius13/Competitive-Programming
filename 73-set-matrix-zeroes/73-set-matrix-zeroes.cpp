class Solution {
public:
    void setZeroes(vector<vector<int>>& a){
        /* 
        * We are storing information regarding where to put zeros in first rows and column
        * For the case that all items in first row and column are zero we store that                     information.
        * In last case we use  that information to set the answer
        */
        int n = a.size();
        int m = a[0].size();
        bool firstRow = false;  // do we need to set first row zero
        bool firstCol = false;  // do we need to ser first col zero
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
					if(a[i][j] == 0){   // store rows and cols state in first row and col
                    if(i==0) firstRow = true;
                    if(j==0) firstCol = true;
                    a[i][0] = 0;
                    a[0][j] = 0;
                }
            }
        }
        // cout<<firstRow<<" "<<firstCol<<endl;
        for(int i=1; i<n; i++){
            for(int j=1; j<m; j++){
                if(a[i][0] == 0 || a[0][j] == 0){
                    a[i][j] = 0;
                }
            }
        }
        
        if(firstRow){
            for(int i=0;i<m;i++) a[0][i] = 0;
        }
        
        if(firstCol){
            for(int i=0;i<n;i++) a[i][0] = 0;
        }
    }
};
/*
* O(m+n) memory solution
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> arrm (m,0);
        vector<int> arrn (n,0);
        
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(matrix[i][j] ==0){
                    arrm[i] = 1;
                    arrn[j] = 1;
                }
            }
        }
        for(int i = 0; i < m ; i++){
            for(int j = 0 ; j < n; j++){
                if(arrm[i] == 1 || arrn[j] ==1)
                    matrix[i][j] = 0;
            }
        }
*/