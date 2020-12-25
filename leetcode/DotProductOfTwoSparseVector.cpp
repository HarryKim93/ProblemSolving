// https://leetcode.com/problems/dot-product-of-two-sparse-vectors/submissions/
// O(N)

class SparseVector {
private:
    vector<int> container;
public:
    SparseVector(vector<int> &nums) {
        container = move(nums);
    }
    
    int getValue(int idx) {
        return container[idx];
    }
    
    // Return the dotProduct of two sparse vectors
    int dotProduct(SparseVector& vec) {
        int ans = 0;
        for (int i = 0; i < container.size(); i++) {
            ans += vec.getValue(i) * container[i]; 
        }
        
        return ans;
    }
};

// Your SparseVector object will be instantiated and called as such:
// SparseVector v1(nums1);
// SparseVector v2(nums2);
// int ans = v1.dotProduct(v2);