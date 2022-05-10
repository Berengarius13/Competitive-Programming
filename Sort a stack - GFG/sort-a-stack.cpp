// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

class SortedStack{
public:
	stack<int> s;
	void sort();
};

void printStack(stack<int> s)
{
    while (!s.empty())
    {
        printf("%d ", s.top());
       	s.pop();
    }
    printf("\n");
}

int main()
{
int t;
cin>>t;
while(t--)
{
	SortedStack *ss = new SortedStack();
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
	int k;
	cin>>k;
	ss->s.push(k);
	}
	ss->sort();
	printStack(ss->s);
}
}// } Driver Code Ends


/*The structure of the class is
class SortedStack{
public:
	stack<int> s;
	void sort();
};
*/

/* The below method sorts the stack s 
you are required to complete the below method */
void SortedStack :: sort()
{
   int size = s.size();
   stack<int> temp;
   for(int i = 0; i < size; i++){
       int maxi = INT_MIN;
       bool flag = true;
       while(!s.empty()){
           maxi = max(s.top(), maxi);
           temp.push(s.top());
           s.pop();
       }
       for(int j = 0; j < size-i; j++){
           if(maxi == temp.top() && flag == true){
               temp.pop();
               flag = false;
               continue;
           }
           s.push(temp.top());
           temp.pop();
       }
       temp.push(maxi);
   }
  while(!temp.empty()){
      s.push(temp.top());
      temp.pop();
  }
}