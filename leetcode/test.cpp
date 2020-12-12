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

int main ()
{
    int n;
    vector<int> nums = {0,2,4,6,8,10,12};
    cin >> n;
    cout << upperBound(nums, n);

    return 0;
}