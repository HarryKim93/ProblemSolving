#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

int upperBound(vector<int>& nums, int threshold) {
    int left = 0, right = nums.size();
    int mid = (left + right) / 2;
    int sum = 0;
    
    while (left < right) {
        if (nums[mid] == threshold) {
            return mid;
        }
        else if (nums[mid] < threshold) {
            left = mid + 1;
        }
        else {
            right = mid;
        }
        mid = (left + right) / 2;
    }
    
    return mid;
}

int underBound(vector<int>& nums, int threshold) {
    int left = 0, right = nums.size();
    int mid = (left + right) / 2;
    int sum = 0;
    
    while (left < mid) {
        if (nums[mid] == threshold) {
            return mid;
        }
        else if (nums[mid] < threshold) {
            left = mid;
        }
        else {
            right = mid;
        }
        mid = (left + right) / 2;
    }
    
    return mid;
}

vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
    int mask = 0;
    vector<int> ps(1);
    for (char c : s)
        ps.push_back(mask ^= 1 << (c - 'a'));

    vector<bool> r;
    for (auto &q : queries) {
        int odds = __builtin_popcount(ps[q[1] + 1] ^ ps[q[0]]);
        r.push_back(q[2] >= odds / 2);
    }
    return r;
}

int main ()
{
    string w(3, 'w');
    w[2] = -1;
    cout << w << "\n";
    return 0;
}