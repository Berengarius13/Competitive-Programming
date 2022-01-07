class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        vector<int> ans;
        int m = mat.size();
        int n = mat[0].size();
        if(m==1&& n==1)
            return mat[0];
        // // if(n==1){
        // //     for(auto &num:mat)
        // //         ans.push_back(num[0]);
        // //     return ans;
        // // }
            
        m--;
        n--;
        int a = 0; 
        int b = 0;

        // int k =0;
        ans.push_back(mat[a][b]);
        for(int i =0 ; i < m+n ; i++){
            if(i%2 == 0){
                if(b+1<=n)
                    b++;
                else
                    a++;
            }
            else{
                if(a+1<=m)
                    a++;
                else
                    b++;
            }
            
            ans.push_back(mat[a][b]);
            while(true){
                
                // c=a;
                // d=b;
                if((i+1)%2 ==0){
                    if((a-1)<0  ||( b+1) >n)
                        break;
                    a--;
                    b++;
                }
                else{
                    if((b-1)<0  || (a+1) >m)
                        break;
                    a++;
                    b--;
                }
                ans.push_back(mat[a][b]);
                // k--;
            }
            // a = c;
            // b = d;
        }
        return ans;
    }
};