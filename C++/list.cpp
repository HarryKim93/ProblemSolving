#include <list>
#include <iostream>

using namespace std;

int main() {
    list<int> lst;
    lst.push_back(1);
    lst.push_back(2);
    lst.push_back(3);
    lst.push_back(4);

    for (auto it = lst.begin(); it != lst.end(); it++) {
        cout << *it << " ";
    }
    cout << "\n";
    auto iter = lst.begin();


    lst.insert(iter, 5);

    for (auto it = lst.begin(); it != lst.end(); it++) {
        cout << *it << " ";
    }
    cout << "\n";

    return 0;
}