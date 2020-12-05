#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

// O(n * k)

class Solution {
public:
    string longestPalindrome(string s) {
        int oddl, oddr, evenl, evenr;
        int ans = 0;
        int mxl, mxr;

        for (int i = 0; i < s.length(); i++) {
            if (i + 1 < s.length() && s[i] == s[i + 1]) {
                evenl = i;
                evenr = i + 1;
                while (s[evenl] == s[evenr]) {
                    evenl--;
                    evenr++;
                    if (evenl < 0 || evenr >= s.length()) break;
                }
                if (ans < evenr - evenl + 1 - 2) {
                    ans = evenr - evenl + 1 - 2;
                    mxl = evenl + 1, mxr = evenr - 1;
                }
            }

            oddl = oddr = i;
            while (s[oddl] == s[oddr]) {
                oddl--;
                oddr++;
                if (oddl < 0 || oddr >= s.length()) break;
            }

            if (ans < oddr - oddl + 1 - 2) {
                ans = oddr - oddl + 1 - 2;
                mxl = oddl + 1, mxr = oddr - 1;
            }
        }

        return move(s.substr(mxl, mxr - mxl + 1));
    }
};

int main() {
    Solution sol;
    cout << sol.longestPalindrome("a") << "\n";
    return 0;
}