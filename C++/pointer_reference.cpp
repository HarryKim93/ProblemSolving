#include <iostream>

using namespace std;

// void test(int*& a, int*& b) {
//     a = b;
// }

void test(int* a, int* b) {
    a = b;
}

int main() {
    int a = 1;
    int b =9;
    int *pa = &a;
    int *pb = &b;

    test(pa, pb);

    cout << *pa << "\n";
    cout << *pb << "\n";
}