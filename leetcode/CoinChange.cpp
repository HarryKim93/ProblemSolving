class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int cache[amount + 1];
        
        sort(coins.begin(), coins.end());

        for (int i = 0; i <= amount; i++) cache[i] = INT_MAX;
        
        cache[0] = 0;
        for (auto coin : coins) {
            if (coin > amount) break;
            cache[coin] = 1;
            for (int i = coin; i <= amount; i++) {
                if (cache[i - coin] != INT_MAX) cache[i] = min(cache[i], cache[i - coin] + cache[coin]);
            }
        }
        
        return cache[amount] == INT_MAX ? -1 : cache[amount];
    }
};