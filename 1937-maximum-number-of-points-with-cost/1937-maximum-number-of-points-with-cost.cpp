// Debug Template, copied from Mikel_Arteta_8 (https://codeforces.com/blog/entry/68809)
void __print(int x) {cout << x;}
void __print(long x) {cout << x;}
void __print(long long x) {cout << x;}
void __print(unsigned x) {cout << x;}
void __print(unsigned long x) {cout << x;}
void __print(unsigned long long x) {cout << x;}
void __print(float x) {cout << x;}
void __print(double x) {cout << x;}
void __print(char x) {cout << '\'' << x << '\'';}
void __print(const char *x) {cout << '\"' << x << '\"';}
void __print(const string &x) {cout << '\"' << x << '\"';}
void __print(bool x) {cout << (x ? "true" : "false");}
template<typename T, typename V>
void __print(const pair<T, V> &x) {cout << '{'; __print(x.first); cout << ','; __print(x.second); cout << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cout << '{'; for (auto &i: x) cout << (f++ ? "," : ""), __print(i); cout << "}";}
void _print() {cout << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cout << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cout << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

#define ll long long
class Solution {
public:
    
    long long maxPoints(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<ll>> dp(n, vector<ll> (m, 0));
        vector<vector<ll>> ans(n, vector<ll> (m, 0));
        multiset<ll, greater<ll>> st;
        for(int i = n-1; i >= 0; i--){
            
            for(int j = 0; j < m; j++){
                ll a = (j == 0)? 0 : dp[i][j-1]-1; // j == 0 case
                ll b = 0;
                if(i != n-1){
                    auto mxIt = st.begin();
                    b = *mxIt;
                    // debug(b);
                    auto it = st.find(ans[i+1][j]-j);
                    st.erase(it);
                    dp[i][j] =  max(a, b+j);
                    // debug(st);
                }
                else{
                    dp[i][j] = 0;
                }
                ans[i][j] = grid[i][j] + dp[i][j];
                
            }
            st.clear();
            for(int j = 0; j < m; j++) st.insert(ans[i][j]-j); // -j 
        }
        ll v = -1;
        for(int j = 0; j < m; j++){
            v = max(v, ans[0][j]);
        }
        // debug(dp);
        // debug(ans);
        return v;
    }
};

































// class SegmentTree{
//   private : 
//         vector<ll> st,A;
//         vector<ll> lazy;
//         int n;
//   public: 
//         SegmentTree(vector<int>& a)
//         {
//           A = a;
//           n = a.size();
//           st.assign(4*n + 1, 0);     // Max 4n nodes required
//           lazy.assign(4*n+1, 0);     // Max 4n nodes required
//           build(1,0,n-1);            // build segment tree 
//         }
        
//         void print()                // Print the st and lazy to debug
//         {
//             cout << "SegmentTree is as follows "<< endl;
//             for(int c: st)
//             {
//                 cout << c << " ";
//             }
//             cout << "\nLazy is as follows \n";
//             for(int c: lazy)
//             {
//                 cout << c<< " ";
//             }
//             cout << endl;
            
//         }
      
//           void build(int i, int l, int r)    // Method to build the segTree 
//           {
//               if(l>r)
//               return;
//               if(l == r)
//               {
//                   st[i] = A[l];
//               }
//               else
//               {
//                   build(2*i, l,(l+r)/2);
//                   build(2*i + 1, (l+r)/2 + 1, r);
//                   st[i] = max(st[2*i], st[2*i + 1]);    // Modify this as needed 
//               }
//           }
      
//       int rmq(int l, int r)                     // Range Sum query.Modify this // as needed for different problems.
//       {
//           l--;
//           r--;
//           return query(1,0,n-1,l,r);
//       }
      
//       void update_range(int l, int r, int diff)
//       {
//           l--,r--;
//           update_lazy(1,0,n-1,l,r ,diff);
//       }
//       void update_lazy(int i, int a, int b, int l, int r, int diff)
//       {
//           if(lazy[i]!=0)
//           {
//               st[i] += (b-a+1)*diff;        // Modify as needed 
//               if(a!=b)                      // propagate if not leaf 
//               {
//                   lazy[2*i] = lazy[i];      
//                   lazy[2*i+1] = lazy[i];
//               }
//               lazy[i] = 0;
//           }
          
//           if(l>r || l>b || r<a)             // Out of range
//           return;
//           if(a>=l && r<=b)                  // Completely in range 
//           {
//               st[i] = (b-a+1)*diff;
//               if(a!=b)                  // If not leaf then propagate
//               {
//                   lazy[2*i] += diff;
//                   lazy[2*i+1] += diff;
//               }
//               return;
//           }
          
//           update_lazy(2*i, a, (a+b)/2, l, r, diff);
//           update_lazy(2*i+1, (a+b)/2+1, b, l, r, diff);
          
//           st[i] = max(st[2*i], st[2*i+1]);      // Modify as needed 
//       }

//     int query(int i, int a,int b, int l, int r)
//     {
//         if(lazy[i]!=0)
//         {
//             st[i] += (b-a+1)*lazy[i];
//             if(a!=b)
//             {
//                 lazy[2*i] = lazy[i];
//                 lazy[2*i+1] = lazy[i];
//             }
//             lazy[i] = 0;
//         }
//         if(r<a || b<l || a > b)
//         return 0;
        
//         if(l<=a && r>=b)
//         return st[i];
        
//         return max(query(2*i, a,(a+b)/2, l,r), query(2*i+1,(a+b)/2 + 1, b,l,r)); // MOdify 
        
//     }
// };























