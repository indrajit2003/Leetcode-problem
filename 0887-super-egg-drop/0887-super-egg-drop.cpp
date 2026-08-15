class Solution {
public:
    int findTotalFloor(int eggs,int moves,vector<vector<int>>&dp){
        if(eggs==0 or moves==0) return 0;
        if(eggs==1) return moves;
        if(dp[eggs][moves]!=-1) return dp[eggs][moves];
        return dp[eggs][moves] =  1+findTotalFloor(eggs-1,moves-1,dp)+findTotalFloor(eggs,moves-1,dp);
    }
    int superEggDrop(int k, int n) {
        int moves = 0;
        vector<vector<int>>dp(k+1,vector<int>(n+1,-1));
        while(findTotalFloor(k,moves,dp)<n){
            moves++;
        }
        return moves;
    }
};