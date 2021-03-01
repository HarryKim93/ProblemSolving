#include <iostream>

using namespace std;

#define HASH_TABLE 1000

struct node {
    int value;
    node* next;
    node() : value(0), next(nullptr) {}
    node(int _value) : value(_value), next(nullptr) {}
};

int hash_function(const char* str) {
    unsigned int hash = 401;

    while (*str != '\0') {
        hash = ((hash << 11) + (unsigned int)(*str) * 3) % HASH_TABLE;
        str++;
    }

    return hash % HASH_TABLE;
}

node hash_table[HASH_TABLE];

void insert (const char* key, int value) {
    int idx = hash_function(key);

    if (hash_table[idx].value == value) {
        cout << "chaining\n";
        node* temp = new node(value);
        temp->next = &hash_table[idx];
        hash_table[idx] = *temp;
    } else {
        hash_table[idx].value = value;
    }
}

bool check (const char* key, int value) {
    int idx = hash_function(key);

    node* temp = &hash_table[idx];
    while (temp != nullptr) {
        if (temp->value == value) return true;
        temp = temp->next;
    }

    return false;
}

int main() {    
    insert("abcde", 1);
    insert("abcde", 2);
    cout  << check("abcde", 1);
    cout << check("abcde", 2);
    
    return 0;
}