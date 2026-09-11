class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        if(n==0) return 0;
        int count=0;
        int k=0;
        for(int i=0;i<n-1;i++){
            if(nums[i]==nums[i+1]) continue;
            if(nums[i]+1==nums[i+1]) count+=1;
            else{
               k=max(k,count);
               count=0;
            }
        }
        k = max(k, count);
        return k+1;
    }
};