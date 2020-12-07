// https://leetcode.com/problems/lru-cache/submissions/
// O(1)

struct Node {
    Node *next, *prev;
    int key, value;
    
    Node(int _key, int _value) : key(_key), value(_value) {
        next = nullptr;
        prev = nullptr;
    }
};

class LRUCache {
public:
    int capacity;
    Node *head, *tail;
    unordered_map<int, Node*> umap;
    
    void omit(Node* node) {
        if (node == tail) return ;
        else if (node == head) { 
            head = head->next;
            head->prev = nullptr;
        }
        else {
            node->prev->next = node->next;
            node->next->prev = node->prev;
        }
    }
    
    void push(Node* node) {
        if (tail == node) return;
        else if (head == nullptr) 
            head = tail = node;
        else { 
            node->next = nullptr;
            node->prev = tail;
            tail->next = node;
            tail = node;
        }
    }
    
    void LRUremove() {
        umap.erase(umap.find(head->key));
        head = move(head->next);
        head->prev = nullptr;
    }
    
    void update(Node* node, int value) {
        node->value = value;
        omit(node);
        push(node);
    }
    
    LRUCache(int capacity) {
        this->capacity = capacity;
        head = nullptr, tail = nullptr;
    }
    
    int get(int key) {
        if (umap.find(key) == umap.end()) return -1;
        else {
            Node* node = umap[key];
            omit(node);
            push(node);
            return umap[key]->value;
        }
    }
    
    void put(int key, int value) {
        Node* node;
        if (umap.find(key) != umap.end()) {
            node = umap[key];
            update(node, value);
        } else if (capacity == umap.size()) {
            node = new Node(key, value);
            push(node);
            LRUremove();
        } else {
            node = new Node(key, value);
            push(node);
        }
        umap[key] = tail;
    }
};
