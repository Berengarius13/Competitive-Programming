class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
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