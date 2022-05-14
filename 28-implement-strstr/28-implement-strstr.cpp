class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.size() == 0) return 0;
        int sa = haystack.size();
        int sb = needle.size();
        int a = 0; 
        int b = 0;
        while(a < sa && b < sb){
            if(haystack[a] != needle[b])
                a++;
            if(a == sa) return -1;
            int temp = a;
            while(haystack[a] == needle[b] && a < sa && b < sb){
                a++; b++;
            }
            if(b == sb) return temp;
            a = temp;
            b = 0;
            a++;
        }
        return -1;
    }
};