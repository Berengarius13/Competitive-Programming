class Solution {
public:
    string ret(vector<char> &mas, int n){
        string temp;
        switch(n){
            case 1:
                temp = {mas[0]}; break;
            case 2:
                temp = {mas[0], mas[0]}; break;
            case 3:
                temp = {mas[0], mas[0], mas[0]}; break;
            case 4:
                temp = {mas[0], mas[1]}; break;
            case 5:
                temp = {mas[1]}; break;
            case 6:
                temp = {mas[1], mas[0]}; break;
            case 7:
                temp = {mas[1], mas[0], mas[0]}; break;
            case 8: 
                temp = {mas[1], mas[0], mas[0], mas[0]}; break;
            case 9:
                temp = {mas[0], mas[2]}; break;
        }
        return temp;
    }
    string intToRoman(int num) {
        vector<string> ans;
        vector<char> a0 = {'I', 'V', 'X'};
        vector<char> a1 = {'X' , 'L', 'C'};
        vector<char> a2 = {'C', 'D', 'M'};
        vector<char> a3 = {'M'};
        vector<vector<char>> master= {a0, a1, a2, a3};
    
        int i = 0; 
        while(num > 0){
            int a = num % 10;
            ans.push_back(ret(master[i], a));
            num /= 10;
            i++;
        }
        string fin;
        for(int i = ans.size()-1; i >=0; i--){
            fin.append(ans[i]);
        }
        return fin;
    }
};