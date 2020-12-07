/**
 * https://leetcode.com/problems/merge-k-sorted-lists/
 * 
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
        function<ListNode*&&(ListNode*, ListNode*)> func = [=](ListNode* a, ListNode* b) -> ListNode*{
            ListNode *head = nullptr, *tail = nullptr;
            ListNode* node;
            
            while (a != nullptr || b != nullptr) {
                if (a == nullptr) node = b;
                else if (b == nullptr) node = a;
                else node = a->val < b->val ? a : b;
                
                if (tail == nullptr) {
                    head = tail = move(node);
                } else {
                    tail->next = move(node);
                    tail = node;
                }
                
                if (node == a) a = move(a->next);
                else b = move(b->next);
            }
            
            return move(head);
        };
        
        function<ListNode*&&(int, int)> divideConquer = [&](int start, int end) {        
            if (start == end) return move(lists[start]);
            
            int mid = (start + end) / 2;
            return func(divideConquer(start, mid), divideConquer(mid + 1, end));
        };
        
        if (lists.empty()) return nullptr;
        return divideConquer(0, lists.size() - 1);
    }
};