class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        vector<int>LDS(n,1);
        vector<int>parent(n,-1);
        vector<int>ans;
        sort(nums.begin(),nums.end());
        int result = 1;
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]%nums[j]==0 and LDS[i]<1+LDS[j]){
                
                      LDS[i] = 1+LDS[j];
                      parent[i] = j;
                
                }
            }
            result = max(result,LDS[i]);
        }
        int index=0;
        for(int i=0;i<n;i++){
            if(result==LDS[i]){
               index=i;
            }
        }
        while(index!=-1){
            ans.push_back(nums[index]);
            index=parent[index];
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};