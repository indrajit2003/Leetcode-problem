class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool>ans;
        int n = candies.size();
        int maxi = candies[0];
        for(int i=0;i<n;i++){
            maxi = max(maxi,candies[i]);
        }
        for(int i=0;i<n;i++){
            if(candies[i]+extraCandies>=maxi)
            ans.push_back(1);
            else 
            ans.push_back(0);
        }
        return ans;
    }
};