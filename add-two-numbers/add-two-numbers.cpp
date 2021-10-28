/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // This approach will not work as unsigned long long int has it's range limits. 
//         unsigned long long int	 a = 0;
//         unsigned long long int	 b = 0; 
//         float i = 0;
//         ListNode* head = NULL;
        
        
//         while (l1 !=NULL)
//         { 
            
//             a = a + l1->val * pow(10.0, i);
//             i++;
//             l1= l1->next;
//         }
//         unsigned long long int	 n;
//         i = 0;
//         while (l2 !=NULL)
//         { 
            
//             b = b + l2->val * (pow(10.0, i));
//             i++;
//             l2= l2->next;
//         }
//         a = a + b;
//         b = a;
//         if(b == 0)
//         {
//             head = new ListNode(0);
//             return head;
//         }
//         int k = 0;
//         while (b != 0){
//             k++;
//             b = b/10;
//         }
        
//         k--;
//         while (k>-1){
//             n = a/ pow(10.0, (float)k);
            
//             a = a - (n * pow(10.0, (float)k));
//             k--;
            // if (head == NULL)
            // {
            //     head = new ListNode(n);
            //     continue;
            // }
            // else 
            // {
            //     ListNode* k = new ListNode(n);
            //     k->next = head;
            //     head= k;
            // }
//         }
//         return head;
    ListNode* head = NULL;
    ListNode* ans;
        int n;
        int a=0,b=0;
        
        int ca=0;
    while (1)
    {
        if(l1!=NULL)
        {   a=l1->val;
            l1=l1->next;}
        else 
        {
            a = 0;
        }
        
        if(l2!=NULL)
        {   b=l2->val;
            l2=l2->next;}
        else 
        {
            b = 0;
        }   
        
        n = ca + a + b;
        if(n>=10)
        {
            ca = n/10;
            n = n%10;
        }
        else 
        {
            ca = 0;
        }
        
        
        if (head == NULL)
            {
                head = new ListNode(n);
                ans = head;
                
            }
            else 
            {
                ListNode* k = new ListNode(n);
                head->next = k;
                head= k;
            }
        if(l1 == NULL and l2 == NULL)
            {
            if(ca!=0)
                {
                    ListNode* k = new ListNode(ca);
                    head->next = k;
                    head= k;
                }
                break;
            }
        
    }
        
        return ans; 
    }
};