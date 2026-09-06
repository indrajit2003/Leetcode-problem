class Solution {
public:
    int countWays(int m,int n,string s,string t,vector<vector<int>>& dp){
        if(n==0) return 1;
        if(m==0)return 0;
        if(dp[m][n]!=-1) return dp[m][n];
        if(s[m-1]==t[n-1]){
            return dp[m][n]= countWays(m-1,n-1,s,t,dp) + countWays(m-1,n,s,t,dp);
        }else{
            return dp[m][n]= countWays(m-1,n,s,t,dp);
        }
    }
    int numDistinct(string s, string t) {
        int m = s.size();
        int n = t.size();
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        return countWays(m,n,s,t,dp);
    }
};