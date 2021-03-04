// time : O(N)
// space : O(1)

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
    ListNode* removeNthFromEnd(ListNode* head, int& cnt, const int& n) {
        if (head == nullptr) return head;
        else {
            ListNode* val = removeNthFromEnd(head->next, cnt, n);
            if (cnt == n) head->next = val;
            cnt++;
            
            return head->next;
        }
    }
    
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int idx = 0;
        ListNode* ret = removeNthFromEnd(head, idx, n);
        if (idx == n) return ret;    
        return head;
    }
};