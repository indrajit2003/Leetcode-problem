class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int>LIS(n,1);
        vector<int>count(n,1);
        int maxlength=1;
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[j]<nums[i]){
                    if(LIS[i]<1+LIS[j]){
                        LIS[i] = 1+LIS[j];
                        count[i] = count[j];
                    }else if(LIS[i]==1+LIS[j]){
                        count[i]+=count[j];
                    }
                }
            }
            maxlength = max(maxlength,LIS[i]);
        }
        int res =0;
        for(int i=0;i<n;i++){
            if(maxlength==LIS[i])
            res+=count[i];
        }
        return res;
    }
};