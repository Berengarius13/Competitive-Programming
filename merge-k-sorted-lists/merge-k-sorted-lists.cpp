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
    /*We have used multi map to store keys and values in oredered pairs to store values in order with
     * their corrospending node
     */
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k = 0;
        ListNode* neu = new ListNode(0);
        ListNode* ans = neu;
        // 
        if (lists.size() == 0) return NULL;
        if(lists.size() == 1) {
            return lists[0];
        }
        //
        for(auto it = lists.begin(); it < lists.end(); it++){
            if((*it) == NULL)
            lists.erase(it);
        }
        
        if (lists.size() == 0) return NULL;
        if(lists.size() == 1) {
            return lists[0];
        }
        k = lists.size();
        multimap<int, ListNode*> mm; 
        for(auto &list: lists){
            if(list != NULL)
            mm.insert({list->val, list});
        }
        while(mm.size() >1){
            auto itm = mm.begin();
            neu->next = itm->second;
            if(itm->second->next != NULL){
                mm.insert({itm->second->next->val,itm->second->next});
                mm.erase(itm);
            }
            else{
                // there are only three elements in vector vec[0], vec[1], vec[2]
                // auto itv = find(lists.begin(),lists.end(), itm->second);
                // lists.erase(itv);
                mm.erase(itm);
            }
            neu = neu->next;
            
                
        }
        if(mm.size() == 0)
            return NULL;
        auto itm = mm.begin();
        neu->next = itm->second;
        return ans->next;
        
    }
};