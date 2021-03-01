#include <iostream>
#include <vector>

using namespace std;

int main() {
    alignas(64) vector<int> num(4);
    return 0;
}