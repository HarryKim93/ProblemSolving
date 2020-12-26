// https://leetcode.com/problems/dot-product-of-two-sparse-vectors/submissions/
// O(N)

#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

class SparseVector {
public:
    vector<int> v, n;
    SparseVector(vector<int> &nums, int i = 0) : n(nums) {
        for_each(begin(n), end(n), [&](int k) { if (k) v.push_back(i); ++i; });
    }
    int dotProduct(SparseVector& vec, vector<int> res = {}) {
        transform(begin(v), end(v), begin(vec.v), end(vec.v), back_inserter(res));
        return accumulate(begin(res), end(res), 0, [&](int s, int i) { return s + n[i] * vec.n[i]; });
    }
};



// Your SparseVector object will be instantiated and called as such:
// SparseVector v1(nums1);
// SparseVector v2(nums2);
// int ans = v1.dotProduct(v2);