class Solution {
public:
    int maxProfit(int k, vector<int>& prices){
        int n = prices.size();
        int ans = 0;
        
        if(n < 2 || k == 0) return 0;
        
        if(k >= n/2){
            int ans = 0;
        
            for(int i=1;i<n;i++){
                ans += max(0, prices[i] - prices[i-1]);    
            }
            return ans;
        }

        vector<vector<int>> C(n,vector<int> (n,0));
    
        for(int i=0;i<n;i++){
            
            int menor = prices[i];

            for(int j=i+1;j<n;j++){
                menor = min(menor, prices[j]);

                C[i][j] = max( C[i][j-1], prices[j] - menor);
            }
        }

        vector<vector<int>> dp(n,vector<int>(k+1,-1));
        
        ans = calc(C,dp,n,0,k);

        return ans;
    }
    
    int calc(vector<vector<int>> &C, vector<vector<int>> &dp, int n, int i, int j){

        if(!j || i==n-1) return 0;

        if(dp[i][j] == -1){
            int ans = 0;

            for(int l=i+1;l<n;l++){
                ans = max(ans, calc(C,dp,n,l,j-1) + C[i][l]);
            }
            dp[i][j] = ans;
        }
        return dp[i][j];
    }
};