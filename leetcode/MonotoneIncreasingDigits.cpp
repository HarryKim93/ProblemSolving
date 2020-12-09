// https://leetcode.com/problems/monotone-increasing-digits/
// O(N * N) 

class Solution {
public:
    bool check(int N) {
        int k = 10;
        int prev = N % k;
        while (N) {
            if (N % 10 > prev) return false;
            prev = N % 10;
            N /= 10;
        }
        
        return true;
    }
    
    int monotoneIncreasingDigits(int N) {
        if (N < 10) return N;
        
        int k = 1, ans = 0, prevNum = 0, num = 0;
        while (N / k >= 10) k *= 10;
        
        prevNum = N / (k * 10);
        while (k) {
            num = (N / k) % 10;
            if (prevNum > num) {
                N -= (num + 1) * k;
                if (N >= 10) {
                    N = (N / k) * k;
                    N += (k - 1);
                }
                break;
            }
            
            k /= 10;
            prevNum = num;
        }
        
        if (check(N)) return N;
        return monotoneIncreasingDigits(N);
    }
};