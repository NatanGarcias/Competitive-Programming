class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty()) return 0;
        
        int n = prices.size();
        
        int ans = 0;
        int menor = prices[0];
        
        for(int i=1;i<n;i++){
            menor = min(menor,prices[i]);
            
            ans = max(ans, prices[i] - menor);    
        }
        
        return ans;
    }
};