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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size(),i;
        vector<int> v;
        for(i=0;i<n;i++)
        {
            while(lists[i]!=NULL)
            {
                v.push_back(lists[i]->val);
                lists[i] = lists[i]->next;
            }
        }
        sort(v.begin(),v.end());
        
        ListNode* temp = NULL;
        for(i=0;i<v.size();i++)
        {
            temp->val = v[i];
            temp = temp->next;
        }
        return temp;
    }
};
