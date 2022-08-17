class Solution {
public:
    void wiggleSort(vector<int>& v) {
        auto t=v;
        int j=0;
        sort(t.begin(),t.end(),[](int &a,int &b){return a>b;});
        for(int i=1;i<v.size();i+=2){
            v[i]=t[j++];
        }
        for(int i=0;i<v.size();i+=2){
            v[i]=t[j++];
         }
    }
};