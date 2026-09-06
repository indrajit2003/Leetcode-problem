class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        vector<int>ans=nums1;
        for(int i=0;i<n;i++){
            ans.push_back(nums2[i]);
        }
        sort(ans.begin(),ans.end());
        int start=0;
        int end = ans.size()-1;
        double k;
        if(ans.size()%2 !=0){
            double mid = start+(end-start)/2;
            return ans[mid];
        }
       int mid = start+(end-start)/2;
       double l = ans[mid]+ans[mid+1];
       k = l/2;
       return k;
    }
};