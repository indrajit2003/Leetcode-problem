class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n = nums1.size();
        if(n==1) return true;
        bool flag=0;
        for(int i=0;i<n;i++){
           if(nums1[i]%2==0)
           flag=1;
        }
        for(int i=0;i<n;i++){
           if(nums1[i]%2!=0)
           flag=1;
        }
        if(flag==1) return true;

        return false;
    }
};