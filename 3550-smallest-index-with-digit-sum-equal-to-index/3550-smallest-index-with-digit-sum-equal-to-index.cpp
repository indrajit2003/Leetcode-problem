class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]<=9 and nums[i]==i){
                return i;
            }
            if(nums[i]>9){
                int sum=0;
                while(nums[i]){
                    int k = nums[i]%10;
                    sum+=k;
                    nums[i]/=10;
                }
                if(sum==i)
                return i;
            }
        }
        return -1;
    }
};