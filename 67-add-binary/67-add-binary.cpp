class Solution {
public:
    string addBinary(string A, string B) 
{
	int na = A.size();
	int nb = B.size();
	int carry = 0, sum = 0;
	string ans = "";

	if(na > nb)     // append na-nb '0's in front of B
	{
		string temp(na-nb, '0');
		B = temp + B;
	}
	if(nb > na)     // append nb-na '0's in front of A
	{
		string temp(nb-na, '0');
		A = temp + A;
	}

	na = A.size();
	nb = B.size();

	for(int i=na-1;i>=0;--i)
	{
		int a = A[i] - '0';
		int b = B[i] - '0';

		sum = carry ^ a ^ b;
		carry = (a&b) | (b&carry) | (carry&a);

		ans = to_string(sum) + ans;
	}

	if(carry) ans = '1' + ans;

	return ans;
}
};