class Solution {
public:
    const int mod = 1e9+7;
    int distinctSubseqII(string s) {
        int n=s.size();
        vector<int>dp(n+1);
        vector<int>last(26,-1);
        dp[0]=1;
        for(int i=0;i<n;i++){
            int k = s[i]-'a';
            dp[i+1] = (2*dp[i])%mod;
            if(last[k]>=0){
                dp[i+1] = dp[i+1]-dp[last[k]];
            }
            dp[i+1] = dp[i+1]%mod;
            last[k]=i;
        }
        dp[n]--;
        if(dp[n]<0) 
        dp[n] = dp[n]+mod;
        return dp[n];
    }
};