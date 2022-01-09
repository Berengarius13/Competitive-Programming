class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        if(m == 0){
            nums1 = nums2;
            nums2.clear(); 
        }

        int i =m-1; 
        int j = m+n-1;
        while(i>=0){
            swap(nums1[i], nums1[j]);
            i--;
            j--;
        }
        int k =0;
        j =0;
        i = n;
        while(j <n && i < m+n){
            if(nums1[i]>nums2[j]){
                nums1[k] = nums2[j];
                k++;
                j++;
            }
            else{
                nums1[k] = nums1[i];
                k++;
                i++;
            }            
        }
        while(j < n){
                nums1[k] =nums2[j];
                k++;
                j++;
            }
        while(i<m+n){
                nums1[k],nums1[i];
                i++;
                k++;
            }
    }
};