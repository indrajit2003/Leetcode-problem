class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return 1;
        int mini = INT_MAX;
        int maxi = INT_MIN;
        for(int i=0;i<n;i++){
            mini = min(mini,nums[i]);
            maxi = max(maxi,nums[i]);
        }
        int count=0;
        bool flag1=0;
        bool flag2=0;
        for(int i=0;i<n;i++){
            if(nums[i]==mini)
            flag1=1;

            if(nums[i]==maxi)
            flag2=1;

            count++;
            
            if(flag1==1 and flag2==1)
            break;
        }

        int count1=0;
        bool fl1=0;
        bool fl2=0;
        for(int i=n-1;i>=0;i--){
            if(nums[i]==mini)
            fl1=1;

            if(nums[i]==maxi)
            fl2=1;

            count1++;

            if(fl1==1 and fl2==1)
            break;
        }
        int count2=0;
        for(int i=0;i<n;i++){
            if(nums[i]!=mini and nums[i]!=maxi){
                count2++;
            }
            if(nums[i]==mini or nums[i]==maxi){
                count2++;
                break;
            }
        }
        for(int i=n-1;i>=0;i--){
            if(nums[i]!=mini and nums[i]!=maxi){
                count2++;
            }
            if(nums[i]==mini or nums[i]==maxi){
              count2++;
              break;
            }
        }
        int ans = min(count,min(count1,count2));

        return ans;
        
    }
};