class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>mx=nums;
        vector<int>mn=nums;
        for(int i=1;i<n;i++){
            mx[i] = max(nums[i],mx[i-1]);
        }
        for(int i=n-2;i>=0;i--){
            mn[i]=min(nums[i],mn[i+1]);
        }
        for(int i=0;i<n;i++){
            if(mx[i]-mn[i]<=k)
            return i;
        }
        return -1;
        

    }
};