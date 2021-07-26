class Solution {
public:
    int dp[1001][101][2];
    
    int maxProfit(int k, vector<int>& prices){
        int n = prices.size();
        int ans = 0;
        
        memset(dp, -1, sizeof(dp));
        ans = solve(prices,n,0,k,false);

        return ans;
    }
    
    int solve(vector<int>& prices, int n, int i, int k, bool b){

        if(i==n) return 0;

        if(dp[i][k][b] == -1){
            int ans = solve(prices, n, i+1, k, b);

            if(b){
                ans = max(ans, solve(prices, n, i+1, k, false) + prices[i]);
            }
            else if(k){
                ans = max(ans, solve(prices, n, i+1, k - 1, true) - prices[i]);
            }

            dp[i][k][b] = ans;
        }

        return dp[i][k][b];
    }
};