#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void quickSort(int low, int high, vector<int>& vec) {
    if (low == high) return ;
    int left = low + 1, right = high - 1;
    int mid = low;

    swap(vec[mid], vec[(low + high) / 2]);

    while (left <= right) {
        while (left <= right && vec[left] <= vec[mid]) left++;
        while (left <= right && vec[mid] <= vec[right]) right--;

        if (left <= right) swap(vec[left], vec[right]); 
    }

    swap(vec[mid], vec[right]);
    quickSort(low, right, vec);
    quickSort(right + 1, high, vec);
}

int main() {
    vector<int> vec{6, 5, 4, 3, 2, 1, 0};
    quickSort(0, vec.size(), vec);

    for (int i = 0; i < vec.size(); i++) cout << vec[i] << " ";

    return 0;
}