// Time : O(N)
// Space : O(1)

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) return head;
        
        Node* traversal = head;
        while (traversal != nullptr) {
            Node* temp = traversal->next;
            traversal->next = new Node(traversal->val);
            traversal->next->next = temp;
            traversal = temp;
        }
        
        traversal = head;
        while (traversal != nullptr) {
            traversal->next->random = traversal->random == nullptr ? nullptr : traversal->random->next;
            traversal = traversal->next->next;
        }
        

        Node* ret = head->next;
        traversal = head;
        while (traversal != nullptr) {
            Node* temp = traversal->next;
            traversal->next = traversal->next->next;
            temp->next = temp->next == nullptr ? nullptr : temp->next->next;
            traversal = traversal->next;
        }
        
        return ret;
    }
};