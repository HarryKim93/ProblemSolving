def canMakePaliQueries(s, queries):
    N = 26
    a = ord('a')
    dp = [[0] * N]

    for i in range(1, len(s)+1):
            new = dp[i-1][:]
            j = ord(s[i-1]) - a
            new[j] += 1
            dp.append(new)
    
    ans = []
    for l, r, k in queries:
            L = dp[l]
            R = dp[r+1]
            ans.append(sum((R[i] - L[i]) & 1 for i in range(N)) // 2 <= k)

    return ans

def canMakePaliQueries(s, queries):
    N = 26
    S = len(s) + 1
    ints = list(map(lambda c: ord(c) - ord('a'), s))

    dp = [0] * S
    for i in range(1, S):
        dp[i] = dp[i-1] ^ (1 << ints[i-1])

    ones = lambda x: bin(x).count('1')
    return [
        ones(dp[r+1] ^ dp[l]) >> 1 <= k
        for l, r, k in queries
    ]