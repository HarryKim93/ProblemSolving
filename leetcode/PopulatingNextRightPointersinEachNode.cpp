// https://leetcode.com/problems/populating-next-right-pointers-in-each-node/
// O(N)

class Solution {
public:
    Node* connect(Node* root) {
        if (root == NULL) return root;
        
        Node* ptr = root;
        Node* startPtr = ptr->left;
        
        while (startPtr != NULL) {
            while (ptr) {
                ptr->left->next = ptr->right;
                ptr->right->next = ptr->next != NULL ? ptr->next->left : NULL;
                ptr = ptr->next;
            }
            
            ptr = startPtr;
            startPtr = startPtr->left;
        }
        
        return root;
    }
};