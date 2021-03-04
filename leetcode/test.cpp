#include <algorithm>
#include <vector>
#include <iostream>
#include <string>

using namespace std;

int main() {
    vector<int> vec{1,4,7,9,11};
    // cout << binary_search(vec.begin(), vec.end(), 7);
    auto binary_search = [vec](int start, int end, int value) {
        int left = start, right = end;
        while (left < right) {
            int mid = (left + right) / 2;
            if (vec[mid] == value) {
                return mid;
            } else if (vec[mid] < value) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }

        return -1;
    };

    auto upper_bound = [vec](int start, int end, int value) {
        int left = start, right = end;
        while (left < right) {
            int mid = (left + right) >> 1;
            if (vec[mid] <= value) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }

        return right;
    };

    auto lower_bound = [vec](int start, int end, int value) {
        int left = start, right = end;
        while (left < right) {
            int mid = (left + right) >> 1;
            if (vec[mid] < value) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }

        return left;
    };

    // int n;
    // cin >> n;
    // cout << lower_bound(0, vec.size(), n);

    string s("12345");
    cout << s.substr(0,0);

    return 0;
}