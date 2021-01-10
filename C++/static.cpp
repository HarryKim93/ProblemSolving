#include <string>
#include <iostream>
#include <functional>
#include <vector>

using namespace std;

int main() {
    string a = "acd";
    cout << a.substr(-1) << "\n";

    using func = function<int(int, int)>;
    unordered_map<string, func> umap;

    return 0;
}