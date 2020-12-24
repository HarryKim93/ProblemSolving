// https://leetcode.com/problems/print-immutable-linked-list-in-reverse/submissions/
// O(N)

class Solution {
public:
    void printLinkedListInReverse(ImmutableListNode* head) {
        head ? printLinkedListInReverse(head->getNext()), head->printValue() : void();
    }
};