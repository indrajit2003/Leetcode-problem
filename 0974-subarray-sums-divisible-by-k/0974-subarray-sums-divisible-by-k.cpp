class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int>mp;
        mp[0]=1;
        int prefixSum=0,rem,total=0;
        for(int i=0;i<n;i++){
            prefixSum+=nums[i];
            rem = prefixSum%k;
            if(rem<0)
            rem+=k;
            if(mp.count(rem)){
                total+=mp[rem];
                mp[rem]++;
            }else{
                mp[rem]++;
            }
        }
        return total;
    }
};