// O(N * N)

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<double> factorial(m + n - 1, 1);
        
        for (int i = 1; i <= m + n - 2; i++)
            factorial[i] = factorial[i - 1] * i;
        
        return factorial[m + n - 2] / (factorial[m - 1] * factorial[n - 1]);
    }
};

class Solution {
public:
    int uniquePaths(int m, int n) {
        double ans = 1;
        
        for (int i = 1; i < m; i++) {
            ans = ans * (n + i - 1) / i;
        }
        
        return int(ans);
    }
};