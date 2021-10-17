/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* ans;
        ans = NULL;
        int a =0; 
        int b =0;
        ListNode* tA = headA;
        ListNode* tB = headB;
//         ListNode* s;
        
//         s = headB;
//         while (headA !=NULL && headB !=NULL){
//             if(headA != headB)
//             {
//                 headB= headB->next;
//                 if(headB == NULL ){
//                     headA = headA->next;
//                     headB=s;
//                 }
//             }
//             else 
//             {
//                 ans =headA;
//                 break;
//             }
            
//         }
//         while (tA !=NULL || tB !=NULL){
//             if(tA!=NULL){
//                 a++;
//                 tA= tA->next;
//             }
//             if(tB!=NULL){
//                 b++;
//                 tB= tB->next;
                
//             }
//             if(tA==NULL && tB == NULL)
//                 break;
//         }
        while(tA!=NULL){
            a++;
            tA=tA->next;
        }
        while(tB!=NULL){
            b++;
            tB=tB->next;
        }
        if(a>b)
        {
            for(int i=0; i<a-b;i++){
                headA=headA->next;
            }
        }
        else if (b>a) {
            for(int i=0; i<b-a;i++)
                {headB=headB->next;}
        }
        // while (true){
        //     tA = tA->next;
        //     tB = tB->next;
        //     if(tA==NULL)
        //     {
        //         while(true){
        //             tB = tB->next;
        //             headA = headA->next;
        //             if(tB==NULL)
        //                 break;
        //         }
        //     }
        //     else if(tB==NULL)
        //     {
        //         while(true){
        //             tA = tA->next;
        //             headB = headB->next;
        //             if(tA==NULL)
        //                 break;
        //         }
        //     }
        //     if(tA == NULL && tB == NULL)
        //         break;
        // }
        
        while (headA !=NULL && headB !=NULL){
            if(headA!=headB){
                headA=headA->next;
                headB=headB->next;
            }
            else 
            {
                ans = headA;
                break;
            }
        }
        
        return ans;
        
    }
};