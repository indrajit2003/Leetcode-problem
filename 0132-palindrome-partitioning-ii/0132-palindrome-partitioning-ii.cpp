class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        if(n==1) return 0;
        vector<vector<int>>palindrome(n,vector<int>(n,0));
        for(int i=0;i<n;i++){
            palindrome[i][i]=1;
        }
        //this code is for substring palindrome hain ki nhi 
        for(int leng=2;leng<=n;leng++){
            for(int i=0;i<=n-leng;i++){
                int j = i+leng-1;
                if(s[i]==s[j] and (leng==2 or palindrome[i+1][j-1])){
                    palindrome[i][j]=1;
                }
                
            }
        }
        vector<int>dp(n,INT_MAX);
        dp[n-1]=0;
        for(int i=n-2;i>=0;i--){
            for(int j=i;j<n;j++){
                if(palindrome[i][j]){
                    if(j==n-1)
                    dp[i]=0;
                    else
                    dp[i] = min(dp[i] , 1+dp[j+1]);
                }
            }
        }
        return dp[0];
    } 
};