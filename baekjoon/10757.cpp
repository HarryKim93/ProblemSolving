<<<<<<< HEAD
#include <stack>
#include <iostream>

using namespace std;

void swap(string& a, string& b){
    string temp;
    temp = move(a);
    a = move(b);
    b = move(temp);
}

int main() {
    string a, b;
    stack<int> stk;

    cin >> a >> b;
    if (a.length() < b.length()) swap(a, b);
    
    int aIdx = a.length() - 1;
    int bIdx = b.length() - 1;
    int val = 0;

    bool check = false;
    for (; aIdx >= 0; aIdx--) {
        val = a[aIdx] - '0' + (bIdx < 0 ? 0 : b[bIdx] - '0');
        if (check) {
            val++;
            check = false;
        }
        if (val >= 10) {
            check = true;
            val -= 10;
        }
        stk.push(val);
        bIdx--;
    }
    if (check) stk.push(1);

    while (!stk.empty()) {
        cout << stk.top();
        stk.pop();
    }

    return 0;
=======
#include <stack>
#include <iostream>

using namespace std;

void swap(string& a, string& b){
    string temp;
    temp = move(a);
    a = move(b);
    b = move(temp);
}

int main() {
    string a, b;
    stack<int> stk;

    cin >> a >> b;
    if (a.length() < b.length()) swap(a, b);
    
    int aIdx = a.length() - 1;
    int bIdx = b.length() - 1;
    int val = 0;

    bool check = false;
    for (; aIdx >= 0; aIdx--) {
        val = a[aIdx] - '0' + (bIdx < 0 ? 0 : b[bIdx] - '0');
        if (check) {
            val++;
            check = false;
        }
        if (val >= 10) {
            check = true;
            val -= 10;
        }
        stk.push(val);
        bIdx--;
    }
    if (check) stk.push(1);

    while (!stk.empty()) {
        cout << stk.top();
        stk.pop();
    }

    return 0;
>>>>>>> origin/master
}