// https://leetcode.com/problems/maximum-students-taking-exam/
// 

#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <string>

using namespace std;

class Solution {
public:
    int maxStudents(vector<vector<char>>& seats) {
        int m = seats.size();
        int n = seats[0].size();
        vector<int> validity; // the validity of each row in the classroom
        for (int i = 0; i < m; ++i) {
            int cur = 0;
            for (int j = 0; j < n; ++j) {
				// the j-th bit is 1 if and only if the j-th seat is not broken
				// here the 0th bit is the most significant bit
                cur = cur * 2 + (seats[i][j] == '.');
            }
            validity.push_back(cur);
        }
		
		// all the f states are set -1 as invalid states in the beginning
		// here f[i][mask] represents the first i-1 rows to handle corner cases
        vector<vector<int>> f(m + 1, vector<int>(1 << n, -1));
		// f[0][0] is a valid state
		// think of a virtual row in the front and no students are sitting in that row
        f[0][0] = 0;
        for (int i = 1; i <= m; ++i) {
            int valid = validity[i - 1];
			// the interval [0, 1 << n) includes all the n-bit states for a row of students
			// please note that state 0 represents no student sitting in this row
			// which is always a valid state
            for (int j = 0; j < (1 << n); ++j) {
				// (j & valid) == j: check if j is a subset of valid
				// !(j & (j >> 1)): check if there is no adjancent students in the row
                if ((j & valid) == j && !(j & (j >> 1))) {
					// f[i][j] may transit from f[i -1][k]
                    for (int k = 0; k < (1 << n); ++k) {
						// !(j & (k >> 1)): no students in the upper left positions
						// !((j >> 1) & k): no students in the upper right positions
						// f[i - 1][k] != -1: the previous state is valid
                        // k is prev state
                        if (!(j & (k >> 1)) && !((j >> 1) & k) && f[i - 1][k] != -1) {
                            f[i][j] = max(f[i][j], f[i - 1][k] + __builtin_popcount(j));
                        }
                    }
                }
            }
        }
        
		// the answer is the maximum among all f[m][mask]
        return *max_element(f[m].begin(), f[m].end());
    }
};

class Solution2 {
public:
    vector<int>locations;//To store non-broken seats in each row as a bitmask
    int m,n;
    vector<vector<int>>memo;
    int dp(vector<vector<char>>& seats,int height,int prevRowArrangement){
        if(height>=m )return 0;
        if(memo[height][prevRowArrangement]!=-1) return memo[height][prevRowArrangement];

        int ans=0;
        
        for(int i=0; i<(1<<n); ++i){
            if( ( (locations[height]&i)==i) && !(i&(i<<1)) && !(i&(i>>1)) ){
                //Students should sit on non-broken seats and no student should sit adjacent to each other. Refer to the tutorial for more understanding
                if(height>0){
                    if(i & (prevRowArrangement<<1)) continue; //for any student, no other student should sit on NorthEast
                    if(i & (prevRowArrangement>>1)) continue; //for any student, no other student should sit on NorthWest
                }
                ans = max(ans,dp(seats, height+1, i) + __builtin_popcount(i));
            }
        }

        return memo[height][prevRowArrangement]=ans;
    }

    int maxStudents(vector<vector<char>>& seats) {
        m=seats.size();
        if(!m) return 0;
        locations.clear();
        n=seats.front().size();
        for(int i=0;i<m;i++){
            int res=0;
            for(int j=0;j<n;++j){
                res=2*res+(seats[i][j]=='.');
            }
            locations.push_back(res); 
        }
        
        memo.assign(m,vector<int>(1<<n,-1));
        
        return dp(seats,0,0);
    }
};

class Solution3 {
public:
    int maxnum = 0;
    map<string, int> scnt;
    queue<string> q;

    void dfs(string& pre,string& cur, vector<char>& seat, int pos, int cnt) {
        if(pos>=seat.size())
        {
            maxnum = max(maxnum,cnt);
            if(scnt.count(cur) == 0)  q.push(cur);
            scnt[cur] = max(scnt[cur],cnt);
            return;
        }

        if(seat[pos]!='#'&& (pos == 0 || pre[pos-1]!='@') && ((pos == seat.size()-1) || pre[pos+1] != '@'))
        {
            cur[pos]='@';       
            dfs(pre, cur, seat, pos+2, cnt+1); 
        }

        cur[pos]='#';       
        dfs(pre, cur, seat, pos+1, cnt); 
    }
    
    int maxStudents(vector<vector<char>>& seats) {
        int n = seats[0].size();
        string s(n+1, '#');
        
        s[n] = -1;  //row info
        scnt[s] = 0;
        q.push(s);

        while (!q.empty()) {
            auto pre = q.front(); 
            q.pop();

            if(pre[n]==seats.size()-1) 
                break;
            
            string cur = string(n+1,'#');
            cur[n] = pre[n]+1;
            
            dfs(pre, cur, seats[cur[n]], 0, scnt[pre]);
        }

        return maxnum;
    }
};

/*
[["#",".","#","#",".","#"],
 [".","#","#","#","#","."],
 ["#",".","#","#",".","#"]]
*/